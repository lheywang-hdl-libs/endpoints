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
    // COMMANDS
    // =========================================================================
    logic [5:0]                         atop;
    logic                               request;
    logic                               done;
    logic                               error;

    // =========================================================================
    // DATA BUS
    // =========================================================================
    logic [ADDR_WIDTH - 1 : 0]          addr;
    logic [DATA_WIDTH - 1 : 0]          data;
    logic [(DATA_WIDTH / 8) - 1 : 0]    byteen;


    // =========================================================================
    // MODPORT FSM
    // =========================================================================
    modport fsm_in (
        output  atop,
        output  request,
        output  addr,
        input   data,
        output  byteen,
        input   done,
        input   error
    );

    modport fsm_out (
        output  atop,
        output  request,
        output  addr,
        output  data,
        output  byteen,
        input   done,
        input   error
    );

    // =========================================================================
    // MODPORT CELLS
    // =========================================================================
    modport cells_in (
        input   atop,
        input   request,
        input   addr,
        output  data,
        input   byteen,
        output  done,
        output  error
    );

    modport cells_out (
        input   atop,
        input   request,
        input   addr,
        input   data,
        input   byteen,
        output  done,
        output  error
    );

endinterface: cell_interface
