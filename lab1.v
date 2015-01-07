module lab1(
	CLOCK_50,
	
	
	HEX0,
	HEX1,
	HEX2,
	HEX3,
	HEX4,
	HEX5,

	KEY,
	
	LEDR,
	
	
	SW,
	
	HPS_DDR3_ADDR,
	HPS_DDR3_BA,
	HPS_DDR3_CAS_N,
	HPS_DDR3_CKE,
	HPS_DDR3_CK_N,
	HPS_DDR3_CK_P,
	HPS_DDR3_CS_N,
	HPS_DDR3_DM,
	HPS_DDR3_DQ,
	HPS_DDR3_DQS_N,
	HPS_DDR3_DQS_P,
	HPS_DDR3_ODT,
	HPS_DDR3_RAS_N,
	HPS_DDR3_RESET_N,
	HPS_DDR3_RZQ,
	HPS_DDR3_WE_N,
);


input CLOCK_50;
output [6:0] HEX0, HEX1, HEX2, HEX3, HEX4, HEX5;
input [3:0] KEY;
output [9:0] LEDR;
input [9:0] SW;

output [14:0] HPS_DDR3_ADDR;
output [2:0] HPS_DDR3_BA;
output HPS_DDR3_CAS_N;
output HPS_DDR3_CKE;
output HPS_DDR3_CK_N;
output HPS_DDR3_CK_P;
output HPS_DDR3_CS_N;
output [3:0] HPS_DDR3_DM;
inout [31:0] HPS_DDR3_DQ;
inout [3:0] HPS_DDR3_DQS_N;
inout [3:0] HPS_DDR3_DQS_P;
output HPS_DDR3_ODT;
output HPS_DDR3_RAS_N;
output HPS_DDR3_RESET_N;
input HPS_DDR3_RZQ;
output HPS_DDR3_WE_N;

wire [31:0] hex3_hex0;
wire [15:0] hex5_hex4;

assign HEX0 = ~hex3_hex0[6:0];
assign HEX1 = ~hex3_hex0[14:8];
assign HEX2 = ~hex3_hex0[22:16];
assign HEX3 = ~hex3_hex0[30:24];
assign HEX4 = ~hex5_hex4[6:0];
assign HEX5 = ~hex5_hex4[14:8];





    mysystem u0 (
        .clk_clk            (<connected-to-clk_clk>),            //         clk.clk
        .reset_reset_n      (<connected-to-reset_reset_n>),      //       reset.reset_n
        .memory_mem_a       (<connected-to-memory_mem_a>),       //      memory.mem_a
        .memory_mem_ba      (<connected-to-memory_mem_ba>),      //            .mem_ba
        .memory_mem_ck      (<connected-to-memory_mem_ck>),      //            .mem_ck
        .memory_mem_ck_n    (<connected-to-memory_mem_ck_n>),    //            .mem_ck_n
        .memory_mem_cke     (<connected-to-memory_mem_cke>),     //            .mem_cke
        .memory_mem_cs_n    (<connected-to-memory_mem_cs_n>),    //            .mem_cs_n
        .memory_mem_ras_n   (<connected-to-memory_mem_ras_n>),   //            .mem_ras_n
        .memory_mem_cas_n   (<connected-to-memory_mem_cas_n>),   //            .mem_cas_n
        .memory_mem_we_n    (<connected-to-memory_mem_we_n>),    //            .mem_we_n
        .memory_mem_reset_n (<connected-to-memory_mem_reset_n>), //            .mem_reset_n
        .memory_mem_dq      (<connected-to-memory_mem_dq>),      //            .mem_dq
        .memory_mem_dqs     (<connected-to-memory_mem_dqs>),     //            .mem_dqs
        .memory_mem_dqs_n   (<connected-to-memory_mem_dqs_n>),   //            .mem_dqs_n
        .memory_mem_odt     (<connected-to-memory_mem_odt>),     //            .mem_odt
        .memory_mem_dm      (<connected-to-memory_mem_dm>),      //            .mem_dm
        .memory_oct_rzqin   (<connected-to-memory_oct_rzqin>),   //            .oct_rzqin
        .rled_export        (<connected-to-rled_export>),        //        rled.export
        .hex3_hex0_export   (<connected-to-hex3_hex0_export>),   //   hex3_hex0.export
        .hex5_hex4_export   (<connected-to-hex5_hex4_export>),   //   hex5_hex4.export
        .switches_export    (<connected-to-switches_export>),    //    switches.export
        .pushbuttons_export (<connected-to-pushbuttons_export>)  // pushbuttons.export
    );

endmodule