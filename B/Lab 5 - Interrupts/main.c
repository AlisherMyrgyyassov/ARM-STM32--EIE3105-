#include "stm32f10x.h"                  // Device header

void delay(int t);

int main(void) {
	
	//GPIO set up for PA5 (on-board LD2)
	//Enable APB2 periphral clock
	RCC->APB2ENR |= RCC_APB2Periph_GPIOA;

	GPIOA->CRL &= ~0x00F00000;  //clear the setting
	GPIOA->CRL |=  0 << 22 | 2 << 20; //GPIO_Mode_Out_PP, GPIO_Speed_2MHz
	
	while(1) {
		GPIOA->BSRR |= 0x20;
		delay(3000000);
		GPIOA->BRR  |= 0x20;
		delay(3000000);
	}
}

void delay(int t) {
	int i, j;
	for(i=0; i<t; i++)
		j++;
}
