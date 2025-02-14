#include "LPC17xx.h"
#include "timer.h"
#include "../led/led.h"
#include "sample.h"
#include "RIT/RIT.h"

/* PER CAMBIARE FREQUENZA TIMER ANDARE SU system_LPC17xx.c SU PERIPHERAL CLOCK SELECTION
 REGISTER CONSIDERANDO CHE LA FREQUENZA D'ENTRATA AL DIVISORE E' DI 100Mhz */

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
