module mux2_1(
  input i0,i1,s,
  output reg o
  );
always @(*)
  if(s==0)
    o=i0;
  else
    o=i1;
endmodule


module mux2s #(
  parameter w=4
  )(
  input [w-1:0]d,
  input [1:0]s,
  output o
  );
  wire f,g;

 mux2_1 inst1(
  .i0(d[0]),
  .i1(d[1]),
  .s(s[0]),
  .o(f)
  );
  mux2_1 inst2(
  .i0(d[2]),
  .i1(d[3]),
  .s(s[0]),
  .o(g)
  );
  mux2_1 inst3(
  .i0(f),
  .i1(g),
  .s(s[1]),
  .o(o)
  );
      
endmodule
/*
module mux2s_tb;
  parameter w=4;
  reg [w-1:0]d;
  reg [1:0]s;
  wire o;
  
  mux2s #(.w(w)) instanta(.d(d),.s(s),.o(o));

  initial begin
     
     $monitor("Time=%0t  |d=%b | s=%b |o=%b",$time,d,s,o);
         // Test case 1
    d = 4'b0001; s = 2'b00; #10; // Expect o = d[0] = 1

  
     // Test case 2
    d = 4'b0010; s = 2'b01; #10; // Expect o = d[1] = 1

    // Test case 3
    
    d = 4'b0100; s = 2'b10; #10; // Expect o = d[2] = 1

    // Test case 4
    d = 4'b1000; s = 2'b11; #10; // Expect o = d[3] = 1

    // Test case 5 (mixed values)
    
    d = 4'b1010; s = 2'b00; #10; // Expect o = d[0] = 0
    s = 2'b01; #10;            // Expect o = d[1] = 1
    s = 2'b10; #10;            // Expect o = d[2] = 1
    s = 2'b11; #10;            // Expect o = d[3] = 0

    // End simulation

  end

endmodule
*/
  