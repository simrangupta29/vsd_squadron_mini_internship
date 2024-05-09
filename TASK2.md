# TASK-2
<b> ABOUT RISC-V ARCHITECTURE </b>

>* RISC-V is an open, versatile instruction-set architecture supporting diverse implementations.</br>
RISC-V is the first widely accepted open-source RISC processor.</br>
It features a base integer ISA, optional extensions, 32/64-bit variants, IEEE-754 floating-point support, and facilitates experimentation with privileged architectures, hypervisors, and parallel computing.

<b> INSTRUCTION SET IN RISCV:- </b>
The RISC-V instruction set is known as RV32I (RISC-V 32-bit integer only) only has 40 instructions. The ISA ( instruction set architecure ) has two sources and one 
destination operands.</br>

<b>RISCV OPERANDS LOCATION</b>
>* **1.REGISTER-** _The fastest and most often used operand is from or to registers on the CPU chip itself. RISC-V RV32I has 32 32-bit registers. 32 registers 
means the instruction must use 3 x 5-bit = 15 bit of the 32-bit instruction._

>* **2.MEMORY-** _The instruction must specify the data memory address, using a register as a pointer._
 
>* **3.CONSTANTS(IMMEDIATES)-** _The third is from instruction memory, i.e. the operand is a constant within  the instruction itself, this is also called an immediate._

<b>The format of the instructions are divided into only six different types</b></br>
</br>
<b>1.R-type (Register/register)</b>:-These are instructions use only registers as source and 
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



<b>2.I-type (Immediate)</b>:-These are instructions has one of the two source operands specified 
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
 
 <b>3.S-type (Store)</b> :-These instructions are exclusively used for storing contents of a 
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

<b>4.B-type (Branch):-</b>These instructions are used to control program flow. It compares 
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

<b>5.J-type (Jump)</b>:-These instructions are used for subroutine calls.</br>

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
<b> ANALYSING SOME OF THE INSTRUCTIONS WITH MACHINE CODE</b></br>

```
1.ADD R6,R2,R1
```

<b>It is R-type instruction.ADD is a typical ALU instruction in the class of 
arithmatic and logic operations. It needs two source operands and one destination operands to store the results.</br>
rs1=r2=00010,rs2=r1 = 00001</br>
rd: =r6=r1+r2= 00110</br>
The operation is specified with the opcode, funct3 and funct7 fields of the instructions.</br> 
opcode =0110011 funct3 = 000, funct7 = 0000000</br>
32 bit instruction(funct7 rs2 rs1 fun3 rd opcode )</br>
0000000 00001 00010 000 00110 0110011</b></br>

```
2.SUB R7, R1, R2
```

<b>It is R-type instruction.SUB is a typical ALU instruction in the class of 
arithmatic and logic operations. It needs two source operands and one destination 
operands to store the results.</br>
rs1=r1=00001,rs2=r2 = 00010</br>
rd: =r7=rs1-rs2= 00111</br>
The operation is specified with the opcode, funct3 and funct7 fields of the instructions. </br>
opcode =0110011 funct3 = 000, funct7 =  0100000</br>
32 bit instruction(funct7 rs2 rs1 fun3 rd opcode )</br>
0000000 00010 00001 000 00111  0100000</b></br>

```
3.AND R8, R1, R3
```
<b>This instruction belongs to R-type instruction set.
r8 will hold the value of r1 & r3, having bitwise and</br>
rd = r8 = 01000</br>
rs1 = r1 = 00001</br>
rs2 = r3 = 00011</br>
The operation is specified with the opcode, funct3 and funct7 fields of the instructions. </br>
Opcode for AND = 0110011,func3 = 111,func7 = 0000000</br>
32 bits instruction :</br>
0000000 00011 00001 111 01000 0110011</b></br>

```
4.OR R9,R2,R5
```
<b>It is also an R-type instruction.</br>
rd = r9=01001</br>
rs1 = r2=00010 ,rs2= r5:00101</br> 
funct3 = 110 ,funct7 = 0000000 ,opcode: 0110011</br>
The operation is specified with the opcode, funct3 and funct7 fields of the instructions. </br>
32 bits instruction :</br>
0000000 00101 00010 110 01001 0110011</b></br>

```
5. XOR R10, R1, R4
```
<b>It is R-type instruction set.</br>
XOR operation bit by bit.</br>
rd = r10 = 01010</br>
rs1 = r1 = 00001</br>
rs2 = r4 = 00100</br>
func3 = 100,func7 = 0000000,Opcode for XOR = 0110011</br>
The operation is specified with the opcode, funct3 and funct7 fields of the instructions. </br>
32 bits instruction :</br>
0000000 00100 00001 100 01010 0110011</b></br>

```
6.SLT R1, R2, R4
```
<b>It is R-type instruction set.</br>
rd = r1 = 00001</br>
rs1 = r2 = 00010</br>
rs2 = r4 = 00100</br>
func3 = 010,func7 = 0000000,Opcode for SLT = 0110011</br>
The operation is specified with the opcode, funct3 and funct7 fields of the instructions. </br>
32 bits instruction :</br>
0000000 00100 00010 010 00001 0110011</b></br>

```
7.ADDI R12, R4, 5
```
<b>It is I-type instruction set.</br>
rd = r12 =r4+5= 01100</br>
rs1 = r4 = 00100</br>
imm[11:0] = 5 = 000000000101</br>
func3 = 000, Opcode for ADDI = 0010011</br>
32 bits instruction :</br>
000000000000101 00100 000 01100 0010011</b></br>

```
8.SW R3, R1, 2
```
<b>It is S-type instruction set.</br>
r3 is the source register.</br> 
rs2 = r3 = 00011</br>
rs1 = r1 = 00001</br>
imm[11:0] = 2 = 000000000010</br>
func3 = 010,Opcode for SW = 0100011</br>
32 bits instruction : </br>
0000000 00011 00001 010 00010 0100011</b></br>

```
9.SRL R16, R14, R2
```
<b>SRL stands for Logical Shift Right.It is S-type instruction set.</br>
r16 is the destination register</br>
rd = r16 = 10000</br>
rs1 = r14 = 01110</br>
rs2 = r2 = 00010</br>
func3 = 101,func7 = 0000000,Opcode for SRL = 0110011</br>
32 bits instruction : 0000000 00010 01110 101 10000 0110011</b></br>

```
10.BNE R0, R1, 20
```
<b>BNE is a B-type instruction . In BNE, the value stored in r0 !=  the value stored in r1.</br>
If the condition is true, PC = PC + 20, elsePC= PC + 4 </br>
rs1 = r0 = 00000</br>
rs2 = r1 = 00001</br>
imm[12:1] = 20 = 000000010100</br>
func3 = 001,Opcode for BNE = 1100011</br>
32 bits instruction :</br>
0 000001 00001 00000 001 0100 0 1100011</b></br>

```
11.BEQ R0, R0, 15
```
<b>BEQ is a B-type instruction. In BEQ,the value stored in r0 == the value stored in r0. </br>
If the condition is true, PC= PC + 15, else PC=PC+4</br>
rs1 = r0 = 00000</br>
rs2 = r0 = 00000</br>
Imm[12:1] = 000000001111</br>
func3 = 000,Opcode for BEQ = 1100011</br>
32 bits instruction :</br>
0 000000 00000 00000 000 1111 0 1100011</b></br>

```
12.LW R13,R1,2
```
<b>It is I-type instruction set.</br>
The "lw" (load word) instruction is used to load a word from memory into a register. </br>
rd =r13=01101</br>
rs1 = r1=00001</br>
imm[11:0]= 2 =000000000010 </br>
funct3 = 010, opcode for lw= 0000011 </br>
32 bit instruction:</br>
000000000010 00001  010 01101  0000011 </b>
</br>
