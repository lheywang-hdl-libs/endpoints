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
        bus:            bus_endpoint::BUS_AXI_LITE,
        burst:          0,
        atomic:         0,
        data_width:     32,
        addr_width:     32,
        prefix_size:    20,
        suffix_size:    12
    },
    parameter int BASE_ADDRESS = 32'h20000002
) (
    input   logic                                                   clk,
    input   logic                                                   rst_n,
    input   logic [MODULE_CONFIG.addr_width -1 : 0]                 input_address,
    input   logic                                                   addr_valid,
    output  logic                                                   match,
    output  logic [max($size(CELL_CONFIG[0].cell_config), 1) : 0 ]  enables
);

    /*
     * Validating the design parameters
     */
    generate
        if ((BASE_ADDRESS & 32'h3) != 0) begin: is_address_aligned
            $fatal(1024, "Base address is not aligned with a 4 byte boundary.");
        end

        if ((MODULE_CONFIG.prefix_size + MODULE_CONFIG.suffix_size) != MODULE_CONFIG.addr_width) begin: is_address_configured
            $fatal(1025, "Sum of prefix and suffix of the address does not match the address size.");
        end
    endgenerate

    genvar index;
    generate for (index = 0; index < $size(CELL_CONFIG); index++) begin

        localparam int CURRENT_ADDR = (CELL_CONFIG[index].offset & 32'h3);

            if (CURRENT_ADDR != 0) begin: is_offset_aligned
                $fatal(1026, "Cell config at index 0x%0h is not aligned with a 4 byte boundary.", index);
        end
    end
    endgenerate
   

    

endmodule: address_decoder
