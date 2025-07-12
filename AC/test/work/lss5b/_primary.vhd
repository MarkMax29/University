library verilog;
use verilog.vl_types.all;
entity lss5b is
    port(
        clk             : in     vl_logic;
        rst_b           : in     vl_logic;
        q               : out    vl_logic_vector(4 downto 0)
    );
end lss5b;
