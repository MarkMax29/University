library verilog;
use verilog.vl_types.all;
entity mux2_1 is
    port(
        i0              : in     vl_logic;
        i1              : in     vl_logic;
        s               : in     vl_logic;
        o               : out    vl_logic
    );
end mux2_1;
