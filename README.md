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
| Column 1 | Column 2 | Column 3 | Column 4 | Column 5 | Column 6 | Column 7 |
|----------|----------|----------|----------|----------|----------|----------|
| INSTRUCTION TYPE   |     [25-31]           |  [20-24]  | [15-19]    | [12-14] | [7-11]  | [0-6]     |
| Register  | function7     | rs2     | rs1   | function3     |   rd     |  opcode    |

</br>
 opcode (7): partially specifies operation.e.g. R-types have opcode = 0b0110011 </br>
funct7+funct3 (10): combined with opcode, these two fields describe what operation to perform </br>
rs1 (5): 1st operand (“source register 1”) </br>
 rs2 (5): 2nd operand (second source register) </br>
 rd (5): “destination register” — receives the result of computation </br>
 We know that RISCV has 32 registers </br> A 5 bit field can represent exactly 25 = 32 things  </br>
(interpret as the register numbers x0-x31)

2.<b>I-type (Immediate)</b> instructions has one of the two source operands specified 
within the 32-bit instruction word as a 12-bit constant (or immediate). This 
constant is regards as 12-bit signed 2’s complement number, which is always 
sign extended to form a 32-bit operand.</br>
| Column 1 | Column 2            | Column 3 | Column 4 | Column 5 | Column 6 |
|----------|---------------------|----------|----------|----------|----------|
|INSTRUCTION TYPE     |        [20-31]         | [15-19]     |  [12-14]    | [7-11]     | [0-6]     |
| Immediates     | imm[11:0]                | rs1      | function3     | rd     | opcode     |

</br>
 opcode (7): uniquely specifies the instruction</br>
 rs1 (5): specifies a register operand</br>
 rd (5): specifies destination register that receives result of computation</br>
 immediate (12): 12 bit number– All computations done in words, so 12-bit immediate must be extended to 32 bits</br>
                              – always sign-extended to 32-bits before use in an arithmetic operation</br>
 imm[11:0] can hold values in range [-211 , +211)</br>
 
 3.<b>S-type (Store)</b> instructions are exclusively used for storing contents of a 
register to data memory. </br>

| Column 1 | Column 2 | Column 3 | Column 4 | Column 5 | Column 6 | Column 7 |
|----------|----------|----------|----------|----------|----------|----------|
| INSTRUCTION TYPE   |     [25-31]           |  [20-24]  | [15-19]    | [12-14] | [7-11]  | [0-6]     |
| Register  |  imm[11:5]      | rs2     | rs1   | function3     |   imm[4:0]      |  opcode    |

</br>
Store needs to read two registers, rs1 for base memory address, and rs2 for data to be stored, as well as need immediate offset.</br>
 Can’t have both rs2 and immediate in same place as other instructions.</br>
 Note: stores don’t write a value to the register file, no rd!</br>
 RISC-V design decision is move low 5 bits of immediate to where rd field was in other instructions – keep rs1/rs2 fields in same place</br>


4.<b>B-type (Branch)</b> instructions are used to control program flow. It compares 
two operands stored in registers and branch to a destination address relative 
to the current Program Counter value. </br>

| Column 1 | Column 2 | Column 3 | Column 4 | Column 5 | Column 6 | Column 7 |
|----------|----------|----------|----------|----------|----------|----------|
| INSTRUCTION TYPE   |     [25-31]           |  [20-24]  | [15-19]    | [12-14] | [7-11]  | [0-6]     |
| Register  |  imm[12] , imm[10:5]      | rs2     | rs1   | function3     |    imm[4:0] ,imm[11]    |  opcode    |

</br>
B-format is mostly same as S-Format, with two register sources (rs1/rs2) and a 12-bit immediate</br>
The 12 immediate bits encode even 13-bit signed byte offsets (lowest bit of offset is always zero, so no need to store it</br>
It checks the condition between Rs1 and Rs2,if condition is true:</br>
pc=pc+immediate value(incrementing the pc) and jump to next address based on offset value</br>
if condition is false:</br>
pc=pc+4(which execute next input)</br>

5.<b>J-type (Jump)</b> instructions are used for subroutine calls.</br>

| Column 1 | Column 2          | Column 3          | Column 4 | Column 5 |
|----------|-------------------|-------------------|----------|----------|
|  INST TYPE  | [20-31]               |   [12-19]           |   [7-11]    | [0-6]    |
| U-TYPE    |      imm[20] , imm[10:1] ,imm[11]      |  imm[19:12]            | rd     | Opcode     |

</br>
The J-type instruction has instruction like JAL.It encodes 20 bits signed immediate</br>
The address of the desired memory location for jump is defined in the instruction.</br> 
jal saves PC+4 in register rd (the return address)<br>
 Set PC = PC + offset (PC-relative jump<br>

6 <b>U-type (Upper immediate)<b> instructions are used to specify the upper 20 bits immediate value of a register</br>

| Column 1 | Column 2             | Column 3 | Column 4 |
|----------|----------------------|----------|----------|
|  INST TYPE  | [12:31]                | [7-11 ]    | [0-6]    |
|  U-TYPE   | imm[12:31]                | rd    | opcode    |

</br>
This instruction should deal with:</br>
 a destination register to put the 20 bits into</br>
the immediate of 20 bits</br>
 the instruction opcode</br>
One destination register, rd</br>
 Used for two instructions</br>
 LUI – Load Upper Immediate</br>
AUIPC – Add Upper Immediate to PC</br>

# ANALYSING OF SOME OF INSTRUCTIONS WITH MACHINE CODE
1.<b>add r6,r2,r1</b>---It is R-type instruction.ADD is a typical ALU instruction in the class of 
arithmatic and logic operations. It needs two source operands and one destination 
operands to store the results.</br>
rs1=r2=00010,rs2=r1 = 00001</br>
rd: =r6=r1+r2= 00110</br>
The operation is specified with the opcode, funct3 and funct7 fields of the instructions.</br> 
opcode =0110011 funct3 = 000, funct7 = 0000000</br>
32 bit instruction(funct7 rs2 rs1 fun3 rd opcode )</br>
0000000 00001 00010 000 00110 0110011</br>

2.<b>SUB r7, r1, r2</b>---It is R-type instruction.SUB is a typical ALU instruction in the class of 
arithmatic and logic operations. It needs two source operands and one destination 
operands to store the results.</br>
rs1=r1=00001,rs2=r2 = 00010</br>
rd: =r7=rs1-rs2= 00111</br>
The operation is specified with the opcode, funct3 and funct7 fields of the instructions. </br>
opcode =0110011 funct3 = 000, funct7 =  0100000</br>
32 bit instruction(funct7 rs2 rs1 fun3 rd opcode )</br>
0000000 00010 00001 000 00111  0100000</br>


3.<b>AND r8, r1, r3</b>- this instruction belongs to R-type instruction set.
r8 will hold the value of r1 & r3, having bitwise and
rd = r8 = 01000
rs1 = r1 = 00001
rs2 = r3 = 00011
The operation is specified with the opcode, funct3 and funct7 fields of the instructions. </br>
Opcode for AND = 0110011,func3 = 111,func7 = 0000000
32 bits instruction :
0000000 00011 00001 111 01000 0110011

4.<b>OR r9,r2,r5</b>
It is also an R-type instruction.
rd = r9=01001
rs1 = r2=00010 ,rs2= r5:00101 
funct3 = 110 ,funct7 = 0000000 ,opcode: 0110011
The operation is specified with the opcode, funct3 and funct7 fields of the instructions. </br>
32 bits instruction :
0000000 00101 00010 110 01001 0110011

5.<b> XOR r10, r1, r4</b>
It is R-type instruction set.
XOR operation bit by bit.
rd = r10 = 01010
rs1 = r1 = 00001
rs2 = r4 = 00100
func3 = 100,func7 = 0000000,Opcode for XOR = 0110011
The operation is specified with the opcode, funct3 and funct7 fields of the instructions. </br>
32 bits instruction :
0000000 00100 00001 100 01010 0110011

6.<b>SLT r1, r2, r4</b>
It is R-type instruction set.
rd = r1 = 00001
rs1 = r2 = 00010
rs2 = r4 = 00100
func3 = 010,func7 = 0000000,Opcode for SLT = 0110011
The operation is specified with the opcode, funct3 and funct7 fields of the instructions. </br>
32 bits instruction :
0000000 00100 00010 010 00001 0110011

7.<b>ADDI r12, r4, 5</b>
It is I-type instruction set.
rd = r12 =r4+5= 01100
rs1 = r4 = 00100
imm[11:0] = 5 = 000000000101
func3 = 000, Opcode for ADDI = 0010011
32 bits instruction :
000000000000101 00100 000 01100 0010011

8.<b>SW r3, r1, 2</b>
It is S-type instruction set.
r3 is the source register. 
rs2 = r3 = 00011
rs1 = r1 = 00001
imm[11:0] = 2 = 000000000010
func3 = 010,Opcode for SW = 0100011
32 bits instruction : 
0000000 00011 00001 010 00010 0100011

9.<b>SRL r16, r14, r2</b>
SRL stands for Logical Shift Right.It is S-type instruction set.
r16 is the destination register
rd = r16 = 10000
rs1 = r14 = 01110
rs2 = r2 = 00010
func3 = 101,func7 = 0000000,Opcode for SRL = 0110011
32 bits instruction : 0000000 00010 01110 101 10000 0110011

10.<b>BNE r0, r1, 20</b>
BNE is a B-type instruction . In BNE, the value stored in r0 !=  the value stored in r1.
If the condition is true, PC = PC + 20, elsePC= PC + 4 
rs1 = r0 = 00000
rs2 = r1 = 00001
imm[12:1] = 20 = 000000010100
func3 = 001,Opcode for BNE = 1100011
32 bits instruction :
0 000001 00001 00000 001 0100 0 1100011

11.<b>BEQ r0, r0, 15</b>
BEQ is a B-type instruction. In BEQ,the value stored in r0 == the value stored in r0. 
If the condition is true, PC= PC + 15, else PC=PC+4
rs1 = r0 = 00000
rs2 = r0 = 00000
Imm[12:1] = 000000001111
func3 = 000,Opcode for BEQ = 1100011
32 bits instruction :
0 000000 00000 00000 000 1111 0 1100011

12.<b>LW r13,r1,2</b>
It is I-type instruction set.
The "lw" (load word) instruction is used to load a word from memory into a register. 
rd =r13=01101
rs1 = r1=00001
imm[11:0]= 2 =000000000010 
funct3 = 010, opcode for lw= 0000011 
32 bit instruction:
000000000010 00001  010 01101  0000011 
