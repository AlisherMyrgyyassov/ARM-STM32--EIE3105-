#include "stm32f10x.h"                  // Device header
#include "stdbool.h"

void delay(uint32_t ms);

static __IO uint32_t msTicks;

void all_off(){
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);
		GPIO_WriteBit(GPIOA, GPIO_Pin_1, Bit_RESET);
		GPIO_WriteBit(GPIOA, GPIO_Pin_8, Bit_RESET);
		GPIO_WriteBit(GPIOA, GPIO_Pin_9, Bit_RESET);
		GPIO_WriteBit(GPIOA, GPIO_Pin_4, Bit_RESET);
		GPIO_WriteBit(GPIOA, GPIO_Pin_5, Bit_RESET); //PA5 / D13
		GPIO_WriteBit(GPIOA, GPIO_Pin_6, Bit_RESET);		
		GPIO_WriteBit(GPIOA, GPIO_Pin_7, Bit_RESET);
}
int main(void) {
	//GPIO set up for PA5 (on board LED)
	//Enable APB2 periphral clock
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10;		
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	SystemCoreClockUpdate();
	// Configure the SysTick timer to overflow every 1 ms
	SysTick_Config(SystemCoreClock / 1000);



	while(1) {
		all_off();
		GPIO_WriteBit(GPIOA, GPIO_Pin_1, Bit_SET);
		GPIO_WriteBit(GPIOA, GPIO_Pin_8, Bit_SET);	
		GPIO_WriteBit(GPIOA, GPIO_Pin_7, Bit_SET);
		delay(5000);
		all_off();
		GPIO_WriteBit(GPIOA, GPIO_Pin_1, Bit_SET);
		GPIO_WriteBit(GPIOA, GPIO_Pin_9, Bit_SET);	
		GPIO_WriteBit(GPIOA, GPIO_Pin_7, Bit_SET);
		delay(1000);
		all_off();
		GPIO_WriteBit(GPIOA, GPIO_Pin_1, Bit_SET);
		GPIO_WriteBit(GPIOA, GPIO_Pin_4, Bit_SET);	
		GPIO_WriteBit(GPIOA, GPIO_Pin_7, Bit_SET);
		delay(1000);
		all_off();
		GPIO_WriteBit(GPIOA, GPIO_Pin_1, Bit_SET);
		GPIO_WriteBit(GPIOA, GPIO_Pin_4, Bit_SET);
		GPIO_WriteBit(GPIOA, GPIO_Pin_6, Bit_SET);
		GPIO_WriteBit(GPIOA, GPIO_Pin_7, Bit_SET);
		delay(1000);
		all_off();
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);
		GPIO_WriteBit(GPIOA, GPIO_Pin_4, Bit_SET);	
		GPIO_WriteBit(GPIOA, GPIO_Pin_5, Bit_SET);
		delay(5000);
		all_off();
		
		GPIO_WriteBit(GPIOA, GPIO_Pin_4, Bit_SET);	
		GPIO_WriteBit(GPIOA, GPIO_Pin_6, Bit_SET);
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);
		delay(5000);
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);
		delay(150);
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);
		delay(50);
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);
		delay(150);
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);
		delay(50);
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);
		delay(150);
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);
		delay(50);
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);
		delay(150);
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);
		delay(50);
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);
		delay(150);
		all_off();
		
		GPIO_WriteBit(GPIOA, GPIO_Pin_1, Bit_SET);
		GPIO_WriteBit(GPIOA, GPIO_Pin_4, Bit_SET);	
		GPIO_WriteBit(GPIOA, GPIO_Pin_7, Bit_SET);
		delay(1000);
		all_off();
		GPIO_WriteBit(GPIOA, GPIO_Pin_1, Bit_SET);
		GPIO_WriteBit(GPIOA, GPIO_Pin_4, Bit_SET);
		GPIO_WriteBit(GPIOA, GPIO_Pin_9, Bit_SET);	
		GPIO_WriteBit(GPIOA, GPIO_Pin_7, Bit_SET);
		delay(1000);
		all_off();				
	} 
}


void delay(uint32_t ms)
{
	// Reload us value
	msTicks = ms;
	// Wait until usTick reach zero
	while (msTicks);
}

// SysTick_Handler function will be called every 1 ms
void SysTick_Handler()
{
	if (msTicks != 0)
	{
		msTicks--;
	}
}

