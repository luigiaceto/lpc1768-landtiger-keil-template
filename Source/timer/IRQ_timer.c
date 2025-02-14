#include "LPC17xx.h"
#include "timer.h"
#include "../led/led.h"
#include "sample.h"
#include "RIT/RIT.h"


/* 
	 To change the frequency of any of these 4 timers you must head to system_LPC17xx.c
	 on Peripheral Clock Selection Register. Note that the standard input frequency of the 
	 divider is 100MHz.
*/

void TIMER0_IRQHandler(void) {
	
	if (LPC_TIM0->IR & 1) { // MR0
		
		
		LPC_TIM0->IR = 1;											/* clear interrupt flag */
	} else if (LPC_TIM0->IR & 2) { // MR1
		
		
		LPC_TIM0->IR = 2;                     /* clear interrupt flag */
	} else if (LPC_TIM0->IR & 4) { // MR2
		
		
		LPC_TIM0->IR = 4;                     /* clear interrupt flag */
	} else if (LPC_TIM0->IR & 8) { // MR3
		
		
		LPC_TIM0->IR = 8;                     /* clear interrupt flag */
	}
  
  return;
}


void TIMER1_IRQHandler(void) {
	
	if (LPC_TIM1->IR & 1) { // MR0
		
		
		LPC_TIM1->IR = 1;											/* clear interrupt flag */
	} else if (LPC_TIM1->IR & 2) { // MR1
		
		
		LPC_TIM1->IR = 2;                     /* clear interrupt flag */
	} else if (LPC_TIM1->IR & 4) { // MR2
		
		
		LPC_TIM1->IR = 4;                     /* clear interrupt flag */
	} else if (LPC_TIM1->IR & 8) { // MR3
		
		
		LPC_TIM1->IR = 8;                     /* clear interrupt flag */
	}
  
  return;
}


void TIMER2_IRQHandler(void) {
	
	if (LPC_TIM2->IR & 1) { // MR0
		
		
		LPC_TIM2->IR = 1;											/* clear interrupt flag */
	} else if (LPC_TIM2->IR & 2) { // MR1
		
		
		LPC_TIM2->IR = 2;                     /* clear interrupt flag */
	} else if (LPC_TIM2->IR & 4) { // MR2
		
		
		LPC_TIM2->IR = 4;                     /* clear interrupt flag */
	} else if (LPC_TIM2->IR & 8) { // MR3
		
		
		LPC_TIM2->IR = 8;                     /* clear interrupt flag */
	}
  
  return;
}


void TIMER3_IRQHandler(void) {
	
	if (LPC_TIM3->IR & 1) { // MR0
		
		
		LPC_TIM3->IR = 1;											/* clear interrupt flag */
	} else if (LPC_TIM3->IR & 2) { // MR1
		
		
		LPC_TIM3->IR = 2;                     /* clear interrupt flag */
	} else if (LPC_TIM3->IR & 4) { // MR2
		
		
		LPC_TIM3->IR = 4;                     /* clear interrupt flag */
	} else if (LPC_TIM3->IR & 8) { // MR3
		
		
		LPC_TIM3->IR = 8;                     /* clear interrupt flag */
	}
  
  return;
}
