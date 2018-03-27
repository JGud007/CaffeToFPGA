from os.path import join, dirname
from vunit import VUnit

ui = VUnit.from_argv()
ui.add_osvvm()
ui.add_verification_components()

src_path = join(dirname(__file__), "src")

caffeToFPGA_lib = ui.add_library("caffeToFPGA_lib")
caffeToFPGA_lib.add_source_files(join(src_path, "*.vhd"))

tb_lib = ui.add_library("tb_lib")
tb_lib.add_source_files(join(src_path, "test", "*.vhd"))

ui.main()