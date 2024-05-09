# VSD SQUADRON MINI INTERNSHIP
Mini summer internship under VLSI SYSTEM DESIGN on RISCV-Architecture and about open source eda tools.
</br>
# TASK-1
<b>INSTALLATION OF VIRTUAL BOX AND SETTING UP UBUNTO.</b>

>* We use Oracle VM VirtualBox to run Ubuntu in order to utilize the RISC-V toolchain. The RISC-V instruction set architecture (ISA) is open-source and widely supported in the Linux environment.

# RISCV-Toolchain

>* The RISC-V toolchain, which includes compilers, assemblers, linkers, and other development tools, is primarily developed and maintained for Linux-based operating systems like Ubunto.

This is the RISC-V C and C++ cross-compiler. It supports two build modes: a generic ELF/Newlib toolchain and a more sophisticated Linux-ELF/glibc toolchain.</br>
These are the commands for installation of riscv Toolchain:-
```
$ sudo apt-get install autoconf automake autotools-dev curl python3 python3-pip libmpc-dev libmpfr-dev libgmp-dev gawk build-essential bison flex texinfo gperf libtool patchutils bc zlib1g-dev libexpat-dev ninja-build git cmake libglib2.0-dev libslirp-dev
$git clone -- recursive https://github.com/riscv/riscv-gnu-toolchain 
$./configure --prefix=/opt/riscv
$ make linux
$ sudo make linux
```

![intern_riscv](https://github.com/simrangupta29/vsd_squadron_mini_internship/assets/130252328/d3cf31fe-2712-4d0d-ad97-b394c5498b41)

# YOSYS

>* Yosys is an open-source synthesis tool for Verilog RTL (Register Transfer Level) synthesis. It's primarily used for digital synthesis, transforming high-level Verilog code into a netlist of logical gates that represent the desired functionality of a digital circuit.

These are the commands for installation of yosys.
```
$ git clone https://github.com/YosysHQ/yosys.git
$ cd yosys
$ sudo apt install make (If make is not installed please install it)
$ sudo apt-get install build-essential clang bison flex
    libreadline-dev gawk tcl-dev libffi-dev git
    graphviz xdot pkg-config python3 libboost-system-dev
    libboost-python-dev libboost-filesystem-dev zlib1g-dev
$ make config-gcc
$ make 
$ sudo make install
```
![intern_yosys](https://github.com/simrangupta29/vsd_squadron_mini_internship/assets/130252328/a562fb43-7d69-4e0c-b9c6-cd00f0c9dc0f)

# IVERILOG
>*Icarus Verilog (IVerilog) is an open-source hardware description language (HDL) simulator.It compiles the Verilog/SystemVerilog code and produces a simulation executable that simulates the behavior of the described hardware.

These are the commands for installation of iverilog.
```
$sudo apt-get install iverilog
```
![intern_verilog](https://github.com/simrangupta29/vsd_squadron_mini_internship/assets/130252328/99574331-89fb-4484-ae07-7ef634dfb823)

# GTKWARE
>* GTKWave is a waveform viewer that works in conjunction with simulation tools like Icarus Verilog. It supports various input formats, including VCD (Value Change Dump) files generated by Verilog/SystemVerilog simulators.

These are the commands for installation of yosys.
```
$sudo apt update
$sudo apt install gtkwave
```
![intern_gitkware](https://github.com/simrangupta29/vsd_squadron_mini_internship/assets/130252328/533e8301-6589-47dc-a309-4882c1bc80af)

# TASK-2
<b> ABOUT RISC-V ARCHITECTURE </b>

>* RISC-V is an open, versatile instruction-set architecture supporting diverse implementations.</br>
RISC-V is the first widely accepted open-source RISC processor.</br>
It features a base integer ISA, optional extensions, 32/64-bit variants, IEEE-754 floating-point support, and facilitates experimentation with privileged architectures, hypervisors, and parallel computing.

<b> INSTRUCTION SET IN RISCV </b>
The RISC-V instruction set is known as RV32I (RISC-V 32-bit integer only) only has 40 instructions. The ISA ( instruction set architecure ) has two sources and one 
destination operands.</br>

<b>RISCV OPERANDS LOCATION</b>
>* **1.REGISTER-** _The fastest and most often used operand is from or to registers on the CPU chip itself. RISC-V RV32I has 32 32-bit registers. 32 registers 
means the instruction must use 3 x 5-bit = 15 bit of the 32-bit instruction._

>* **2.MEMORY-** _The instruction must specify the data memory address, using a register as a pointer._
 
>* **3.CONSTANTS(IMMEDIATES)-** _The third is from instruction memory, i.e. the operand is a constant within  the instruction itself, this is also called an immediate._

<b>The format of the instructions are divided into only six different types</b></br>
</br>
<b>1.R-type (Register/register)</b>:These are instructions use only registers as source and 
destiantions. This instruction type is mostly used for arithmetic and logic 
operations involving the ALU.</br>

| Column 1 | Column 2 | Column 3 | Column 4 | Column 5 | Column 6 | Column 7 |
|----------|----------|----------|----------|----------|----------|----------|
| INSTRUCTION TYPE   |     [25-31]           |  [20-24]  | [15-19]    | [12-14] | [7-11]  | [0-6]     |
| Register  | function7     | rs2     | rs1   | function3     |   rd     |  opcode    |

</br>

 >* opcode (7): partially specifies operation.e.g. R-types have opcode = 0b0110011. </br>
funct7+funct3 (10): combined with opcode, these two fields describe what operation to perform .</br>
rs1 (5): 1st operand (“source register 1”).</br>
rs2 (5): 2nd operand (second source register). </br>
rd (5): “destination register” — receives the result of computation .</br>
 We know that RISCV has 32 registers </br> A 5 bit field can represent exactly 25 = 32 things  
(interpret as the register numbers x0-x31).</br>



<b>2.I-type (Immediate)</b>:These are instructions has one of the two source operands specified 
within the 32-bit instruction word as a 12-bit constant (or immediate). This 
constant is regards as 12-bit signed 2’s complement number, which is always 
sign extended to form a 32-bit operand</br>.
</br>

| Column 1 | Column 2            | Column 3 | Column 4 | Column 5 | Column 6 |
|----------|---------------------|----------|----------|----------|----------|
|INSTRUCTION TYPE     |        [20-31]         | [15-19]     |  [12-14]    | [7-11]     | [0-6]     |
| Immediates     | imm[11:0]                | rs1      | function3     | rd     | opcode     |

</br>

 >* Opcode (7): uniquely specifies the instruction</br>
 rs1 (5): specifies a register operand</br>
 rd (5): specifies destination register that receives result of computation</br>
 immediate (12): 12 bit number– All computations done in words, so 12-bit immediate must be extended to 32 bits</br>
                              – always sign-extended to 32-bits before use in an arithmetic operation</br>
 imm[11:0] can hold values in range [-211 , +211]</br>
 </br>
 
 <b>3.S-type (Store)</b> :These instructions are exclusively used for storing contents of a 
register to data memory. </br>


| Column 1 | Column 2 | Column 3 | Column 4 | Column 5 | Column 6 | Column 7 |
|----------|----------|----------|----------|----------|----------|----------|
| INSTRUCTION TYPE   |     [25-31]           |  [20-24]  | [15-19]    | [12-14] | [7-11]  | [0-6]     |
| Register  |  imm[11:5]      | rs2     | rs1   | function3     |   imm[4:0]      |  opcode    |

</br>

>* Store needs to read two registers, rs1 for base memory address, and rs2 for data to be stored, as well as need immediate offset.</br>
 Can’t have both rs2 and immediate in same place as other instructions.</br>
 Note: stores don’t write a value to the register file, no rd!</br>
 RISC-V design decision is move low 5 bits of immediate to where rd field was in other instructions – keep rs1/rs2 fields in same place</br>
 
</br>

<b>4.B-type (Branch)</b>These instructions are used to control program flow. It compares 
two operands stored in registers and branch to a destination address relative 
to the current Program Counter value. </br>


| Column 1 | Column 2 | Column 3 | Column 4 | Column 5 | Column 6 | Column 7 |
|----------|----------|----------|----------|----------|----------|----------|
| INSTRUCTION TYPE   |     [25-31]           |  [20-24]  | [15-19]    | [12-14] | [7-11]  | [0-6]     |
| Register  |  imm[12] , imm[10:5]      | rs2     | rs1   | function3     |    imm[4:0] ,imm[11]    |  opcode    |

</br>

>*B-format is mostly same as S-Format, with two register sources (rs1/rs2) and a 12-bit immediate</br>
The 12 immediate bits encode even 13-bit signed byte offsets (lowest bit of offset is always zero, so no need to store it</br>
It checks the condition between Rs1 and Rs2,if condition is true:</br>
pc=pc+immediate value(incrementing the pc) and jump to next address based on offset value</br>
if condition is false:</br>
pc=pc+4(which execute next input)</br>

</br>

<b>5.J-type (Jump)</b>:These instructions are used for subroutine calls.</br>

| Column 1 | Column 2          | Column 3          | Column 4 | Column 5 |
|----------|-------------------|-------------------|----------|----------|
|  INST TYPE  | [20-31]               |   [12-19]           |   [7-11]    | [0-6]    |
| U-TYPE    |      imm[20] , imm[10:1] ,imm[11]      |  imm[19:12]            | rd     | Opcode     |

</br>

>* The J-type instruction has instruction like JAL.It encodes 20 bits signed immediate</br>
The address of the desired memory location for jump is defined in the instruction.</br> 
jal saves PC+4 in register rd (the return address)<br>
 Set PC = PC + offset (PC-relative jump<br>
 
</br>
 <b>6.U-type (Upper immediate)</b>:-These instructions are used to specify the upper 20 bits immediate value of a register</br>

| Column 1 | Column 2             | Column 3 | Column 4 |
|----------|----------------------|----------|----------|
|  INST TYPE  | [12:31]                | [7-11 ]    | [0-6]    |
|  U-TYPE   | imm[12:31]                | rd    | opcode    |

>* This instruction should deal with:</br>
-the immediate of 20 bits</br>
-the instruction opcode</br>
-One destination register, rd</br>
 Used for two instructions</br>
 LUI – Load Upper Immediate</br>
AUIPC – Add Upper Immediate to PC</br>

</br>
# ANALYSING SOME OF THE INSTRUCTIONS WITH MACHINE CODE
1. <b>add r6,r2,r1</b></br>
It is R-type instruction.ADD is a typical ALU instruction in the class of 
arithmatic and logic operations. It needs two source operands and one destination operands to store the results.</br>
rs1=r2=00010,rs2=r1 = 00001</br>
rd: =r6=r1+r2= 00110</br>
The operation is specified with the opcode, funct3 and funct7 fields of the instructions.</br> 
opcode =0110011 funct3 = 000, funct7 = 0000000</br>
32 bit instruction(funct7 rs2 rs1 fun3 rd opcode )</br>
0000000 00001 00010 000 00110 0110011</br>

2.<b>SUB r7, r1, r2</b></br>
It is R-type instruction.SUB is a typical ALU instruction in the class of 
arithmatic and logic operations. It needs two source operands and one destination 
operands to store the results.</br>
rs1=r1=00001,rs2=r2 = 00010</br>
rd: =r7=rs1-rs2= 00111</br>
The operation is specified with the opcode, funct3 and funct7 fields of the instructions. </br>
opcode =0110011 funct3 = 000, funct7 =  0100000</br>
32 bit instruction(funct7 rs2 rs1 fun3 rd opcode )</br>
0000000 00010 00001 000 00111  0100000</br>


3.<b>AND r8, r1, r3</b></br>
This instruction belongs to R-type instruction set.
r8 will hold the value of r1 & r3, having bitwise and</br>
rd = r8 = 01000</br>
rs1 = r1 = 00001</br>
rs2 = r3 = 00011</br>
The operation is specified with the opcode, funct3 and funct7 fields of the instructions. </br>
Opcode for AND = 0110011,func3 = 111,func7 = 0000000</br>
32 bits instruction :</br>
0000000 00011 00001 111 01000 0110011</br>

4.<b>OR r9,r2,r5</b></br>
It is also an R-type instruction.</br>
rd = r9=01001</br>
rs1 = r2=00010 ,rs2= r5:00101</br> 
funct3 = 110 ,funct7 = 0000000 ,opcode: 0110011</br>
The operation is specified with the opcode, funct3 and funct7 fields of the instructions. </br>
32 bits instruction :</br>
0000000 00101 00010 110 01001 0110011</br>

5.<b> XOR r10, r1, r4</b></br>
It is R-type instruction set.</br>
XOR operation bit by bit.</br>
rd = r10 = 01010</br>
rs1 = r1 = 00001</br>
rs2 = r4 = 00100</br>
func3 = 100,func7 = 0000000,Opcode for XOR = 0110011</br>
The operation is specified with the opcode, funct3 and funct7 fields of the instructions. </br>
32 bits instruction :</br>
0000000 00100 00001 100 01010 0110011</br>

6.<b>SLT r1, r2, r4</b></br>
It is R-type instruction set.</br>
rd = r1 = 00001</br>
rs1 = r2 = 00010</br>
rs2 = r4 = 00100</br>
func3 = 010,func7 = 0000000,Opcode for SLT = 0110011</br>
The operation is specified with the opcode, funct3 and funct7 fields of the instructions. </br>
32 bits instruction :</br>
0000000 00100 00010 010 00001 0110011</br>

7.<b>ADDI r12, r4, 5</b></br>
It is I-type instruction set.</br>
rd = r12 =r4+5= 01100</br>
rs1 = r4 = 00100</br>
imm[11:0] = 5 = 000000000101</br>
func3 = 000, Opcode for ADDI = 0010011</br>
32 bits instruction :</br>
000000000000101 00100 000 01100 0010011</br>

8.<b>SW r3, r1, 2</b></br>
It is S-type instruction set.</br>
r3 is the source register.</br> 
rs2 = r3 = 00011</br>
rs1 = r1 = 00001</br>
imm[11:0] = 2 = 000000000010</br>
func3 = 010,Opcode for SW = 0100011</br>
32 bits instruction : </br>
0000000 00011 00001 010 00010 0100011</br>

9.<b>SRL r16, r14, r2</b></br>
SRL stands for Logical Shift Right.It is S-type instruction set.</br>
r16 is the destination register</br>
rd = r16 = 10000</br>
rs1 = r14 = 01110</br>
rs2 = r2 = 00010</br>
func3 = 101,func7 = 0000000,Opcode for SRL = 0110011</br>
32 bits instruction : 0000000 00010 01110 101 10000 0110011</br>

10.<b>BNE r0, r1, 20</b></br>
BNE is a B-type instruction . In BNE, the value stored in r0 !=  the value stored in r1.</br>
If the condition is true, PC = PC + 20, elsePC= PC + 4 </br>
rs1 = r0 = 00000</br>
rs2 = r1 = 00001</br>
imm[12:1] = 20 = 000000010100</br>
func3 = 001,Opcode for BNE = 1100011</br>
32 bits instruction :</br>
0 000001 00001 00000 001 0100 0 1100011</br>

11.<b>BEQ r0, r0, 15</b></br>
BEQ is a B-type instruction. In BEQ,the value stored in r0 == the value stored in r0. </br>
If the condition is true, PC= PC + 15, else PC=PC+4</br>
rs1 = r0 = 00000</br>
rs2 = r0 = 00000</br>
Imm[12:1] = 000000001111</br>
func3 = 000,Opcode for BEQ = 1100011</br>
32 bits instruction :</br>
0 000000 00000 00000 000 1111 0 1100011</br>

12.<b>LW r13,r1,2</b></br>
It is I-type instruction set.</br>
The "lw" (load word) instruction is used to load a word from memory into a register. </br>
rd =r13=01101</br>
rs1 = r1=00001</br>
imm[11:0]= 2 =000000000010 </br>
funct3 = 010, opcode for lw= 0000011 </br>
32 bit instruction:</br>
000000000010 00001  010 01101  0000011 
</br>

# TASK-3

<b>LAB BASED TASK</br>
C program to calculate sum of n natural numbers</b></br>
Open the terminal and give this command to open leafpad which is an editor.</br>
```
 $leafpad sum1ton.c
```
If it is not installed,install it using below command.
```
 $sudo install leafpad.
```
Write  the c program in leafpad editor to calculate sum of n natural numbers and save it.</br>
![intern_task3_1](https://github.com/simrangupta29/vsd_squadron_mini_internship/assets/130252328/692130e7-4732-45ac-a7e3-257a0b57b1eb)</br>
```
 $gcc sum1ton.c 
$ ./a.out
```
>* Running the command "gcc sum1ton.c" in a terminal would compile the C source file "sum1ton.c" using the GNU Compiler Collection (GCC). If successful, it would generate an executable file named "a.out" by default.

![intern_task3_2](https://github.com/simrangupta29/vsd_squadron_mini_internship/assets/130252328/11b8bc1c-05d3-4085-998f-f73d6b57ce43) </br>
Change the value of n to 100 in the editor and again run the command for output.</br>
![intern_task3_3](https://github.com/simrangupta29/vsd_squadron_mini_internship/assets/130252328/36a4129b-3090-47ee-9376-eb5ddc650c94) </br>
![intern_task3_4](https://github.com/simrangupta29/vsd_squadron_mini_internship/assets/130252328/08f52872-e733-4969-b99d-4c48e90e4ba0) </br>
</br>
<b>TO RUN THE SAME PROGRAM USING RISCV GCC COMPILER & SIMULATOR</b></br>

>* The RISC-V GCC compiler is part of the GNU Compiler Collection (GCC) suite, adapted to target the RISC-V instruction set architecture (ISA). It allows developers to compile C, C++, and other languages into machine code that can run on RISC-V-based processors.

WE can the run these commands using VDI too which has preinstalled softwares in virtual box.</br>
Give command to open the C program in terminal
```
$ cat sum1ton.c.
```
 ![vsd_4](https://github.com/simrangupta29/vsd_squadron_mini_internship/assets/130252328/e701a9d8-1b78-40cc-b3ac-2ce7a8d1c818)
 </br>
Give command :-
```
$ riscv64-unknown-elf-gcc-o1 -mabi=lp64 -march=rv64i -o sum1ton.o sum1ton.c
```
>* This command is compiling a C source file named "sum1ton.c" into an object file named "sum1ton.o" using the RISC-V GCC compiler with optimization level 1 (-O1), specifying the Application Binary Interface (ABI) as LP64 (-mabi=lp64), and the target architecture as RV64I (-march=rv64i).

>* **-mabi=ilp32:** _This option specifies the ABI (Application Binary Interface) to use ilp32, which is for a 32-bit integer, long, and pointer size. This ABI is used for 32-bit 
    RISC-V architectures._

>* **-march=rv32i:** _This option specifies the architecture to use rv32i, which indicates a 32-bit RISC-V base integer instruction set. This further confirms the targeting of a 32- bit architecture._
>* **-riscv64:**_allows to  target any 32-bit or 64-bit architecture._

Go to another tab and give command:-
```
$ riscv64-unknown-elf-objdump -d sum1ton.o
```
It will give a bunch of assembly language code.

>* The command riscv64-unknown-elf-objdump -d sum1ton.o tells the objdump utility, customized for the RISC-V architecture, to disassemble the contents of the sum1ton.o object file and display the resulting assembly language instructions.

Search for main address in that assembly language code. </br>
Main address starts from 10184 in hex and ends at 101ec in hex which means it has 27 instructions.

![vdi_2](https://github.com/simrangupta29/vsd_squadron_mini_internship/assets/130252328/e7808211-8835-4278-ad84-021ed65b52de)
</br>

In the previous tab, instead of give command following command:-
```
$ riscv64-unknown-elf-gcc-ofast -mabi=lp64 -march=rv64i -o sum1ton.o sum1ton.c    
```
In the second tab run the same command
```
$ riscv64-unknown-elf-objdump -d sum1ton.c | less    
```
>* The options -Ofast and -O1 in GCC represent different levels of optimization, where -Ofast is a higher optimization level compared to -O1.
-Ofast is a high optimization level that enables aggressive optimizations for maximum performance, sacrificing strict adherence to language standards and precision in floating-point arithmetic if necessary. On the other hand, -O1 is a lower optimization level that provides basic optimizations while maintaining code correctness and adherence to language standards.

Search for main address in that assembly language code </br>
<b>This time main starts from 10184 in hex and ends at 101ac in hex which means it has 11 instructions.</b> </br>
![WhatsApp Image 2024-05-02 at 10 47 57_dbb39ad5](https://github.com/simrangupta29/vsd_squadron_mini_internship/assets/130252328/195bab90-8306-4098-9a75-a2e8f6ac553e)
  </br>


# <b>TASK-4</b>
<b>SPIKE AND PROXY KERNEL</b> 			

> * **1.Spike:** _Spike is an open-source RISC-V simulator, which implements a functional model of RISC-V. Spike supports all the extensions supported by the RISC-V ISA.Spike simulates the execution of RISC-V programs on a virtual RISC-V processor. It allows developers to test their RISC-V code, debug it, and analyze its performance without needing physical RISC-V hardware._				

> * **2.Proxy Kernel (pk):** _Proxy kernels are typically, focuses on the core functionalities necessary for running user-space programs.It acts as a bridge between user-level applications and the underlying hardware, providing essential operating system services such as process management, memory management, and I/O handling._

 		

WE can run these commands using VDI too which has preinstalled softwares in virtual box.</br>   


First compiled and got output using gcc as we did in task3 
```
$ riscv64-unknown-elf-gcc -Ofast -mabi=lp64 -march=rv64i -o sum1ton.o sum1ton.c
$ gcc sum1ton.c
$ ./a.out   
```

![task4_1](https://github.com/simrangupta29/vsd_squadron_mini_internship/assets/130252328/6081b6b7-9f3c-4004-bb9d-08b5c535d12c)

 Getting Output using spike**
```
$ spike pk sum1ton.o
```

![task4_2](https://github.com/simrangupta29/vsd_squadron_mini_internship/assets/130252328/b8efe6f6-6fa3-4a23-a1fc-f4353d07b052)

Disassemble the contents of the sum1ton.o object
```
$ riscv64-unknown-elf-objdump -d sum1ton.o | less
```

![task4_3](https://github.com/simrangupta29/vsd_squadron_mini_internship/assets/130252328/12ff8f39-e68e-4994-9da3-10ffb24d81ee)

Simulating and Debugging using spike and proxy kernel 
```
$ spike -d pk sum1ton.o
```
![task4_4](https://github.com/simrangupta29/vsd_squadron_mini_internship/assets/130252328/ea850ee5-7d5c-48fd-9825-eb7f2b875720)


<b>DEBUGGING</b></br>
</br>
spike -d pk sum1ton.o is a command used to simulate the execution of a RISC-V program represented by the binary file sum1ton.o and the proxy kernel, enables debug mode for detailed analysis and debugging.</br>
</br>
> * until pc 0 100b0:_ In the Spike RISC-V simulator,it instructs the simulator to execute instructions until the program counter (pc) reaches the address 100b0._
> * reg 0 a0:_This command is often used during debugging sessions to inspect the state of registers at various points during program execution._
> * lui a0, 0x21:_This instruction loads the immediate value 0x21 into the upper bits of register a0, effectively setting the lower 12 bits to zero.After executing this instruction, register a0 will contain the value 0x0000000021000000_
> * addi sp, sp, -16:_ This instruction subtracts 16 from the stack pointer, effectively allocating 16 bytes of space on the stack.Before executing this instruction, the stack pointer (sp) 0x0000003ffffffb50. After executing addi sp, sp, -16, 16 is subtracted from the value in the stack pointer.Now, the sp has 0x0000003ffffffb40


# <b>TASK-5</b>
<b>Functional simulation experiment using RISC-V Core Verilog netlist and testbench.</b> 

> * **1.IVERILOG:** _Icarus Verilog (IVerilog) is an open-source hardware description language (HDL) simulator.It compiles the Verilog/SystemVerilog code and produces a simulation executable that simulates the behavior of the described hardware._
> * **2.GTKWAVE:-** _GTKWave is a waveform viewer that works in conjunction with simulation tools like Icarus Verilog. It supports various input formats, including VCD (Value Change Dump) files generated by Verilog/SystemVerilog simulators._

First created the verilog file and its testbench file in my github repository and cloned it to the machine using following command.
> * **VERILOG CODE:-** _The code implements a pipelined RV32I processor with basic arithmetic, logic, load/store, and branch instructions.</br>
It supports instructions like ADD, SUB, AND, OR, XOR, SLT, ADDI, SUBI, ANDI, ORI, XORI, LW, SW, BEQ, BNE, SLL, and SRL.</br>
The processor consists of the IF, ID, EX, MEM, and WB pipeline stages.</br>
It fetches instructions from memory, decodes them, executes them, accesses memory if necessary, and writes back the results.</br>
Branch instructions are supported, with branch conditions evaluated during the execution stage._

```
$  git clone https://github.com/simrangupta29/vsd_squadron_mini_internship
$ cd vsd_squadron_mini_internship
```
Simulate and run the verilog code , using the following commands in terminal.

```
$ iverilog -o vsd_squadron_mini_internship simran_rv32i.v simran_rv32i_tb.v
$ ./vsd_squadron_mini_internship
```

To see the output waveform in gtkwave, enter the following commands in the terminal.
```
$ gtkwave simran_rv32i.vcd
```
![verilog](https://github.com/simrangupta29/vsd_squadron_mini_internship/assets/130252328/fcafa177-27f2-44a7-8214-f1004cda8d1b)

<b>The instructions which are to be simulate are:-</b>

![Screenshot (558)](https://github.com/simrangupta29/vsd_squadron_mini_internship/assets/130252328/3007623d-0d62-4e13-aa9a-84ab4a5d1b70)

<b>Now Let's anaylze wave form of each instruction using gtkwave.</b>
```
1. ADD R6,R2,R1
```
![WhatsApp Image 2024-05-09 at 15 21 03_58c86c3c](https://github.com/simrangupta29/vsd_squadron_mini_internship/assets/130252328/e04b571e-05e5-49fa-995a-1eb87491bed7)
</br>
>* As it is shown in the waveform the contents of register R1=1  and register R2=2 are added, and the result which is 1+2=3 is stored in register R6.The hard-corded 32bit ISA for this instruction is 32'h02208300.

```
2:SUB R7,R1,R2
```
![WhatsApp Image 2024-05-09 at 15 20 59_10b4984a](https://github.com/simrangupta29/vsd_squadron_mini_internship/assets/130252328/cf520af0-d96b-4c62-ad19-639c45eae15a)

>* As it is shown in the waveform the contents of register R1=2 are subtracted from the contents of register R2=1, and the result which is 1-2=-1 is stored in register R7.The hard-corded 32bit ISA for this instruction is 32'h02209380.

```
3.AND R8, R1, R3
```
![WhatsApp Image 2024-05-09 at 15 20 59_c1f52b9f](https://github.com/simrangupta29/vsd_squadron_mini_internship/assets/130252328/62c3d9d6-cc43-478d-9e45-3e6a09288481)

>*  As it is shown in the waveform, it performs a bitwise AND operation between the contents of register R1=3(0011) and register R3=1(0001), and stores the result in register R8=1(0001).The hard-corded 32bit ISA for this instruction is 32'h0230a400.

```
4.OR R9, R2, R5
```

![WhatsApp Image 2024-05-09 at 15 21 04_c93bf218](https://github.com/simrangupta29/vsd_squadron_mini_internship/assets/130252328/b07d179c-bdb7-43d1-809d-301c559f663a)

>*  As it is shown in the waveform, it performs a bitwise OR operation between the contents of register R2=2(0010) and register R5=5(0101), and stores the result in register R9=7(0111).The hard-corded 32bit ISA for this instruction is 32'h02513480.


```
5.XOR R10, R1, R4
```

![WhatsApp Image 2024-05-09 at 15 21 00_e30a8b4b](https://github.com/simrangupta29/vsd_squadron_mini_internship/assets/130252328/44583ba2-b4d0-4655-8829-e41c32c85d8c)

>*  As it is shown in the waveform, it performs a bitwise XOR operation between the contents of register R1 and register R4, and stores the result in register R10.The hard-corded 32bit ISA for this instruction is 32'h0240c500.

```
6.SLT R1, R2, R4
```

![WhatsApp Image 2024-05-09 at 15 20 59_df25ada7](https://github.com/simrangupta29/vsd_squadron_mini_internship/assets/130252328/34cc090a-588a-411c-a873-b5a1d9bd76c9)


>*  As it is shown in the waveform, this instruction sets register R1 to 1 if the value in register R2 is less than the value in register R4, and sets it to 0 otherwise.Here R2<R4 so R1=1.The hard-corded 32bit ISA for this instruction is 32'h02415580.


```
7.ADDI R12, R4, 5
```

![WhatsApp Image 2024-05-09 at 15 20 58_df092cd8](https://github.com/simrangupta29/vsd_squadron_mini_internship/assets/130252328/9262b4bc-89ef-4fd4-b820-25d845fb66a9)


>*  As it is shown in the waveform, it adds an immediate value (in this case, 5) to the contents of register R4=4 and stores the result (4+5=9) in register R12.The hard-corded 32bit ISA for this instruction is 32'h00520600.

```
8.SW R3, R1, 2
```

![WhatsApp Image 2024-05-09 at 15 20 59_d12f9fd7](https://github.com/simrangupta29/vsd_squadron_mini_internship/assets/130252328/0ef4defd-6b8d-487c-a0cb-0530625344a6)


>*  As it is shown in the waveform, it stores the contents of register R3 into the memory address calculated by adding the contents of register R1 and the immediate value 2.The hard-corded 32bit ISA for this instruction is 32'h00209181.

```
9.LW R13, R1, 2
```

![WhatsApp Image 2024-05-09 at 15 20 57_6fd51942](https://github.com/simrangupta29/vsd_squadron_mini_internship/assets/130252328/6bbf04d0-a9c7-4276-92ac-d693eb27c8a3)


>*  As it is shown in the waveform, this instruction loads a 32-bit word from the memory address obtained by adding the contents of register R1 and the immediate value 2 into register R13.The hard-corded 32bit ISA for this instruction is 32'h00208681.



```
10.BEQ R0, R0, 15
```

![WhatsApp Image 2024-05-09 at 15 21 00_bbc85928](https://github.com/simrangupta29/vsd_squadron_mini_internship/assets/130252328/c6733030-122c-43f0-95e1-aedeb04047db)


>*  As it is shown in the waveform, it checks the contents of two registers here both are R0.Theyare equal therefore the PC(Program counter)would increment by 15.The hard-corded 32bit ISA for this instruction is 32'h00f00002.
