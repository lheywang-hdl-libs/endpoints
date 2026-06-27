/**
 * @file    bus_endpoint.sv
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