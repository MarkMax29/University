module fac(
  input x,y,ci,
  output z,co
  );
   assign {co,z}=x+y+ci;

endmodule

module add2b(
  input [1:0]x_add,y_add,
  input ci,
  output [1:0]z_add,
  output co
  );
 

wire c1;// wire pt conexiunea de la co al primului fac la ci la al doilea fac

fac inst1(
  .x(x_add[0]),
  .y(y_add[0]),
  .ci(ci),
  .co(c1),
  .z(z_add[0])
  );
fac inst2(
  .x(x_add[1]),
  .y(y_add[1]),
  .ci(c1),
  .co(co),
  .z(z_add[1])
  );
endmodule

module add2b_tb;
  reg [1:0]x_add,y_add;
  reg ci;
  wire [1:0]z_add;
  wire co;
  
  add2b add2b_inst(.x_add(x_add),.y_add(y_add),.ci(ci),.z_add(z_add),.co(co));
  
  integer k;
  initial begin
    $display("Time\tx\ty\tci\tz\tco");
    $monitor("%0t\t%b\t%b\t%b\t%b\t%b", $time, x_add, y_add, ci, z_add,co);
  for(k=0;k<32;k=k+1) begin
    {x_add,y_add,ci}=k;
    #10;
  end
  end
endmodule