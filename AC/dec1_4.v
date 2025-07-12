module dec1_4(
  input [1:0]s,
  input e,
  output reg [3:0]o
  );
  always@(*)
    if(e==0)
      o=0;
    else
      o[s]=1;     
endmodule