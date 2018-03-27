-- This is a simple 1 bit full adder to test functionality provided by vunit
-- code was sourced from http://www.fpga4student.com/2017/02/vhdl-code-for-full-adder.html
library ieee; 
use ieee.std_logic_1164.all;

library vunit_lib;
context vunit_lib.vunit_context;
context vunit_lib.vc_context;

library caffeToFPGA_lib;
  
entity Full_Adder_Structural_VHDL is  
port( 
	X1, X2, Cin : in std_logic;  
	S, Cout : out std_logic
);  
end Full_Adder_Structural_VHDL;  
architecture structural of Full_Adder_Structural_VHDL is  
	signal a1, a2, a3: std_logic;  
begin  
	a1 <= X1 xor X2;  
	a2 <= X1 and X2;  
	a3 <= a1 and Cin;  
	Cout <= a2 or a3;  
	S <= a1 xor Cin;  
end structural;  