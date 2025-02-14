#include "button.h"
#include "LPC17xx.h"
#include "sample.h"

extern int int0_pressed;
extern int key1_pressed;
extern int key2_pressed;

void EINT0_IRQHandler(void) {	  							/* INT0														 */
	NVIC_DisableIRQ(EINT0_IRQn);								/* disable Button interrupts			 */
	LPC_PINCON->PINSEL4    &= ~(1 << 20);     	/* GPIO pin selection */
	int0_pressed=1;
	LPC_SC->EXTINT &= (1 << 0);     						/* clear pending interrupt         */
}


void EINT1_IRQHandler(void) {	  							/* KEY1														 */
	NVIC_DisableIRQ(EINT1_IRQn);								
	LPC_PINCON->PINSEL4    &= ~(1 << 22);     	
	key1_pressed=1;
	LPC_SC->EXTINT &= (1 << 1);     						
}


void EINT2_IRQHandler(void) {	  							/* KEY2														 */
	NVIC_DisableIRQ(EINT2_IRQn);								
	LPC_PINCON->PINSEL4    &= ~(1 << 24);    		
	key2_pressed=1;
  LPC_SC->EXTINT &= (1 << 2);     						    
}
