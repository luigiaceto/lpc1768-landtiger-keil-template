#include "LPC17xx.h"
#include "joystick.h"

void joystick_init(void) {
	// Joystick Down (P1.26)
  LPC_PINCON->PINSEL3 &= ~(3 << 20);   // Configura P1.26 come GPIO (00b)
  LPC_GPIO1->FIODIR   &= ~(1 << 26);   // Imposta P1.26 come Input

  // Joystick Left (P1.27)
  LPC_PINCON->PINSEL3 &= ~(3 << 22);   // Configura P1.27 come GPIO (00b)
  LPC_GPIO1->FIODIR   &= ~(1 << 27);   // Imposta P1.27 come Input

  // Joystick Right (P1.28)
  LPC_PINCON->PINSEL3 &= ~(3 << 24);   // Configura P1.28 come GPIO (00b)
  LPC_GPIO1->FIODIR   &= ~(1 << 28);   // Imposta P1.28 come Input
	
	// Joystick Up (P1.29)
  LPC_PINCON->PINSEL3 &= ~(3<<26);		 //PIN mode GPIO (00b value per P1.29)
	LPC_GPIO1->FIODIR   &= ~(1<<29);		 //P1.25 Input (joysticks on PORT1 defined as Input) 
}
