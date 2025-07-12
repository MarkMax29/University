module dec2x4(
  input e,
  input [1:0]d,
  output reg [3:0]o
);
  always @(*) begin
    if (e) begin
      case (d)
        2'b00: o = 4'b0001;
        2'b01: o = 4'b0010;
        2'b10: o = 4'b0100;
        2'b11: o = 4'b1000;
        default: o = 4'b0000; // Default pentru siguran??
      endcase
    end else begin
      o = 4'b0000; // Dac? `e` este 0, ie?irea este 0
    end
  end
  
endmodule

module mux4x1(
  input [1:0]s,
  input [7:0]d0,d1,d2,d3,
  output reg [7:0]o
);
  
  always @(*)begin
    case(s)
      2'b00: o = d0;
      2'b01: o = d1;
      2'b10: o = d2;
      2'b11: o = d3;
      default: o = 8'b0; // Default pentru siguran??
    endcase
  end
  
endmodule


module register(
  input ld,clk,rst,
  input [7:0]d,
  output reg [7:0]q
);
  
  always @(posedge clk, negedge rst) begin
    if(!rst)
      q<=0;
    else
      if(ld)
        q<=d;
  end
  
endmodule

module regfl(
  input [7:0]wr_data,
  input [1:0]wr_addr,rd_addr,
  input clk,rst,wr_e,
  output reg [7:0]rd_data
);
  
  wire [3:0]dec_out;
  dec2x4 DUT0(
    .e(1'd1),
    .d(wr_addr),
    .o(dec_out)
  );
  
  wire [7:0]reg_out[3:0];
  generate
    genvar k;
    for(k=0;k<4;k=k+1) begin:v
      register DUT1(
        .clk(clk),
        .rst(rst),
        .ld(dec_out[k]),
        .d(wr_data),
        .q(reg_out[k])
      );
    end
  endgenerate
  
 /* mux2s #(
    .w(8)
  ) DUT2(
    .d0(reg_out[0]),
    .d1(reg_out[1]),
    .d2(reg_out[2]),
    .d3(reg_out[3]),
    .s(rd_addr),
    .o(rd_data)
  );*/
  
  mux4x1 DUT2(
    .d0(reg_out[0]),
    .d1(reg_out[1]),
    .d2(reg_out[2]),
    .d3(reg_out[3]),
    .s(rd_addr),
    .o(rd_data)
  );
  
endmodule
module regfl_tb;
  
  reg [7:0]wr_data;
  reg [1:0]wr_addr,rd_addr;
  reg wr_e,clk,rst;
  wire [7:0]rd_data;
  
  regfl inst(
    .clk(clk),
    .rst(rst),
    .wr_e(wr_e),
    .wr_data(wr_data),
    .wr_addr(wr_addr),
    .rd_addr(rd_addr),
    .rd_data(rd_data)
  );
  
  initial begin
    $dumpfile("dump.vcd"); $dumpvars;
  end
  
  integer k;
  initial begin
    clk=0;
    for(k=1;k<18;k=k+1)
      #50 clk=~clk;
  end
  
  initial begin
    rst=0;
    #5;
    rst=1;
  end
  
  initial begin
    wr_e=1;
    #200;
    wr_e=0;
    #100;
    wr_e=1;
    #400;
    wr_e=0;
  end
  
  initial begin
    wr_addr=2'h0; wr_data=8'ha2; rd_addr=2'h3;
    #100;
    wr_addr=2'h2; wr_data=8'h2e; rd_addr=2'h0;
    #100;
    wr_addr=2'h1; wr_data=8'h98; rd_addr=2'h1;
    #100;
    wr_addr=2'h3; wr_data=8'h55; rd_addr=2'h2;
    #100;
    wr_addr=2'h0; wr_data=8'h20; rd_addr=2'h0;
    #100;
    wr_addr=2'h1; wr_data=8'hff; rd_addr=2'h3;
    #100;
    wr_addr=2'h3; wr_data=8'hc7; rd_addr=2'h1;
    #100;
    wr_addr=2'h2; wr_data=8'hb5; rd_addr=2'h2;
    #100;
    wr_addr=2'h3; wr_data=8'h91; rd_addr=2'h3;
    
  end
  
endmodule