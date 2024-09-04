#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#define LED1 GPIOD, GPIO_Pin_12
#define LED2 GPIOD, GPIO_Pin_13
#define LED3 GPIOD, GPIO_Pin_14
#define LED4 GPIOD, GPIO_Pin_15
#define button GPIOA, GPIO_Pin_0
int a, b, c, d ;
GPIO_InitTypeDef GPIO_InitStruct;
static void GPIO_setup(void)
{RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_15 | GPIO_Pin_14 | GPIO_Pin_13 | GPIO_Pin_12; // we want to configure all LED GPIO pins
		GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT; 		// we want the pins to be an output
		GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz; 	// this sets the GPIO modules clock speed
		GPIO_InitStruct.GPIO_OType = GPIO_OType_PP; 	// this sets the pin type to push / pull (as opposed to open drain)
		GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL; 	// this sets the pullup / pulldown resistors to be inactive
		GPIO_Init(GPIOD, &GPIO_InitStruct);
}

static void button_setup(void)
{RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;		  // we want to configure PA0
		GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN; 	  // we want it to be an input
		GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;//this sets the GPIO modules clock speed
		GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;   // this sets the pin type to push / pull (as opposed to open drain)
		GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_DOWN;   // this enables the pulldown resistor --> we want to detect a high level
		GPIO_Init(GPIOA, &GPIO_InitStruct);
}
int main(void){
	GPIO_setup();
	button_setup();
	GPIO_ResetBits(GPIOD, GPIO_Pin_12 | GPIO_Pin_13 |GPIO_Pin_14 |GPIO_Pin_15 );

while(1)
{

loop:	if(GPIO_ReadInputDataBit(button == 1)  ) //Ambil Data Bit Button
		{a++;

			while(GPIO_ReadInputDataBit(button == 1)) //Selama Belum Dilepas Loop Terus
			{}
		}

	if (a==1)
		{GPIO_SetBits(LED1); // LED1 ON
		GPIO_ResetBits(GPIOD,  GPIO_Pin_13 |GPIO_Pin_14 |GPIO_Pin_15 ); //LED off
		}

	if (a==2)
			{GPIO_SetBits(LED2); // LED1 ON
			GPIO_ResetBits(GPIOD,  GPIO_Pin_12 |GPIO_Pin_14 |GPIO_Pin_15 ); //LED off
			}
	if (a==3)
				{GPIO_SetBits(LED3); // LED1 ON
				GPIO_ResetBits(GPIOD,  GPIO_Pin_12 |GPIO_Pin_13 |GPIO_Pin_15 ); //LED off
				}
	if (a==4)
				{GPIO_SetBits(LED4); // LED1 ON
				GPIO_ResetBits(GPIOD,  GPIO_Pin_12 |GPIO_Pin_13 |GPIO_Pin_14 ); //LED off
				}
	if (a==5)
	{a=1;}
}




}
