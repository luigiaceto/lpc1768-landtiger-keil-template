#include "LPC17xx.h"
#include "RIT.h"
#include "../led/led.h"
#include "../timer/timer.h"
#include "sample.h"
#include "../adc/adc.h"

// operatori logici bitwise: &and |or ^xor ~not 

volatile int int0_pressed=0;
volatile int key1_pressed=0;
volatile int key2_pressed=0;
volatile int int0_toRelease=0;
volatile int key1_toRelease=0;
volatile int key2_toRelease=0;


void RIT_IRQHandler(void) {					
	static int down=0, left=0, right=0, up=0;
	static int upleft=0, upright=0, downleft=0, downright=0;
	
	
	if ((LPC_GPIO1->FIOPIN & (1<<26))==0 && (LPC_GPIO1->FIOPIN & (1<<27))!=0 && (LPC_GPIO1->FIOPIN & (1<<28))!=0) {	
		/* Joytick DOWN pressed */
		down++;
		switch(down){
			case 1:
				
				break;
			default:
				break;
		}
	} else {
		down=0;
	}
	
	
	if ((LPC_GPIO1->FIOPIN & (1<<27))==0 && (LPC_GPIO1->FIOPIN & (1<<26))!=0 && (LPC_GPIO1->FIOPIN & (1<<29))!=0) {	
		/* Joytick LEFT pressed */
		left++;
		switch(left){
			case 1:
				
				break;
			default:
				break;
		}
	} else {
		left=0;
	}
	
	
	if ((LPC_GPIO1->FIOPIN & (1<<28))==0 && (LPC_GPIO1->FIOPIN & (1<<26))!=0 && (LPC_GPIO1->FIOPIN & (1<<29))!=0) {	
		/* Joytick RIGHT pressed */
		right++;
		switch(right){
			case 1:
				
				break;
			default:
				break;
		}
	} else {
		right=0;
	}
	
	
	if ((LPC_GPIO1->FIOPIN & (1<<29))==0 && (LPC_GPIO1->FIOPIN & (1<<27))!=0 && (LPC_GPIO1->FIOPIN & (1<<28))!=0) {	
		/* Joytick UP pressed */
		up++;
		switch(up){
			case 1:
				
				break;
			default:
				break;
		}
	} else {
		up=0;
	}
	
	
	if ((LPC_GPIO1->FIOPIN & (1<<29))==0 && (LPC_GPIO1->FIOPIN & (1<<27))==0) {	
		/* Joytick UP-LEFT pressed */
		upleft++;
		switch(upleft){
			case 1:
				
				break;
			default:
				break;
		}
	} else {
		upleft=0;
	}
	
	
	if ((LPC_GPIO1->FIOPIN & (1<<29))==0 && (LPC_GPIO1->FIOPIN & (1<<28))==0) {	
		/* Joytick UP-RIGHT pressed */
		upright++;
		switch(upright){
			case 1:
				
				break;
			default:
				break;
		}
	} else {
		upright=0;
	}
	
	
	if ((LPC_GPIO1->FIOPIN & (1<<26))==0 && (LPC_GPIO1->FIOPIN & (1<<27))==0) {	
		/* Joytick DOWN-LEFT pressed */
		downleft++;
		switch(downleft){
			case 1:
				
				break;
			default:
				break;
		}
	} else {
		downleft=0;
	}
	
	
	if ((LPC_GPIO1->FIOPIN & (1<<26))==0 && (LPC_GPIO1->FIOPIN & (1<<28))==0) {	
		/* Joytick DOWN-RIGHT pressed */
		downright++;
		switch(downright){
			case 1:
				
				break;
			default:
				break;
		}
	} else {
		downright=0;
	}
	
	
	/*                BUTTON                 */
	
	/* INT0 pressed */
	if(int0_pressed>=1){ 
		if((LPC_GPIO2->FIOPIN & (1<<10)) == 0) {	
			switch(int0_pressed){				
				case 2:		
					
					int0_toRelease=1;
					break;
				default:
					break;
			}
			int0_pressed++;
		} else {	                                   /* button released */
			if (int0_toRelease==1) {
				
				int0_toRelease=0;
			}
			int0_pressed=0;			
			NVIC_EnableIRQ(EINT0_IRQn);							 /* enable Button interrupts			     */
			LPC_PINCON->PINSEL4    |= (1 << 20);     /* External interrupt 0 pin selection */
		}
	}
	
	
	/* KEY1 pressed */
	if(key1_pressed>=1){ 
		if((LPC_GPIO2->FIOPIN & (1<<11)) == 0) {	
			switch(key1_pressed){				
				case 2:				
					
					key1_toRelease=1;
					break;
				default:
					break;
			}
			key1_pressed++;
		} else {	                                   /* button released */
			if (key1_toRelease==1) {
				
				key1_toRelease=0;
			}
			key1_pressed=0;			
			NVIC_EnableIRQ(EINT1_IRQn);							 /* enable Button interrupts			     */
			LPC_PINCON->PINSEL4    |= (1 << 22);     /* External interrupt 0 pin selection */
		}
	}
	
	
	/* KEY2 pressed */
	if(key2_pressed>=1){ 
		if((LPC_GPIO2->FIOPIN & (1<<12)) == 0){	
			switch(key2_pressed){				
				case 2:				
					
					key2_toRelease=1;
					break;
				default:
					break;
			}
			key2_pressed++;
		} else {	                                   /* button released */
			if (key2_toRelease==1) {
				
				key2_toRelease=0;
			}
			key2_pressed=0;			
			NVIC_EnableIRQ(EINT2_IRQn);							 /* enable Button interrupts			*/
			LPC_PINCON->PINSEL4    |= (1 << 24);     /* External interrupt 0 pin selection */
		}
	}
	
	
  LPC_RIT->RICTRL |= 0x1;	/* clear interrupt flag */
  return;
}