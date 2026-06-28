import os
from pathlib import Path
from cocotb_tools.runner import get_runner


def test_generic_cell_runner():
    hdl_toplevel_lang = "verilog"
    sim = "verilator"

    proj_path = Path(__file__).resolve().parent.parent
    proj_path = proj_path / "rtl"

    # Set sources
    sources = [
        proj_path / "config/bus_endpoint.sv",
        proj_path / "config/cell_interface.sv",
        proj_path / "modules/cells/fifo_in.sv",
        proj_path / "modules/cells/fifo_out.sv",
        proj_path / "modules/cells/register_in.sv",
        proj_path / "modules/cells/register_out.sv",
        proj_path / "modules/cells/sram_in.sv",
        proj_path / "modules/cells/sram_out.sv",
        proj_path / "modules/address_decoder.sv",
    ]

    # Configure the simulator
    runner = get_runner(sim)
    runner.build(
        sources=sources,
        hdl_toplevel="address_decoder",
        always=True,
        build_args=["-Wall", "-Wno-fatal", "--trace", "--debug"],
    )

    # 3. Lancement du test Python
    runner.test(
        hdl_toplevel="address_decoder",
        test_module="testbench.tb_address_decoder",
    )


if __name__ == "__main__":
    test_generic_cell_runner()
