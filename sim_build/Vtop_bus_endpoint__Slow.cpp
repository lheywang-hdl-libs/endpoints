// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

// Parameter definitions for Vtop_bus_endpoint
constexpr IData/*31:0*/ Vtop_bus_endpoint::DEFAULT_REG_COUNT;


void Vtop_bus_endpoint___ctor_var_reset(Vtop_bus_endpoint* vlSelf);

Vtop_bus_endpoint::Vtop_bus_endpoint() = default;
Vtop_bus_endpoint::~Vtop_bus_endpoint() = default;

void Vtop_bus_endpoint::ctor(Vtop__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
    Vtop_bus_endpoint___ctor_var_reset(this);
}

void Vtop_bus_endpoint::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

void Vtop_bus_endpoint::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
