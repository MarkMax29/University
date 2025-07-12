library verilog;
use verilog.vl_types.all;
entity reg_8 is
    port(
        ld              : in     vl_logic;
        clk             : in     vl_logic;
        rst_b           : in     vl_logic;
        clr             : in     vl_logic;
        d               : in     vl_logic_vector(7 downto 0);
        q               : out    vl_logic_vector(7 downto 0)
    );
end reg_8;
