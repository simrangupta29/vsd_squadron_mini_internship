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

