-- testbench for a 1 bit full adder to test vunit
--------------------------------------------------------
-- full adder should have the following truth table
-- |Inputs |Outputs |
-- |A|B|Cin|Cout|Sum|
--------------------------------------------------------
-- |0|0|0  |  0 | 0 |
-- |0|0|1  |  0 | 1 |
-- |0|1|0  |  0 | 1 |
-- |0|1|1  |  1 | 0 |
-- |1|0|0  |  0 | 1 |
-- |1|0|1  |  1 | 0 |
-- |1|1|0  |  1 | 0 |
-- |1|1|1  |  1 | 0 |
---------------------------------------------------------
-- original test bench for 1 bit adder sourced from 
-- http://www.fpga4student.com/2017/02/vhdl-code-for-full-adder.html

Library IEEE;
USE IEEE.Std_logic_1164.all;

library vunit_lib;
context vunit_lib.vunit_context;
context vunit_lib.vc_context;

library caffeToFPGA_lib;

entity vunit_test_tb is
	generic (
		runner_cfg : string
	);
end vunit_test_tb;
 
architecture  tb of vunit_test_tb is
component Full_Adder_Structural_VHDL 
	port( 
		X1, X2, Cin : in std_logic;  
		S, Cout : out std_logic
	);  
end component; 
	signal A,B,Cin: std_logic:='0';
	signal S,Cout: std_logic;
begin   
	structural_adder: Full_Adder_Structural_VHDL port map 
	(
		X1 => A,
		X2 => B,
		Cin => Cin,
		S => S,
		Cout => Cout 
	);
main : process
begin
	test_runner_setup(runner, runner_cfg);
	
	while test_suite loop
		if run("test_all_low") then
			A <= '0';
			B <= '0';
			Cin <= '0';
			wait for 100 ns; -- this doesn't necessarily need to be this long
			check_equal(Cout, '0');
			check_equal(S, '0');
			
		elsif run("test_Cin_high") then
			A <= '0';
			B <= '0';
			Cin <= '1';
			wait for 1 ns;
			check_equal(Cout, '0');
			check_equal(S, '1');
			
		elsif run("test_B_high") then
			A <= '0';
			B <= '1';
			Cin <= '0';
			wait for 1 ns;
			check_equal(Cout, '0');
			check_equal(S, '1');
			
		elsif run("test_B_Cin_high") then
			A <= '0';
			B <= '1';
			Cin <= '1';
			wait for 1 ns;
			check_equal(Cout, '1');
			check_equal(S, '0');
			
		elsif run("test_A_high") then
			A <= '1';
			B <= '0';
			Cin <= '0';
			wait for 1 ns;
			check_equal(Cout, '0');
			check_equal(S, '1');
		
		elsif run("test_A_Cin_high") then
			A <= '1';
			B <= '0';
			Cin <= '1';
			wait for 1 ns;
			check_equal(Cout, '1');
			check_equal(S, '0');
			
		elsif run("test_A_B_high") then
			A <= '1';
			B <= '1';
			Cin <= '0';
			wait for 1 ns;
			check_equal(Cout, '1');
			check_equal(S, '0');
			
		elsif run("test_all_high") then
			A <= '1';
			B <= '1';
			Cin <= '1';
			wait for 1 ns;
			check_equal(Cout, '1');
			check_equal(S, '1');
		end if;
	end loop;
	
	test_runner_cleanup(runner);
	wait;
end process;
end architecture;
