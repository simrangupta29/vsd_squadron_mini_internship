# <b>TASK-4</b>
<b>SPIKE AND PROXY KERNEL</b> 			

> * **1.Spike:** _Spike is an open-source RISC-V simulator, which implements a functional model of RISC-V. Spike supports all the extensions supported by the RISC-V ISA.Spike simulates the execution of RISC-V programs on a virtual RISC-V processor. It allows developers to test their RISC-V code, debug it, and analyze its performance without needing physical RISC-V hardware._				

> * **2.Proxy Kernel (pk):** _Proxy kernels are typically, focuses on the core functionalities necessary for running user-space programs.It acts as a bridge between user-level applications and the underlying hardware, providing essential operating system services such as process management, memory management, and I/O handling._

 		

WE can the run these commands using VDI too which has preinstalled softwares in virtual box.</br>   


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
> * lui a0, 0x21:_This instruction loads the immediate value 0x21 into the upper bits of register a0, effectively setting the lower 12 bits to zero.After executing this
 instruction, register a0 will contain the value 0x0000000021000000_
> * addi sp, sp, -16:_ This instruction subtracts 16 from the stack pointer, effectively allocating 16 bytes of space on the stack.Before executing this instruction, the stack pointer (sp) 0x0000003ffffffb50.
 After executing addi sp, sp, -16, 16 is subtracted from the value in the stack pointer.Now, the sp has 0x0000003ffffffb40
