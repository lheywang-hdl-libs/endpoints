/**
 * @file    cell_interface.sv
 * @brief   Define the standard cell interface between the FSM and the cell
 *
 * @author  l.heywang <leonard.heywang@proton.me>
 * @date    27/06/2026
 *
 * @copyright l.heywang, MIT License.
 */

interface cell_interface #(
    parameter int DATA_WIDTH = 32,
    parameter int ADDR_WIDTH = 32
);

    // =========================================================================
    // FSM -> CELLS
    // =========================================================================
    logic [ADDR_WIDTH - 1 : 0]          addr;
    logic [DATA_WIDTH - 1 : 0]          wdata;
    logic [(DATA_WIDTH / 8) - 1 : 0]    wstrb;
    logic [5:0]                         atop;

    logic                               req_write;
    logic                               req_read;

    // =========================================================================
    // CELLS -> FSM
    // =========================================================================
    logic                               ready;
    logic [DATA_WIDTH - 1 : 0]          rdata;
    logic                               error;

    
    // =========================================================================
    // MODPORT FSM
    // =========================================================================
    modport fsm (
        output addr,
        output wdata,
        output wstrb,
        output atop,
        output req_write,
        output req_read,
        input  ready,
        input  rdata,
        input  error
    );

    // =========================================================================
    // MODPORT CELLS
    // =========================================================================
    modport cells (
        input  addr,
        input  wdata,
        input  wstrb,
        input  atop,
        input  req_write,
        input  req_read,
        output ready,
        output rdata,
        output error
    );

endinterface: cell_interface
