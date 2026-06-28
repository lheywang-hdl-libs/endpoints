# tb/test_address_decoder.py
import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, Timer


@cocotb.test()
async def test_address_decoding_logic(dut):
    """Check the comb logic."""

    error = 0

    # 1. Initialisation de l'horloge système (100 MHz -> 10 ns)
    clock = Clock(dut.clk, 5, unit="ns")
    cocotb.start_soon(clock.start())

    # 2. Séquence de réinitialisation asynchrone sécurisée
    dut.rst_n.value = 0
    dut.input_address.value = 0
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)
    dut.rst_n.value = 1
    await RisingEdge(dut.clk)

    assert int(dut.match.value) & 0x01 == 0

    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)

    dut.input_address.value = 0x20000000

    await RisingEdge(dut.clk)

    assert int(dut.match.value) & 0x01 == 1
