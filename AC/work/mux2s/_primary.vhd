library verilog;
use verilog.vl_types.all;
entity mux2s is
    generic(
        w               : integer := 4
    );
    port(
        d               : in     vl_logic_vector;
        s               : in     vl_logic_vector(1 downto 0);
        o               : out    vl_logic
    );
end mux2s;
