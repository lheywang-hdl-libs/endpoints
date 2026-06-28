/**
 * @file    address_decoder.sv
 * @brief   Main address decoder, to be configured by the HW.
 *
 * @author  l.heywang <leonard.heywang@proton.me>
 * @date    28/06/2026
 *
 * @copyright l.heywang, MIT License.
 */

// Loading the package structs
import bus_endpoint::cell_config_t;
import bus_endpoint::endpoint_config_t;
import bus_endpoint::cell_bus_t;

// Define the max function
let max(a,b) = (a > b) ? a : b;

module address_decoder #(
    parameter cell_config_t CELL_CONFIG[bus_endpoint::DEFAULT_REG_COUNT] = '{
        default: '{
            cell_type:      bus_endpoint::TYPE_REG_OUT,
            offset:         0,
            size:           4,
            mem_size:       0,
            cell_config: '{
                0: '{
                    bit_offset: 0,
                    bit_width:  32
                },
                default: '{
                    bit_offset: 0,
                    bit_width:  0
                }
            }
        }
    },
    parameter endpoint_config_t MODULE_CONFIG = '{
        bus:        bus_endpoint::BUS_AXI_LITE,
        burst:      0,
        atomic:     0,
        data_width: 32,
        addr_width: 32
    },
    parameter int BASE_ADDRESS = 32'h20000000
) (
    input   logic                                                   clk,
    input   logic                                                   rst_n,
    input   logic [MODULE_CONFIG.addr_width -1 : 0]                 input_address,
    input   logic                                                   addr_valid,
    output  logic                                                   match,
    output  logic [max($size(CELL_CONFIG[0].cell_config), 1) : 0 ]    enables
);

    always_ff @(posedge clk or negedge rst_n) begin

        if (input_address == BASE_ADDRESS) begin
            match <= 1'b1;
        end else begin
            match <= 1'b0;
        end

    end

endmodule: address_decoder
