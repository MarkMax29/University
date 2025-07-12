module mul5bcd(
  input [3:0]i,
  output reg [3:0]d,u
  );
  
  always @(*)
    if(i[0]==0)
      u=4'd0;
    else
      u=4'd5;
      d = {1'd0, i[3:1]};
  d=i/2;
  end
endmodule

module mul5bcd_tb;
  reg [3:0]i;
  wire [3:0]d,u;
  
  mul5bcd instance(.i(i),.d(d),.u(u));
  
  integer k;
  initial begin
    $display("Time\ti\t\td\t\tu");
    $monitor("%0t\t%b(%4d)\t%b(%4d)\t%b(%4d)",$time,i,i,d,d,u,u);
    i=0;
    for(k=1;k<16;k=k+1)
      #10 i=k;
  end
endmodule