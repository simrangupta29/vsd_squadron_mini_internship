# <b>TASK-6</b>
<b> Make a mini project on VSD Squadron mini board to understand the board's overview.</b>
# AUTOMATIC LIGHT SYSTEM
An automatic light system is a setup designed to automatically control the lighting based on the presence or absence of individuals within its detection range.
This system will also give the indication of motion detected by blinking the led 3 times.

</br>
<b>COMPONENTS REQUIRED</b>
</br>
<ul>VSD SQUADRON MINI BOARD</ul>
<ul>IR SENSOR</ul>
<ul>LEDS</ul>
<ul>BREAD BOARD</ul>
<ul>USB CABLE</ul>
<ul>JUMPER WIRES</ul>
</br>

<b>PIN DIAGRAM</b>
| IR SENSOR,LED   | VSD SQUADRON BOARD |
| --------------- | --------------- |
| VCC OF IR | 3.2V |
| GND OF IR| GND |
| OUT OF IR | PIN 4 |
| LED | PIN 6 |

</br>
<b> WORKING </b>
<ul>The IR sensor is strategically placed in a location where it can detect the movement of individuals within its sensing range.
</ul>
<ul>The IR sensor continuously monitors its surroundings for any changes in infrared radiation caused by the movement of individuals.</ul>
<ul>When someone enters the detection range of the IR sensor, it detects the change in radiation and triggers an output signal.</ul>
<ul>When the IR sensor detects motion, it sends a signal to the microcontroller which then activates the LED lighting system.
The LED lights up, providing illumination and the led will blink 3 times in the area where motion is detected which gives indication of motion detected. </ul>
</br>

![images_gen](https://github.com/simrangupta29/vsd_squadron_mini_internship/assets/130252328/789ea1b1-b392-40c5-9e63-1956c918358f)

</br>
<b> C CODE </b>

```
//These include the necessary header files (ch32v00x.h and debug.h) for the CH32V microcontroller and debugging purposes.
#include <ch32v00x.h>
#include <debug.h>
//pin configuration
void GPIO_Config(void)
{
GPIO_InitTypeDef GPIO_InitStructure = {0}; //structure variable GPIO_InitStructure of type GPIO_InitTypeDef which is used for GPIO configuration.

RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE); // to Enable the clock for Port D
//pin 4 OUT PIN FOR IR SENSOR
GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 ; // Defines which Pin to configure
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; // Defines Output Type
GPIO_Init(GPIOD, &GPIO_InitStructure);
//pin 6 IS LED PIN
GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 ; //
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; // Defines Output Type
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // Defines speed

GPIO_Init(GPIOD, &GPIO_InitStructure);

}
//main function

int main(void)
{
uint8_t IR = 0;
uint8_t set=1;
uint8_t reset=0;
uint8_t a=0;
NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);// Configuring NVIC priority group
SystemCoreClockUpdate();// Update System Core Clock
Delay_Init();//Initialize Delay
GPIO_Config();//Call GPIO configuration function

while(1)
{
IR = GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_4);
if (IR==1)//Read state of Pin 4 (IR sensor)
{ // for blinking of led three times upon motion detection
	for(a=0;a<3;a++){
GPIO_WriteBit(GPIOD, GPIO_Pin_6, set);
Delay_Ms(200);
GPIO_WriteBit(GPIOD, GPIO_Pin_6,reset);
Delay_Ms(100);}

}

}
}
```

<b>APPLICATIONS</b>
<UL><b>Security Lighting:</b>These systems can be used for security lighting in outdoor spaces, such as gardens, driveways, and pathways, to deter intruders and provide visibility at night.</UL>
<ul><b>Home Automation:</b>Automatic light systems can be installed in homes, particularly in areas such as hallways, staircases, and bathrooms, where lights need to be turned on/off based on occupancy.</ul>
<ul><b>Energy Efficiency:</b>
Automatic light systems contribute to energy conservation by ensuring that lights are not left on unnecessarily when the area is unoccupied.</ul>
<ul><b>Accessibility:</b>These systems can improve accessibility for individuals with disabilities by providing automatic illumination in response to their movement.</ul>

</br>
<b>DEMONSTRATION OF PROJECT</b>


https://github.com/simrangupta29/vsd_squadron_mini_internship/assets/130252328/b6022d54-e2d0-4c81-91ac-ec7a3a7abbd9


# CONCLUSION
During the VSD Squadron mini Internship, I embarked on a journey exploring various aspects of VLSI system design on the RISC-V architecture, alongside open-source EDA tools.</br> 

<b>Installation and Setup:</b> I began by setting up the development environment, including installing VirtualBox for running Ubuntu and configuring the RISC-V toolchain, Yosys, Icarus Verilog, and GTKWave.</br>

<b>Understanding RISC-V Architecture: </b>I delved into the fundamentals of the RISC-V architecture, learning about its open, versatile instruction set, instruction formats, operand types, and various instruction types and their opcodes.</br>

<b>Lab-Based Tasks:</b> Engaging in lab-based tasks, I wrote and compiled C programs, simulated them using RISC-V GCC compiler and Spike, and analyzed the assembly code. You also performed functional simulation experiments using Verilog netlists and testbenches, utilizing Icarus Verilog and GTKWave.</br>

<b>Spike and Proxy Kernel: </b>I explored the Spike simulator and Proxy Kernel, understanding their roles in simulating RISC-V programs and debugging them effectively.

<b>Mini Project :</b> Automatic Light System: As part of my project work, I implemented an automatic light system using the VSD Squadron mini board,</br> IR sensor, and LEDs, wrote C code to control the system, detecting motion with the IR sensor and indicating it through LED illumination.

