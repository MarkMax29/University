module patt(
  input clk,rst_b,
  input i,
  output reg o
  );
  
  localparam s0=3'd0;
  localparam s1=3'd1;
  localparam s2=3'd2;
  localparam s3=3'd3;
  localparam s4=3'd4;
  reg [2:0]st;
  reg [2:0]st_next;
  
  always @(*) begin
    st_next=st;
    case(st)
      s0: st_next=(i==1)?s1:s0;
      s1: st_next=(i==0)?s2:s0;
      s2: st_next=(i==1)?s3:s0;
      s3: st_next=(i==1)?s4:s0;
      s4: st_next=(i==0)?s2:s4;
    default: st_next=s0;
endcase
end
//assign o=(st==s4);
always @(*)begin
  o=1'b0;
  case(st)
    s0,s1,s2,s3: o=1'b0;
    s4: o=1'b1;
  endcase
end
always @(posedge clk,negedge rst_b) begin
  if(!rst_b)
      st<=s0;
  else  
      st<=st_next;
end
endmodule

module patt_tb;
  reg clk,rst_b,i;
  wire o;
  
  patt inst(.clk(clk),.rst_b(rst_b),.i(i),.o(o));
  
  initial begin
    clk=0;
    repeat (8) #100 clk=~clk;
  end
  initial begin
    rst_b=0;
    #25 rst_b=~rst_b;
  end
  initial begin
    i=1;
    #100 i=0;
    #100 i=1;
    #200 i=0;
    #100 i=1;
  end
endmodule
      
       
     