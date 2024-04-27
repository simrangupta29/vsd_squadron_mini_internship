# vsd_squadron_mini_internship
Mini summer internship under vlsi system design on riscv-architecture and about open source eda tools.
# TASK-1
First installed the oracle virtual machine<br />
The next step was to download ubuntu and open it into virtual box.<br />
# RISCV-Toolchain
This is the RISC-V C and C++ cross-compiler. It supports two build modes: a generic ELF/Newlib toolchain and a more sophisticated Linux-ELF/glibc toolchain.<br />
give command:-$ sudo apt-get install autoconf automake autotools-dev curl python3 python3-pip libmpc-dev libmpfr-dev libgmp-dev gawk build-essential bison flex texinfo gperf libtool patchutils bc zlib1g-dev libexpat-dev ninja-build git cmake libglib2.0-dev libslirp-dev<br />
$git clone -- recursive https://github.com/riscv/riscv-gnu-toolchain <br />
$./configure --prefix=/opt/riscv<br />
$ make linux<br />
$ sudo make linux<br />
![intern_riscv](https://github.com/simrangupta29/vsd_squadron_mini_internship/assets/130252328/d3cf31fe-2712-4d0d-ad97-b394c5498b41)
# YOSYS
$ git clone https://github.com/YosysHQ/yosys.git<br />
$ cd yosys<br />
$ sudo apt install make (If make is not installed please install it) <br />
$ sudo apt-get install build-essential clang bison flex \<br />
    libreadline-dev gawk tcl-dev libffi-dev git \<br />
    graphviz xdot pkg-config python3 libboost-system-dev \<br />
    libboost-python-dev libboost-filesystem-dev zlib1g-dev<br />
$ make config-gcc<br />
$ make <br />
$ sudo make install<br />
![intern_yosys](https://github.com/simrangupta29/vsd_squadron_mini_internship/assets/130252328/a562fb43-7d69-4e0c-b9c6-cd00f0c9dc0f)
# verilog
$sudo apt-get install iverilog<br />
![intern_verilog](https://github.com/simrangupta29/vsd_squadron_mini_internship/assets/130252328/99574331-89fb-4484-ae07-7ef634dfb823)

# Gtkware
$sudo apt update<br />
$sudo apt install gtkwave<br />
![intern_gitkware](https://github.com/simrangupta29/vsd_squadron_mini_internship/assets/130252328/533e8301-6589-47dc-a309-4882c1bc80af)
# TASK-2
# ABOUT RISC-V
RISC-V is an open, versatile instruction-set architecture supporting diverse implementations. </br>
RISC-V is the first widely accepted open-source RISC processor </br>.
It features a base integer ISA, optional extensions, 32/64-bit variants, IEEE-754 floating-point support, and facilitates experimentation with privileged architectures, hypervisors, and parallel computing.
# INSTRUCTION SET IN RISCV
The RISC-V instruction set is known as RV32I (RISC-V 32-bit integer only) only has 40 instructions. The ISA ( instruction set architecure ) has two sources and one 
destination operands.</br>
# RISCV OPERANDS LOCATION
1.REGISTER-The fastest and most often used operand is from or to registers on the CPU chip itself. RISC-V RV32I has 32 32-bit registers. 32 registers 
means the instruction must use 3 x 5-bit = 15 bit of the 32-bit instruction.</br>
2.MEMORY-the instruction must specify the data memory address, using a register as a pointer</br>
3.CONSTANTS(IMMEDIATES)-The third is from instruction memory, i.e. the operand is a constant within  the instruction itself. this is also called an immediate.</br>
</br>
The format of the instructions are divided into only six different types</br>
1.<b>R-type (Register/register)</b> instructions use only registers as source and 
destiantions. This instruction type is mostly used for arithmetic and logic 
operations involving the ALU.</br>
| Column 1 | Column 2           | Column 3 | Column 4 | Column 5 | Column 6 |
|----------|--------------------|----------|----------|----------|----------|
| INSTRUCTION TYPE   |      [20-31]                            |  [20-24]  | [15-19]    | [12-14] | [7-11]  | [0-6]     |
| REGISTER           |        imm[0:11]                        | rs1   | function3     |   rd     |  opcode    |

2.<b>I-type (Immediate)</b> instructions has one of the two source operands specified 
within the 32-bit instruction word as a 12-bit constant (or immediate). This 
constant is regards as 12-bit signed 2’s complement number, which is always 
sign extended to form a 32-bit operand.</br>
| Column 1 | Column 2 | Column 3 | Column 4 | Column 5 | Column 6 | Column 7 |
|----------|----------|----------|----------|----------|----------|----------|
| INSTRUCTION TYPE   |     [25-31]           |  [20-24]  | [15-19]    | [12-14] | [7-11]  | [0-6]     |
| Immediates  | function7     | rs2     | rs1   | function3     |   rd     |  opcode    |

3.<b>S-type (Store)</b> instructions are exclusively used for storing contents of a 
register to data memory. </br>
4.<b>B-type (Branch)</b> instructions are used to control program flow. It compares 
two operands stored in registers and branch to a destination address relative 
to the current Program Counter value. </br>
5.<b>J-type (Jump)</b> instructions are used for subroutine calls.</br>
6 <b>U-type (Upper immediate)<b> instructions are used to specify the upper 20 bits immediate value of a register</br>









