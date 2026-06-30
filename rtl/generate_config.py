# ==============================================================================
# file:     generate_config.py
# bried:    Generate the SystemVerilog config to assemble the requested system.
#           Use a passed .yaml config file and produce multiple outputs :
#           - A generate_instances.svh, to be included in the top level file
#           - A config.json5, to render the config as a Wavedrom register
#           - A log.txt file.
#
# author:   l.heywang <leonard.heywang@proton.me>
# date :    30/06/2026
#
# copyright: MIT
#
# ==============================================================================

# ==================================
# IMPORTS
# ==================================

import argparse
import yaml

from datetime import datetime
from pathlib import Path
from dataclasses import dataclass

# ==================================
# TYPES
# ==================================


@dataclass
class Bitfield:
    """
    Define a single bitfield element to be loaded
    """

    name: str
    offset: int
    width: int


@dataclass
class Cell:
    """
    Define a Cell config
    """

    # Public members
    name: str
    type: str
    offset: int
    size: int
    mem_size: int
    bitfield: list[Bitfield]

    # Private members
    _cell_name: str


@dataclass
class Endpoint:
    """
    Store the endpoint config to be passed.
    """

    bus: str
    burst: bool
    atomic: bool
    data_width: int
    addr_width: int
    prefix_size: int
    suffix_size: int

    address: int


# ==================================
# HELPERS
# ==================================


def log(header: str, message: str):
    """
    A small helper to print to both console and file.
    """

    string = f"[ {header:8} ] {datetime.now()} - {message}"

    with open("log.txt", "a+") as f:
        f.write(string)
        f.write("\n")

    color = "\033[0m"
    if header == "INFO":
        color = "\033[94m"
    elif header == "WARNING":
        color = "\033[93m"
    elif header == "ERROR":
        color = "\033[91m"

    print(color + string + "\033[0m")


# ==================================
# FUNCTIONS
# ==================================

# ----------------------------------
# LOADING
# ----------------------------------


def load_config(path: Path) -> tuple[Endpoint, list[Cell]]:

    # First, load the YAML config
    with open(path, "r") as f:
        config = yaml.safe_load(f)

    # First, try to load the endpoint config
    endpoint_cfg = Endpoint("", False, False, 0, 0, 0, 0, 0)

    try:

        log("INFO", f"Loading endpoint config for {config["endpoint"].get("name", "")}")

        # Load the bus :
        endpoint_cfg.bus = str(config["endpoint"].get("bus", "AXI-Lite"))

        # Load the options :
        endpoint_cfg.burst = bool(config["endpoint"].get("enable_burst", False))
        endpoint_cfg.atomic = bool(config["endpoint"].get("enable_atomic", False))

        # Load the address parameters
        endpoint_cfg.data_width = int(config["endpoint"].get("data_size", 32))
        endpoint_cfg.addr_width = int(config["endpoint"].get("addr_size", 32))
        endpoint_cfg.prefix_size = int(config["endpoint"].get("prefix_size", 16))
        endpoint_cfg.suffix_size = int(config["endpoint"].get("suffix_size", 16))

        # Load the base address
        endpoint_cfg.address = int(config["endpoint"].get("base_address", 0x20000000))

    except Exception as e:
        log("ERROR", f"Could not load the endpoint config from {Path} : {e}")

    log("INFO", "Finished the endpoint.")

    # Then, load the cells config
    cells: list[Cell] = []

    for index, cell_config in enumerate(config["cells"]):
        try:

            cell_cfg = Cell("", "", 0, 0, 0, [], "")

            # Load the name
            cell_cfg.name = f"{cell_config.get("name", "Default")}"
            log("INFO", f"Loading the cell config for {cell_cfg.name}")

            # Load the type
            type = str(cell_config.get("type", "register")).upper()
            direction = str(cell_config.get("direction", "inpu")).upper()
            cell_cfg.type = f"{type}_{direction}"

            # Load the parameters
            cell_cfg.offset = int(cell_config.get("offset", 0))
            cell_cfg.size = int(cell_config.get("size", 32))
            cell_cfg.mem_size = int(cell_config.get("mem_size", 0))

            # Load the bitfield config
            if cell_cfg.type in ["REGISTER_INPUT", "REGISTER_OUTPUT", "IRQ"]:
                log("INFO", "Loading the required bitfields")

                for bitfield in cell_config["bitfields"]:

                    bitfield_cfg = Bitfield("", 0, 0)

                    # Loading parameters
                    bitfield_cfg.name = str(bitfield.get("name", "Default"))
                    bitfield_cfg.offset = int(bitfield.get("offset", 0))
                    bitfield_cfg.width = int(bitfield.get("width", 32))

                    cell_cfg.bitfield.append(bitfield_cfg)

            cells.append(cell_cfg)

        except Exception as e:
            log(
                "ERROR",
                f"Could not load cell at index {index} with the following error : {e}",
            )

        log("INFO", "Loaded cell.")

    return endpoint_cfg, cells


# ----------------------------------
# VALIDATION
# ----------------------------------


def validate_endpoint(endpoint) -> bool:

    # First, check that the endpoint does match a known cell :
    valid_bus = ["AVALON", "AXI", "AXI-LITE"]

    if endpoint.bus.upper() not in valid_bus:
        log(
            "ERROR",
            "The cell bus is unknown. Please ensure it match one of the following : ",
        )
        for valid in valid_bus:
            log("", valid)

        return False

    # Then, checking the bus features
    if endpoint.bus.upper() == "AXI-LITE":
        if endpoint.burst == True:
            endpoint.burst = False
            log(
                "WARNING",
                "Disabled burst feature as the AXI-Lite bus does not support this feature.",
            )

    if endpoint.bus.upper() != "AXI":
        if endpoint.atomic == True:
            endpoint.atomic = False
            log(
                "WARNING",
                "Disabled atomic modification feature as this is only supported for the AXI bus.",
            )

    # Checking the memory alignement
    if endpoint.address & 0x3 != 0:
        log("ERROR", "Endpoint is not aligned on a 4 byte boundary.")
        return False

    # Checking the address decoder generation:
    if (endpoint.prefix_size + endpoint.suffix_size) != endpoint.addr_width:
        log(
            "ERROR",
            "Address split is not correctly done. Addr prefix + suffix may be equal to the size.",
        )
        log(
            "ERROR",
            f"Here, {endpoint.prefix_size} + {endpoint.suffix_size} = {endpoint.prefix_size + endpoint.suffix_size} != {endpoint.addr_width}",
        )
        return False

    # Checking that the address is a power of 2 :
    aw = endpoint.addr_width
    if aw <= 0 or (aw & (aw - 1)) != 0:
        log(
            "ERROR", "Address size is not a power of two. System won't be usable after."
        )
        return False

    dw = endpoint.data_width
    if dw <= 0 or (dw & (dw - 1)) != 0:
        log("ERROR", "Data size is not a power of two. System won't be usable after.")
        return False

    return True


def validate_cell(cell) -> bool:

    valid_type = [
        "REGISTER_INPUT",
        "REGISTER_OUTPUT",
        "FIFO_INPUT",
        "FIFO_OUTPUT",
        "SRAM_INPUT",
        "SRAM_OUTPUT",
        "IRQ",
    ]

    return True


# ----------------------------------
# GENERATION
# ----------------------------------


def generate_instances(cells: list[Cell]) -> bool:
    return True


# ==================================
# MAIN
# ==================================
if __name__ == "__main__":

    # Add the arguments
    parser = argparse.ArgumentParser(
        prog="Endpoint config generator tool.",
        usage="Pass the YAML configuration file, and see the results !",
        description="Parse the config, load the different registers and build the right assignements for you.",
    )

    parser.add_argument("config", help="The config file that must be loaded")
    parser.add_argument(
        "--validate", action="store_true", help="Only perform the config validation."
    )

    args = parser.parse_args()

    # Load the config
    log("INFO", "Starting the config loading...")
    endpoint, cells = load_config(args.config)
    log("", "")

    # Validating the config
    log("INFO", "Starting the config validation...")
    result = True
    result &= validate_endpoint(endpoint)

    for cell in cells:
        result &= validate_cell(cell)

    if args.validate == True:
        log("INFO", "File generation was not requested. Ending operation here.")
        exit(0)

    if result == False:
        log("ERROR", "The config was not correct. Aborting.")
        exit(1)

    log("INFO", "The config was validated.")
    log("INFO", "Starting file generation.")
    log("", "")

    # Export the results
