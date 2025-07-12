module fsmm(
  input clk,rst_b,
  input A6,X3,I3,
  output reg o
  );
  
  localparam S0=0;
  localparam S1=1;
  localparam S2=2;
  localparam S3=3;
  reg [1:0]st,st_next;
  always @(*)begin
    o=0;
    case (st)
      S0: if((A6&X3&I3)|X3) o=1;
         else o=0;
    endcase 
  end
    
  always @(*)begin
    case(st)
      S0:  
          if((A6&X3&I3)|X3)
            st_next=S0;
          else if((I3&A6)|(I3&X3))
            st_next=S1;
          else if((I3&X3)|(A6&X3&I3))
            st_next=S2;
          else if(X3)
            st_next=S3;
      S1:   
            //o=0;
            if(A6&I3)
              st_next=S2;
            else
              st_next=S0;
      S2:
          //o=0;
            if((I3&A6)|X3)
              st_next=S2;
      S3: 
         // o=0;
          if((X3&A6)|(A6&I3))
              st_next=S2;
    endcase
  end
  
  always @(posedge clk,negedge rst_b)begin
    if(!rst_b)  st<=S0;
    else  st<=st_next;
    end
  endmodule
  
  module fsm_tb;
    reg clk,rst_b,A6,X3,I3;
    wire o;
    
    fsmm inst(.clk(clk),.rst_b(rst_b),.A6(A6),.X3(X3),.I3(I3),.o(o));
    
    initial begin
      clk=0;
      repeat (21) #50 clk=~clk;
    end
    initial begin
      rst_b=0;
      #100 rst_b=~rst_b;
    end
    initial begin 
      A6=0;
      #105 A6=1;
      #95 A6=0;
      #205 A6=1;
      #495 A6=0;
    end
    initial begin
      X3=1;
      #105 X3=0;
      #150 X3=1;
      #150 X3=0;
      #150 X3=1;
      #100 X3=0;
      #100 X3=1;
      #200 X3=0;
      #50  X3=1;
    end
    initial begin
      I3=1;
      #55 I3=0;
      #100 I3=1;
      #100 I3=0;
      #100 I3=1;
      #100 I3=0;
      #100 I3=1;
      #50 I3=0;
      #150 I3=1;
      #150 I3=0;
      #50 I3=1;
      #50 I3=0;
  end 
  
initial begin
  $monitor("TIME = %0t | clk = %b | rst_b = %b | A6 = %b | X3 = %b | I3 = %b | o = %b", $time, clk, rst_b, A6, X3, I3, o);
end
endmodule


/*
module fsm(
  input clk, rst_b, a6, x3, i3,
  output reg o
);

localparam s0 = 2'd0;
localparam s1 = 2'd1;
localparam s2 = 2'd2;
localparam s3 = 2'd3;
reg [1:0] st, st_next;

always @(*) begin
  case (st)
    s0: if((i3 & a6) | (i3 & x3)) st_next = s1; else st_next = s0;
    s1: if(a6 & i3) st_next = s1; else st_next = s0;
    s3: if((x3 & a6) | (a6 & i3)) st_next = s2; else st_next = s3;
  endcase
end

always @(*) begin
  o = 0;
  case (st)
    s0: if((a6 & x3 & i3) | x3) o = 1; else o = 0;  
  endcase
end

always @(posedge clk, negedge rst_b) begin
  if(!rst_b) st <= s0;
  else st <= st_next;
end
endmodule

module fsm_tb;
  reg clk, rst_b, a6, x3, i3;
  wire o;
  
  fsm fsm_i(.clk(clk), .rst_b(rst_b), .a6(a6), .x3(x3), .i3(i3), .o(o));
  
  integer i;
  initial begin
    clk = 0;
    rst_b = 0;
    a6 = 0;
    x3 = 1;
    i3 = 1;
  end
  
  initial begin
    for(i = 1; i <= 10; i = i + 1) begin
      #50; clk = ~clk;
    end
  end
  
  initial begin
    #75; rst_b = 1;
  end
  
  initial begin
    #100; a6 = 1;
    #125; a6 = 0; 
    #275; a6 = 1;
    #450; a6 = 0;
  end
  
  initial begin
    #100; x3 = 0;
    #150; x3 = 1;
    #150; x3 = 0;
    #150; x3 = 1;
    #200; x3 = 0;
    #250; x3 = 1;
  end
  
  initial begin
    #50; i3 = 0;
    #100; i3 = 1;
    #400; i3 = 0;
    #150; i3 = 1;
    #100; i3 = 0;
  end

initial begin
  $monitor("TIME = %0t | clk = %b | rst_b = %b | a6 = %b | x3 = %b | i3 = %b | o = %b", $time, clk, rst_b, a6, x3, i3, o);
  end
endmodule
*/