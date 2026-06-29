// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

std::string VL_TO_STRING(const Vtop_field_config_t__struct__0& obj) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_bus_endpoint::VL_TO_STRING\n"); );
    // Body
    std::string out;
    out += "'{bit_offset:" + VL_TO_STRING(obj.__PVT__bit_offset);
    out += ", bit_width:" + VL_TO_STRING(obj.__PVT__bit_width);
    out += "}";
    return (out);
}

std::string VL_TO_STRING(const Vtop_cell_config_t__struct__0& obj) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_bus_endpoint::VL_TO_STRING\n"); );
    // Body
    std::string out;
    out += "'{cell_type:" + VL_TO_STRING(obj.__PVT__cell_type);
    out += ", offset:" + VL_TO_STRING(obj.__PVT__offset);
    out += ", size:" + VL_TO_STRING(obj.__PVT__size);
    out += ", mem_size:" + VL_TO_STRING(obj.__PVT__mem_size);
    out += ", cell_config:" + VL_TO_STRING(obj.__PVT__cell_config);
    out += "}";
    return (out);
}

std::string VL_TO_STRING(const Vtop_endpoint_config_t__struct__0& obj) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_bus_endpoint::VL_TO_STRING\n"); );
    // Body
    std::string out;
    out += "'{bus:" + VL_TO_STRING(obj.__PVT__bus);
    out += ", burst:" + VL_TO_STRING(obj.__PVT__burst);
    out += ", atomic:" + VL_TO_STRING(obj.__PVT__atomic);
    out += ", data_width:" + VL_TO_STRING(obj.__PVT__data_width);
    out += ", addr_width:" + VL_TO_STRING(obj.__PVT__addr_width);
    out += ", prefix_size:" + VL_TO_STRING(obj.__PVT__prefix_size);
    out += ", suffix_size:" + VL_TO_STRING(obj.__PVT__suffix_size);
    out += "}";
    return (out);
}
