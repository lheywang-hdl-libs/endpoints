// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"
#include "Vtop_bus_endpoint.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final {
  public:
    // CELLS
    Vtop_bus_endpoint* __PVT__bus_endpoint;

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    VL_IN8(addr_valid,0,0);
    VL_OUT8(match,0,0);
    CData/*0:0*/ address_decoder__DOT__clk;
    CData/*0:0*/ address_decoder__DOT__rst_n;
    CData/*0:0*/ address_decoder__DOT__addr_valid;
    CData/*0:0*/ address_decoder__DOT__match;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VstlPhaseResult;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __VicoPhaseResult;
    CData/*0:0*/ __Vtrigprevexpr___TOP__address_decoder__DOT__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__address_decoder__DOT__rst_n__0;
    CData/*0:0*/ __VactPhaseResult;
    CData/*0:0*/ __VnbaPhaseResult;
    VL_IN(input_address,31,0);
    IData/*31:0*/ address_decoder__DOT__input_address;
    IData/*31:0*/ __VactIterCount;
    VL_OUT64(enables,32,0);
    QData/*32:0*/ address_decoder__DOT__enables;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;

    // PARAMETERS
    static constexpr IData/*31:0*/ address_decoder__DOT__BASE_ADDRESS = 0x20000000U;
    static const Vtop_endpoint_config_t__struct__0 address_decoder__DOT__MODULE_CONFIG;
    static const VlUnpacked<Vtop_cell_config_t__struct__0, 64> address_decoder__DOT__CELL_CONFIG;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* namep);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
