module pktmux(
  input [63:0]msg_len,pkt,
  input pad_pkt,zero_pkt,mgln_pkt,
  output reg [63:0]o
  );
  
  always@(*)
    if(pad_pkt==1)  o=(1<<63);
    else if(zero_pkt==1) o=0;
    else if(mgln_pkt==1) o=msg_len;
    else  o=pkt;
endmodule

module  pktmux_tb;
  reg [63:0]msg_len,pkt;
  reg pad_pkt,zero_pkt,mgln_pkt;
  wire [63:0]o;
  
  pktmux inst(.msg_len(msg_len),.pkt(pkt),.pad_pkt(pad_pkt),.zero_pkt(zero_pkt),.mgln_pkt(mgln_pkt),.o(o));
  
  initial begin
    pad_pkt=0;
    zero_pkt=0;
    mgln_pkt=0;
   repeat(3)begin 
      #100;
        pad_pkt=1;
      #100
        pad_pkt=0;
        zero_pkt=1;
      #100;
        zero_pkt=0;
        mgln_pkt=1; 
      #100;
        mgln_pkt=0; 
    end 
  end

task urand64(output reg [63:0]r);
  begin
    r[63:32]=$urandom;
    r[31:0]=$urandom;
  end
endtask
integer k;
initial begin
  urand64(pkt);
  urand64(msg_len);
  for(k=1;k<13;k=k+1)begin
    #100;
    urand64(pkt);
    urand64(msg_len);
    end
  end
 endmodule      