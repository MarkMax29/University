module div3(
  input [3:0]i,
  output reg [2:0]o
  );
  
  always @(*)
    case(i)
      0,1,2: o=0;
      3,4,5: o=1;
      6,7,8: o=2;
      9,10,11: o=3;
      12,13,14: o=4;
      default: o=5;
    endcase
  endmodule
  
  module div3_tb;
    reg [3:0]i;
    wire [2:0]o;
  div3 div3_instance(.i(i),.o(o));
  
  integer k;
  
  initial begin
    $display("Time\ti\t\to");
    $monitor("%0t\t%b(%2d)\t%b(%0d)",$time,i,i,o,o);
    i=0;
    for(k=1;k<16;k=k+1)
      #10 i=k;
    end
  endmodule