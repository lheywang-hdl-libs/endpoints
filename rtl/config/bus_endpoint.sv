/**
 * @file    bus_endpoint_pkg.sv
 * @brief   Define different endpoints types that may be used (SRAM, FIFO, REGISTERS, MULTIREGISTERS, IRQ).
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
    typedef enum int {
        TYPE_REG_IN,
        TYPE_REG_OUT,
        TYPE_FIFO_IN,
        TYPE_FIFO_OUT,
        TYPE_SRAM_IN,
        TYPE_SRAM_OUT,
        TYPE_IRQ
    } cell_type_t;

    /**
     * Structure to pass to configure a register bitfield
     */
    typedef struct {
        int bit_offset; // Offset position.
        int bit_width;  // Width of the passed field.
    } field_config_t;

    /*
     * Structure to be passed to configure the register.
     *
     * Quick note about [] arrays --> Shall be supported, if not, use a default value.
     * The code will check that it's valid anyway, so excepted some CPU cycles and a bit or RAM,
     * nothing bad will happen.
     *
     * Another point : cell_config will be used to define the effective data bus width.
     * Therefore, a bus requested for 32 bits may only be 11 bits after configuration.
     */
    typedef struct {
        cell_type_t cell_type;          // The cell type.
        int offset;                     // The offset at which it's placed.
        int size;                       // Reserve memory space.
        int mem_size;                   // Configure the FIFO or the SRAM size;
        field_config_t cell_config[];   // Store the bitfield config for the registers.
    } cell_config_t;

    /**
     * Define the cell connectivity type
     */
    typedef enum int {
        BUS_AVALON,
        BUS_AXI_LITE,
        BUS_AXI
    } cell_bus_t;

    /**
     * Define an endpoint configuration.
     */
    typedef struct {
        cell_bus_t  bus;
        logic       burst;
        logic       atomic;
        int         data_width;
        int         addr_width;
    } endpoint_config_t;

endpackage: bus_endpoint
