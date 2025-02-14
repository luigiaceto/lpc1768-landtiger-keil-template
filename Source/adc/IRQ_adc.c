#include "LPC17xx.h"
#include "adc.h"
#include "../led/led.h"

/*----------------------------------------------------------------------------
  A/D IRQ: Executed when A/D Conversion is ready (signal from ADC peripheral)
 *----------------------------------------------------------------------------*/

unsigned short AD_current;   
unsigned short AD_last = 0xFF;     /* Last converted value               */

void ADC_IRQHandler(void) {
  	
  AD_current = ((LPC_ADC->ADGDR>>4) & 0xFFF);/* Read Conversion Result             */
  if (AD_current != AD_last) {
		AD_last = AD_current;
  }	
}
