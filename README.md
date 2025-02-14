# LandTIger LPC1768 board on Keil

<p align="center">
    <img src="Images/board_pic.png" alt="" width="300">
</p>

This is a project involving the embedded board LPC1768 and permits to interface with it 
through a series of libraries including LEDs, BUTTONs, JOYSTICK and the ADC. 
Note: the project uses polling though the Repetitive Interrupt Timer insted of direct interrupts because the Joystick pins can't throws interrupts. A version which starts the RIT in the button handlers can be implemented if the joystick isn't needed.

## main folder
- sample.c : contain the main file of the project, where all the components are initialized
- sample.h : permit to define some constants to share in the entire project
- ASM_funct.s : permit to define ASM functions to use in the project and called through the ABI standard

## led
- funct_led.c : it defines some functions regarding the LEDs such as the LED_out() which lights up certain LEDs
- lib_led.c : it initializes the LEDs setting up their PIN mode and direction (in/out)

## button_EINT
