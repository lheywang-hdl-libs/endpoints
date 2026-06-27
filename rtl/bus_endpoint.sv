/**
 * @file    bus_endpoint.sv
 * @brief   Define the master endpoint to be used.
 *
 * @details This top level mutualize a single endpoint bus to make the axi routing "simple".
 *          The required submodules are then added within that global cell to customize the register file.
 *
 * @author  l.heywang <leonard.heywang@proton.me>
 * @date    27/06/2026
 *
 * @copyright l.heywang, MIT License.
 */

package bus_endpoint;

    /**
     * Define the cell type to be used.
     */
    typedef enum logic [2 : 0] {
        TYPE_REG_IN,
        TYPE_REG_OUT,
        TYPE_FIFO_IN,
        TYPE_FIFO_OUT,
        TYPE_SRAM_IN,
        TYPE_SRAM_OUT,
        TYPE_IRQ
    } cell_type_t;

    /*
     * Structure to be passed to configure the register.
     */
    typedef struct packed {
        cell_type_t cell_type;      // The cell type.
        logic [31 : 0] offset;      // The offset at which it's placed.
        logic [31 : 0] size;        // Reserve memory space.
        logic [31 : 0] mem_size;    // Configure the FIFO or the SRAM size;
    } cell_config_t;

endpackage: bus_endpoint

