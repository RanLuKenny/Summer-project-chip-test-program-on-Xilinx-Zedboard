# Summer-project-chip-test-program-on-Xilinx-Zedboard
This is the real silicon chip test program on Xilinx Zedboard:

There 4 steps in the program design.

1. Linux system (Xilinux) installation on FPGA Zedboard.

2. Extract test vector from '.vcd' file and store the vector into temp file.

3. Extract the input vector from temp file and drive the chip on board.

4. Control the GPIOs by Xilinux.

5. Compare the final results between chip outputs and temp file.

# How to run the program? 
-Download all the python script files and C files into Zedboard

-Run the python file (command.py) in terminal

    # python command.py
    
-Compare the results

    # diff data.txt text.txt
    
-Check the results
