// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_BUS_ENDPOINT_H_
#define VERILATED_VTOP_BUS_ENDPOINT_H_  // guard

#include "verilated.h"
#include "Vtop_bus_endpoint.h"


class Vtop__Syms;
struct Vtop_field_config_t__struct__0 {
    IData/*31:0*/ __PVT__bit_offset;
    IData/*31:0*/ __PVT__bit_width;

    bool operator==(const Vtop_field_config_t__struct__0& rhs) const {
        return __PVT__bit_offset == rhs.__PVT__bit_offset
            && __PVT__bit_width == rhs.__PVT__bit_width;
    }
    bool operator!=(const Vtop_field_config_t__struct__0& rhs) const {
        return !(*this == rhs);
    }

    bool operator<(const Vtop_field_config_t__struct__0& rhs) const {
        return std::tie(__PVT__bit_offset, __PVT__bit_width)
            <  std::tie(rhs.__PVT__bit_offset, rhs.__PVT__bit_width);
    }
};
template <>
struct VlIsCustomStruct<Vtop_field_config_t__struct__0> : public std::true_type {};

struct Vtop_cell_config_t__struct__0 {
    IData/*31:0*/ __PVT__cell_type;
    IData/*31:0*/ __PVT__offset;
    IData/*31:0*/ __PVT__size;
    IData/*31:0*/ __PVT__mem_size;
    VlUnpacked<Vtop_field_config_t__struct__0, 32> __PVT__cell_config;

    bool operator==(const Vtop_cell_config_t__struct__0& rhs) const {
        return __PVT__cell_type == rhs.__PVT__cell_type
            && __PVT__offset == rhs.__PVT__offset
            && __PVT__size == rhs.__PVT__size
            && __PVT__mem_size == rhs.__PVT__mem_size
            && __PVT__cell_config == rhs.__PVT__cell_config;
    }
    bool operator!=(const Vtop_cell_config_t__struct__0& rhs) const {
        return !(*this == rhs);
    }

    bool operator<(const Vtop_cell_config_t__struct__0& rhs) const {
        return std::tie(__PVT__cell_type, __PVT__offset, __PVT__size, __PVT__mem_size, __PVT__cell_config)
            <  std::tie(rhs.__PVT__cell_type, rhs.__PVT__offset, rhs.__PVT__size, rhs.__PVT__mem_size, rhs.__PVT__cell_config);
    }
};
template <>
struct VlIsCustomStruct<Vtop_cell_config_t__struct__0> : public std::true_type {};
struct Vtop_endpoint_config_t__struct__0 {
    IData/*31:0*/ __PVT__bus;
    CData/*0:0*/ __PVT__burst;
    CData/*0:0*/ __PVT__atomic;
    IData/*31:0*/ __PVT__data_width;
    IData/*31:0*/ __PVT__addr_width;
    IData/*31:0*/ __PVT__prefix_size;
    IData/*31:0*/ __PVT__suffix_size;

    bool operator==(const Vtop_endpoint_config_t__struct__0& rhs) const {
        return __PVT__bus == rhs.__PVT__bus
            && __PVT__burst == rhs.__PVT__burst
            && __PVT__atomic == rhs.__PVT__atomic
            && __PVT__data_width == rhs.__PVT__data_width
            && __PVT__addr_width == rhs.__PVT__addr_width
            && __PVT__prefix_size == rhs.__PVT__prefix_size
            && __PVT__suffix_size == rhs.__PVT__suffix_size;
    }
    bool operator!=(const Vtop_endpoint_config_t__struct__0& rhs) const {
        return !(*this == rhs);
    }

    bool operator<(const Vtop_endpoint_config_t__struct__0& rhs) const {
        return std::tie(__PVT__bus, __PVT__burst, __PVT__atomic, __PVT__data_width, __PVT__addr_width, __PVT__prefix_size, __PVT__suffix_size)
            <  std::tie(rhs.__PVT__bus, rhs.__PVT__burst, rhs.__PVT__atomic, rhs.__PVT__data_width, rhs.__PVT__addr_width, rhs.__PVT__prefix_size, rhs.__PVT__suffix_size);
    }
};
template <>
struct VlIsCustomStruct<Vtop_endpoint_config_t__struct__0> : public std::true_type {};

class alignas(VL_CACHE_LINE_BYTES) Vtop_bus_endpoint final {
  public:

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;

    // PARAMETERS
    static constexpr IData/*31:0*/ DEFAULT_REG_COUNT = 0x00000040U;

    // CONSTRUCTORS
    Vtop_bus_endpoint();
    ~Vtop_bus_endpoint();
    void ctor(Vtop__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vtop_bus_endpoint);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const Vtop_field_config_t__struct__0& obj);
std::string VL_TO_STRING(const Vtop_cell_config_t__struct__0& obj);
std::string VL_TO_STRING(const Vtop_endpoint_config_t__struct__0& obj);

#endif  // guard
