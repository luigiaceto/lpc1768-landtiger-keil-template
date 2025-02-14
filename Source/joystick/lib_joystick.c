#include "LPC17xx.h"
#include "joystick.h"

void joystick_init(void) {
	// Joystick Down (P1.26)
  LPC_PINCON->PINSEL3 &= ~(3 << 20);   // COnfigure P1.26 as GPIO
  LPC_GPIO1->FIODIR   &= ~(1 << 26);   // Set P1.26 as Input

  // Joystick Left (P1.27)
  LPC_PINCON->PINSEL3 &= ~(3 << 22);   // Configure P1.27 as GPIO
  LPC_GPIO1->FIODIR   &= ~(1 << 27);   // Set P1.27 as Input

  // Joystick Right (P1.28)
  LPC_PINCON->PINSEL3 &= ~(3 << 24);   // Configure P1.28 as GPIO
  LPC_GPIO1->FIODIR   &= ~(1 << 28);   // Set P1.28 as Input
	
	// Joystick Up (P1.29)
  LPC_PINCON->PINSEL3 &= ~(3<<26);		 // Configure P1.29 as GPIO
	LPC_GPIO1->FIODIR   &= ~(1<<29);		 // Set P1.25 as Input 
}
