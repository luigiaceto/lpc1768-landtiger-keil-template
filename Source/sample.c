#include <stdio.h>
#include "LPC17xx.h"                    /* LPC17xx definitions                */
#include "led/led.h"
#include "button_EXINT/button.h"
#include "timer/timer.h"
#include "RIT/RIT.h"
#include "joystick/joystick.h"
#include "sample.h"
#include "adc/adc.h"

#ifdef SIMULATOR
extern uint8_t ScaleFlag; // <- ScaleFlag needs to visible in order for the emulator to find the symbol (can be placed also inside system_LPC17xx.h but since it is RO, it needs more work)
#endif

/* STO USANDO OTTIMIZZAZIONE -O1*/
int main (void) {
  	
	SystemInit();  												/* System Initialization (i.e., PLL)  */
  LED_init();                           /* LED Initialization                 */
  BUTTON_init();												/* BUTTON Initialization              */
	joystick_init();											/* Joystick Initialization            */
	//ADC_init();
	init_RIT(0x004C4B40);									/* RIT Initialization 50 msec (RIT lavora a 100Mhz) */
	enable_RIT();													/* RIT enabled												*/
	//init_timer(2, 500000);							  /* c = t*f = 1/100 * 50MHz  					*/
	
	
	
	LPC_SC->PCON |= 0x1;									
	LPC_SC->PCON &= ~(0x2);						
		
  while (1) {                           	
		__ASM("wfi");
  }
}
