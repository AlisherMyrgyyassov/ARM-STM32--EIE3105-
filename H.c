#include "stm32f10x.h"                  // Device header
#include "stdbool.h"

void delay(uint32_t ms);

static __IO uint32_t msTicks;

static bool state = false;
static bool state_changed = false;
static bool works = true;

int i = 0;

#define BUTTON_RCC_GPIO   RCC_APB2Periph_GPIOC
#define BUTTON_GPIO	      GPIOC
#define BUTTON_GPIO_PIN   GPIO_Pin_13
#define BUTTON_EXTI_LINE     EXTI_Line13
#define BUTTON_GPIO_PORTSOURCE GPIO_PortSourceGPIOC
#define BUTTON_GPIO_PINSOURCE  GPIO_PinSource13

#define L3_RCC_GPIO  RCC_APB2Periph_GPIOB
#define L3_GPIO      GPIOB
#define L3_R_PIN     GPIO_Pin_8
#define L3_G_PIN     GPIO_Pin_9


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
	
	GPIO_InitTypeDef GPIO_InitStruct;
	
	// GPIO clock for I/O
	RCC_APB2PeriphClockCmd(BUTTON_RCC_GPIO, ENABLE);
   	RCC_APB2PeriphClockCmd(L3_RCC_GPIO, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	
	// Configure I/O for L3
	GPIO_InitStruct.GPIO_Pin = L3_R_PIN | L3_G_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(L3_GPIO, &GPIO_InitStruct);
 
	// Configure I/O for EXTI13
	GPIO_InitStruct.GPIO_Pin = BUTTON_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(BUTTON_GPIO, &GPIO_InitStruct);
	
	// EXTI Configuration
	GPIO_EXTILineConfig(BUTTON_GPIO_PORTSOURCE, BUTTON_GPIO_PINSOURCE);
	EXTI_InitTypeDef EXTI_InitStruct;
	EXTI_InitStruct.EXTI_Line = BUTTON_EXTI_LINE;
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStruct);
	
	// Enable Interrupt
	NVIC_InitTypeDef NVIC_InitStruct;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    	NVIC_InitStruct.NVIC_IRQChannel = EXTI15_10_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0x02;
	NVIC_Init(&NVIC_InitStruct);

	while(1) {
		all_off();
		if (i == 0)
		{
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
}


void EXTI15_10_IRQHandler(void) {
    if (EXTI_GetITStatus(EXTI_Line13) != RESET) {	
				if (i == 0) i = 1;
			else i = 0;
			state = !state;
			state_changed = true;
			all_off();
			EXTI_ClearITPendingBit(EXTI_Line13);
			
    }
}

void delay(uint32_t ms)
{
	// Reload us value
	msTicks = ms;
	// Wait until usTick reach zero
	while (msTicks){}
	while(i);
}

// SysTick_Handler function will be called every 1 ms
void SysTick_Handler()
{
	if (msTicks != 0)
	{
		msTicks--;
	}
}


