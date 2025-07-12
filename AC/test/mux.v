module mux(
  input [7:0] d0,d1,d2,d3,
  input [1:0]s,
  output reg [7:0]o
  );
  
 always @(*)begin
   if(s==0)
     o=d0;
 else if(s==1)
    o=d1;
  else if(s==2)
    o=d2;
  else if (s==3)
    o=d3;
  end
 endmodule