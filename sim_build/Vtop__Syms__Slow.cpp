// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup top module instance
    , TOP{this, namep}
{
    // Check resources
    Verilated::stackCheck(250);
    // Setup sub module instances
    TOP__bus_endpoint.ctor(this, "bus_endpoint");
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__PVT__bus_endpoint = &TOP__bus_endpoint;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__bus_endpoint.__Vconfigure(true);
    // Setup scopes
    __Vscopep_TOP = new VerilatedScope{this, "TOP", "TOP", "<null>", 0, VerilatedScope::SCOPE_OTHER};
    __Vscopep_address_decoder = new VerilatedScope{this, "address_decoder", "address_decoder", "address_decoder", -12, VerilatedScope::SCOPE_MODULE};
    __Vscopep_bus_endpoint = new VerilatedScope{this, "bus_endpoint", "bus_endpoint", "bus_endpoint", -12, VerilatedScope::SCOPE_PACKAGE};
    // Set up scope hierarchy
    __Vhier.add(0, __Vscopep_address_decoder);
    __Vhier.add(0, __Vscopep_bus_endpoint);
    // Setup export functions - final: 0
    // Setup export functions - final: 1
    // Setup public variables
    __Vscopep_TOP->varInsert("addr_valid", &(TOP.addr_valid), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("clk", &(TOP.clk), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("enables", &(TOP.enables), false, VLVT_UINT64, VLVD_OUT|VLVF_PUB_RW, 0, 1 ,32,0);
    __Vscopep_TOP->varInsert("input_address", &(TOP.input_address), false, VLVT_UINT32, VLVD_IN|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_TOP->varInsert("match", &(TOP.match), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("rst_n", &(TOP.rst_n), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_address_decoder->varInsert("BASE_ADDRESS", const_cast<void*>(static_cast<const void*>(&(TOP.address_decoder__DOT__BASE_ADDRESS))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_address_decoder->varInsert("CELL_CONFIG", const_cast<void*>(static_cast<const void*>(&(TOP.address_decoder__DOT__CELL_CONFIG))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_address_decoder->varInsert("MODULE_CONFIG", const_cast<void*>(static_cast<const void*>(&(TOP.address_decoder__DOT__MODULE_CONFIG))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_address_decoder->varInsert("addr_valid", &(TOP.address_decoder__DOT__addr_valid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_address_decoder->varInsert("clk", &(TOP.address_decoder__DOT__clk), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_address_decoder->varInsert("enables", &(TOP.address_decoder__DOT__enables), false, VLVT_UINT64, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,32,0);
    __Vscopep_address_decoder->varInsert("input_address", &(TOP.address_decoder__DOT__input_address), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_address_decoder->varInsert("match", &(TOP.address_decoder__DOT__match), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_address_decoder->varInsert("rst_n", &(TOP.address_decoder__DOT__rst_n), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_bus_endpoint->varInsert("DEFAULT_REG_COUNT", const_cast<void*>(static_cast<const void*>(&(TOP__bus_endpoint.DEFAULT_REG_COUNT))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_SIGNED, 0, 1 ,31,0);
}

Vtop__Syms::~Vtop__Syms() {
    // Tear down scope hierarchy
    __Vhier.remove(0, __Vscopep_address_decoder);
    __Vhier.remove(0, __Vscopep_bus_endpoint);
    // Clear keys from hierarchy map after values have been removed
    __Vhier.clear();
    // Tear down scopes
    VL_DO_CLEAR(delete __Vscopep_TOP, __Vscopep_TOP = nullptr);
    VL_DO_CLEAR(delete __Vscopep_address_decoder, __Vscopep_address_decoder = nullptr);
    VL_DO_CLEAR(delete __Vscopep_bus_endpoint, __Vscopep_bus_endpoint = nullptr);
    // Tear down sub module instances
    TOP__bus_endpoint.dtor();
}
