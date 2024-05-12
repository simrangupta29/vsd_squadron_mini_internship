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
