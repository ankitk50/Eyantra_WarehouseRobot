/*
*
* Team Id: eYRC#2467-WM
* Modified By- Ankit Kumar
* Filename: Buzzer_beep.h
* Theme: 	Warehouse Management	
* Functions: buzzer_on(),buzzer_off(),buzzer_pin_config(),init_buzzer()	
* Global Variables:	NULL
*
*/
	
	
	
/**************************************************************************
	* Function Name:init_buzzer()
	* Input:		NULL
	* Output:		initializes data direction for buzzer connected port
	* Logic:		values are specified for DDR and PORT
	*
	* Example Call:	init_buzzer()
	*
	**************************************************************************/
/**************************************************************************
	* Function Name:buzzer_pin_config()
	* Input:		NULL
	* Output:		initializes data direction for buzzer connected port
	* Logic:		values are specified for DDR and PORT
	*
	* Example Call:	buzzer_pin_config()
	
**************************************************************************/
/**************************************************************************
	* Function Name:buzzer_on()
	* Input:		NULL
	* Output:		turns on the buzzer
	* Logic:		values are specified for DDR and PORT
	*
	* Example Call:buzzer_on()
	*
	**************************************************************************/
/**************************************************************************
	* Function Name:buzzer_off()
	* Input:		NULL
	* Output:		turns off the buzzer
	* Logic:		values are specified for DDR and PORT
	*
	* Example Call:	buzzer_off()
	
**************************************************************************/





#define F_CPU 14745600
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

//Function to initialize Buzzer 
void buzzer_pin_config (void)
{
 DDRC = DDRC | 0x08;		//Setting PORTC 3 as output
 PORTC = PORTC & 0xF7;		//Setting PORTC 3 logic low to turnoff buzzer
}

void init_buzzer (void)
{
	cli();
	buzzer_pin_config();
	sei();
}

void buzzer_on (void)
{
 unsigned char port_restore = 0;
 port_restore = PINC;
 port_restore = port_restore | 0x08;
 PORTC = port_restore;
}

void buzzer_off (void)
{
 unsigned char port_restore = 0;
 port_restore = PINC;
 port_restore = port_restore & 0xF7;
 PORTC = port_restore;
}

