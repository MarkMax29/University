library verilog;
use verilog.vl_types.all;
entity dec1_4 is
    port(
        s               : in     vl_logic_vector(1 downto 0);
        e               : in     vl_logic;
        o               : out    vl_logic_vector(3 downto 0)
    );
end dec1_4;
