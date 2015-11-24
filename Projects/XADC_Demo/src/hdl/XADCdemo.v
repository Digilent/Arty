`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: Digilent inc.
// Engineer: Samuel Lowe
// Engineer Email: samuel.lowe@ni.com
// Create Date: 05/28/2015 03:26:51 PM
// Design Name: XADCdemo
// Module Name: XADCdemo: 
// Target Devices: ARTY
// Tool Versions: Vivado 15.1
// Description: A top level design for reading values off of the XADC Pmod port of the ARTY FPGA
// 
// Dependencies: 
// 
// Revision: 3/3/2015
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////
 

module XADCdemo(
   input CLK100MHZ,
   input [8:0] ck_an_p,
   input [8:0] ck_an_n,
   
   input [3:0] sw,
   output reg [7:0] LED

 );
   
   wire enable;  
   wire ready;
   wire [15:0] data;   
   reg [6:0] Address_in;     

  
   
   //xadc instantiation connect the eoc_out .den_in to get continuous conversion

   xadc_wiz_0 xadc
          (
          .daddr_in(Address_in),            // Address bus for the dynamic reconfiguration port
          .dclk_in(CLK100MHZ),             // Clock input for the dynamic reconfiguration port
          .den_in(enable),              // Enable Signal for the dynamic reconfiguration port
          .di_in(),               // Input data bus for the dynamic reconfiguration port
          .dwe_in(),              // Write Enable for the dynamic reconfiguration port
          .reset_in(),            // Reset signal for the System Monitor control logic
          .vauxp4(ck_an_p[0]),              // Auxiliary channel 0
          .vauxn4(ck_an_n[0]),
          .vauxp5(ck_an_p[1]),              // Auxiliary channel 5
          .vauxn5(ck_an_n[1]),
          .vauxp6(ck_an_p[2]),              // Auxiliary channel 5
          .vauxn6(ck_an_n[2]),
          .vauxp7(ck_an_p[3]),              // Auxiliary channel 6
          .vauxn7(ck_an_n[3]),
          .vauxp15(ck_an_p[4]),              // Auxiliary channel 7
          .vauxn15(ck_an_n[4]),
          .vauxp0(ck_an_p[5]),             // Auxiliary channel 12
          .vauxn0(ck_an_n[5]),
          .vauxp12(ck_an_p[6]),             // Auxiliary channel 13
          .vauxn12(ck_an_n[6]),
          .vauxp13(ck_an_p[7]),             // Auxiliary channel 14
          .vauxn13(ck_an_n[7]),
          .vauxp14(ck_an_p[8]),             // Auxiliary channel 15
          .vauxn14(ck_an_n[8]),
          .busy_out(),            // ADC Busy signal
          .channel_out(),         // Channel Selection Outputs
          .do_out(data),              // Output data bus for dynamic reconfiguration port
          .drdy_out(ready),            // Data ready signal for the dynamic reconfiguration port
          .eoc_out(enable),             // End of Conversion Signal
//          .eos_out(),             // End of Sequence Signal
          .alarm_out(),           // OR'ed output of all the Alarms    
          .vp_in(),               // Dedicated Analog Input Pair
          .vn_in());                 
         
    
      //led visual dmm              
      always @( posedge(CLK100MHZ))
      begin            
        if(ready == 1'b1)
        begin
          case (data[15:13])
            1:  LED <= 8'b11;
            2:  LED <= 8'b111;
            3:  LED <= 8'b1111; 
            4:  LED <= 8'b11111;
            5:  LED <= 8'b111111;
            6:  LED <= 8'b1111111;
            7:  LED <= 8'b11111111;                    
           default: LED <= 8'b0; 
           endcase
        end           
      end
           
      //switch driver to choose channel
      always @(posedge(CLK100MHZ))
      begin
        case(sw)
        0: Address_in <= 8'h14; //A0
        1: Address_in <= 8'h15; //A1
        2: Address_in <= 8'h16; //A2
        3: Address_in <= 8'h17; //A3
        4: Address_in <= 8'h1F; //A4
        5: Address_in <= 8'h10; //A5
        6: Address_in <= 8'h1C; //A6 - A7 differential
        7: Address_in <= 8'h1D; //A8 - A9 differential
        8: Address_in <= 8'h1E; //A10 - A11 diferential
        default: Address_in <= 8'h14; //A0
        endcase
      end
endmodule
