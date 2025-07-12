module reg_8(
  input ld,clk,rst_b,clr,[7:0]d,
  output reg [7:0]q
  );
  
  always@(posedge clk,negedge rst_b)begin
    if(!rst_b)  q<=0;
    else if(clr) q<=0;
    else if(ld) q<=d;
   
  end
endmodule