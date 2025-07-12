module patt(
  input clk,rst_b,i,
  output o
  );
  localparam S0=0,S1=1,S2=2,S3=3,S4=4;
  reg [2:0]st,st_next;
  always @(*)
    case(st)
      S0: if(i)
            st_next=S1;
          else
            st_next=S0;
      S1: if(!i)
            st_next=S2;
          else
            st_next=S1;
      S2: if(i)
            st_next=S3;
          else
            st_next=S0;
      S3: if(i)
            st_next=S4;
          else
            st_next=S2;
      S4: st_next=S0;
    endcase
  assign o=(st==S4);
  
  always @(posedge clk,negedge rst_b)
    if(!rst_b)  st<=S0;
    else  st<=st_next;
endmodule

module patt_tb;
  reg clk,rst_b,i;
  wire o;
  
  patt inst(.clk(clk),.rst_b(rst_b),.i(i),.o(o));
  
  initial begin
    clk=0;
    repeat (14) #50 clk=~clk;
  end
  initial begin
    rst_b=0;
    #25;
    rst_b=~rst_b;
  end
  initial begin
    i=1;
    #100; 
    i=0;
    #100; 
    i=1;
    #200;
     i=0;
    #100;
     i=1;
  end
endmodule