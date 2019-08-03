
/*
*
* Team Id: eYRC#2467-WM
* Modified By-Ankit Kumar
* Filename: Pos_Con_Interrupts.h
* Theme: 	Warehouse Management	
* Functions: int smallest_location(int a[]),map * final_point(int),void deposit_point(int a[])
* Global Variables:	unsigned char Left_white_line = 0;
*					unsigned char Center_white_line = 0;
*					unsigned char Right_white_line = 0;
*					volatile unsigned long int ShaftCountLeft = 0; //to keep track of left position encoder
*					volatile unsigned long int ShaftCountRight = 0; //to keep track of right position encoder
*					volatile unsigned int Degrees; //to accept angle in degrees for turning
*					unsigned char line_check_flag=0;
*
*/


    /**************************************************************************
	* Function Name:void motion_set(unsigned char direction)
	* Input:		direction-specifies the direction of PORTA and DDRA
	* Output:		configures data direction and port for both the wheels of the moter
	* Logic:		Values are specified to DDRA and PORTA 
	* Example Call:	motion_set(0x06)
	*
	**************************************************************************/
    /**************************************************************************
	* Function Name:void forward()
	* Input:		NULL
	* Output:		configures data direction and port for both the wheels to move forward
	* Logic:		uses motion set function 
	* Example Call:	forward()
	*
	**************************************************************************/
	
    /**************************************************************************
	* Function Name:void back()
	* Input:		NULL
	* Output:		configures data direction and port for both the wheels to move backward
	* Logic:		uses motion set function 
	* Example Call:	back()
	*
	**************************************************************************/
	 /**************************************************************************
	* Function Name:void right()
	* Input:		NULL
	* Output:		configures data direction and port for both the wheels to move tht bot right
	* Logic:		uses motion set function 
	* Example Call:	right()
	*
	**************************************************************************/
	/**************************************************************************
	* Function Name:void left()
	* Input:		NULL
	* Output:		configures data direction and port for both the wheels to move the bot leftwards
	* Logic:		uses motion set function 
	* Example Call:	left()
	*
	**************************************************************************/

	/**************************************************************************
	* Function Name:void stop()
	* Input:		NULL
	* Output:		stops the bot wheels 
	* Logic:		uses motion set function 
	* Example Call:	stop()
	*
	**************************************************************************/  
/**************************************************************************
	* Function Name:angle_rotate(int degrees)
	* Input: degrees ->integer value which specifies amount of angle for the bot to rotate
	* Output:		rotates the bot precisely to the angle specified
	* Logic:		uses interrupt enabled position encoders for the bot movement
	*				ReqdShaftCount = (float) Degrees/ 4.090;
	* Example Call:	angle_rotate(90)
	*
	**************************************************************************/
/**************************************************************************
	* Function Name:left_degrees(unsigned int degrees)
	* Input: degrees ->integer value which specifies amount of angle for the bot to rotate in left direction
	* Output:		rotates the bot precisely to the angle specified in left direction (both wheels rotating)
	* Logic:		uses angle_rotate()
	* Example Call:	left_degrees(90)
	*
	**************************************************************************/
/**************************************************************************
	* Function Name:right_degrees(unsigned int degrees)
	* Input: degrees ->integer value which specifies amount of angle for the bot to rotate in right direction
	* Output:		rotates the bot precisely to the angle specified in right direction (both wheels rotating)
	* Logic:		uses angle_rotate()
	* Example Call:	right_degrees(90)
	*
	**************************************************************************/
    /**************************************************************************
	* Function Name:void linear_distance_mm(unsigned int DistanceInMM)
	* Input: DistanceInMM-> >integer value which specifies amount of distance in mm for the bot to travel 
	* Output:		moves the bot straight in to the distance specified in milli meters
	* Logic:		uses interrupt enabled position encoders for the bot movement
	*				ReqdShaftCount = DistanceInMM / 5.338;
	* Example Call:	linear_distance_mm(10);
	*
	**************************************************************************/
	
    /**************************************************************************
	* Function Name:void forward_mm(unsigned int DistanceInMM)
	* Input: DistanceInMM-> >integer value which specifies amount of distance in mm for the bot to travel 
	* Output:		moves the bot forward straight in to the distance specified in milli meters
	* Logic:		uses interrupt enabled position encoders for the bot movement
	*				ReqdShaftCount = DistanceInMM / 5.338;
	* Example Call:	linear_distance_mm(10);
	*
	**************************************************************************/
	
    /**************************************************************************
	* Function Name:void back_mm(unsigned int DistanceInMM)
	* Input: DistanceInMM-> >integer value which specifies amount of distance in mm for the bot to travel 
	* Output:		moves the bot back straight in to the distance specified in milli meters
	* Logic:		uses interrupt enabled position encoders for the bot movement
	*				ReqdShaftCount = DistanceInMM / 5.338;
	* Example Call:	linear_distance_mm(10);
	*
	**************************************************************************/
	/**************************************************************************
	* Function Name:void velocity (unsigned char left_motor, unsigned char right_motor)
	* Input: left_motor,  right_motor -> Integer values which is given out as voltage to the PWM output pins OCR1A and OCR1B 
	* Output:		PWM output generation of particular voltage
	* Logic:		OCR5AL = (unsigned char)left_motor;
					OCR5BL = (unsigned char)right_motor;
	* Example Call:	velocity(200,255);
	*
	**************************************************************************/
	/**************************************************************************
	* Function Name:void timer5_init()
	* Input:		NULL
	* Output:		initializes timer 5 for PWM generation
	* Logic:		OCR5AL = (unsigned char)left_motor;
					OCR5BL = (unsigned char)right_motor;
	* Example Call:	timer5_init();
	*
	**************************************************************************/
	/**************************************************************************
	* Function Name:left_position_encoder_interrupt_init (void)
	* Input:		NULL
	* Output:		initializes interrupt for left position encoder
	* Logic:		registers initialized according to data sheet
	* Example Call:	left_position_encoder_interrupt_init (void)
	*
	**************************************************************************/
	
	/**************************************************************************
	* Function Name:right_position_encoder_interrupt_init (void)
	* Input:		NULL
	* Output:		initializes interrupt for right position encoder
	* Logic:		registers initialized according to data sheet
	* Example Call:	right_position_encoder_interrupt_init (void)
	*
	**************************************************************************/
#define F_CPU 14745600
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void velocity(unsigned char, unsigned char);
void forward_mm(unsigned int DistanceInMM);
unsigned char ADC_Conversion(unsigned char Ch);
unsigned char Left_white_line = 0;
unsigned char Center_white_line = 0;
unsigned char Right_white_line = 0;
volatile unsigned long int ShaftCountLeft = 0; //to keep track of left position encoder
volatile unsigned long int ShaftCountRight = 0; //to keep track of right position encoder
volatile unsigned int Degrees; //to accept angle in degrees for turning

#define TH_LEFT    100
#define TH_RIGHT   100
#define TH_CENTER  100    //the center sensor has an extra value mentioned in the linearDistance fun.
#define TH_CENTER01 100

void timer5_init()
{
	TCCR5B = 0x00;	//Stop
	TCNT5H = 0xFF;	//Counter higher 8-bit value to which OCR5xH value is compared with
	TCNT5L = 0x01;	//Counter lower 8-bit value to which OCR5xH value is compared with
	OCR5AH = 0x00;	//Output compare register high value for Left Motor
	OCR5AL = 0xFF;	//Output compare register low value for Left Motor
	OCR5BH = 0x00;	//Output compare register high value for Right Motor
	OCR5BL = 0xFF;	//Output compare register low value for Right Motor
	OCR5CH = 0x00;	//Output compare register high value for Motor C1
	OCR5CL = 0xFF;	//Output compare register low value for Motor C1
	TCCR5A = 0xA9;	/*{COM5A1=1, COM5A0=0; COM5B1=1, COM5B0=0; COM5C1=1 COM5C0=0}
 					  For Overriding normal port functionality to OCRnA outputs.
				  	  {WGM51=0, WGM50=1} Along With WGM52 in TCCR5B for Selecting FAST PWM 8-bit Mode*/
	
	TCCR5B = 0x0B;	//WGM12=1; CS12=0, CS11=1, CS10=1 (Prescaler=64)
}

//Function to configure ports to enable robot's motion
void motion_pin_config (void)
{
	DDRA = DDRA | 0x0F;
	PORTA = PORTA & 0xF0;
	DDRL = DDRL | 0x18;   //Setting PL3 and PL4 pins as output for PWM generation
	PORTL = PORTL | 0x18; //PL3 and PL4 pins are for velocity control using PWM.
}

//Function to configure INT4 (PORTE 4) pin as input for the left position encoder
void left_encoder_pin_config (void)
{
	DDRE  = DDRE & 0xEF;  //Set the direction of the PORTE 4 pin as input
	PORTE = PORTE | 0x10; //Enable internal pull-up for PORTE 4 pin
}

//Function to configure INT5 (PORTE 5) pin as input for the right position encoder
void right_encoder_pin_config (void)
{
	DDRE  = DDRE & 0xDF;  //Set the direction of the PORTE 4 pin as input
	PORTE = PORTE | 0x20; //Enable internal pull-up for PORTE 4 pin
}

//Function to initialize ports
void port_init_pos()
{
	motion_pin_config(); //robot motion pins config
	left_encoder_pin_config(); //left encoder pin config
	right_encoder_pin_config(); //right encoder pin config
}

void left_position_encoder_interrupt_init (void) //Interrupt 4 enable
{
	cli(); //Clears the global interrupt
	EICRB = EICRB | 0x02; // INT4 is set to trigger with falling edge
	EIMSK = EIMSK | 0x10; // Enable Interrupt INT4 for left position encoder
	sei();   // Enables the global interrupt
}

void right_position_encoder_interrupt_init (void) //Interrupt 5 enable
{
	cli(); //Clears the global interrupt
	EICRB = EICRB | 0x08; // INT5 is set to trigger with falling edge
	EIMSK = EIMSK | 0x20; // Enable Interrupt INT5 for right position encoder
	sei();   // Enables the global interrupt
}

//ISR for right position encoder
ISR(INT5_vect)
{
	ShaftCountRight++;  //increment right shaft position count
}


//ISR for left position encoder
ISR(INT4_vect)
{
	ShaftCountLeft++;  //increment left shaft position count
}


//Function used for setting motor's direction
void motion_set (unsigned char Direction)
{
	unsigned char PortARestore = 0;

	Direction &= 0x0F; 		// removing upper nibbel for the protection
	PortARestore = PORTA; 		// reading the PORTA original status
	PortARestore &= 0xF0; 		// making lower direction nibbel to 0
	PortARestore |= Direction; // adding lower nibbel for forward command and restoring the PORTA status
	PORTA = PortARestore; 		// executing the command
}

void forward (void) //both wheels forward
{
	motion_set(0x06);
	velocity(240,230);
}

void back (void) //both wheels backward
{
	motion_set(0x09);
}

void left (void) //Left wheel backward, Right wheel forward
{
	motion_set(0x05);
}

void right (void) //Left wheel forward, Right wheel backward
{
	motion_set(0x0A);
}

void stop (void)
{
	motion_set(0x00);
}


//Function used for turning robot by specified degrees
void angle_rotate(unsigned int Degrees)
{
	float ReqdShaftCount = 0;
	unsigned long int ReqdShaftCountInt = 0;

	ReqdShaftCount = (float) Degrees/ 4.090; // division by resolution to get shaft count
	ReqdShaftCountInt = (unsigned int) ReqdShaftCount + 10;
	ShaftCountRight = 0;
	ShaftCountLeft = 0;

	while (1)
	{
		Center_white_line=ADC_Conversion(2);
		Left_white_line=ADC_Conversion(1);
		Right_white_line=ADC_Conversion(3);
		if((ShaftCountRight >= ReqdShaftCountInt) || (ShaftCountLeft >= ReqdShaftCountInt))
		break;
		if((ShaftCountLeft>5)||(ShaftCountRight>5))
		{
			if ((Center_white_line>70))//&&(Left_white_line<13)&&(Right_white_line<13))
			{
				
				break;
			}
		}
	}
	stop(); //Stop robot
}

//Function used for moving robot forward by specified distance

void linear_distance_mm(unsigned int DistanceInMM)
{
	float ReqdShaftCount = 0;
	unsigned long int ReqdShaftCountInt = 0;

	ReqdShaftCount = DistanceInMM / 5.338; // division by resolution to get shaft count
	ReqdShaftCountInt = (unsigned long int) ReqdShaftCount;
	
	ShaftCountRight = 0;
	while(1)
	{
		
		if(ShaftCountRight > ReqdShaftCountInt )
		{
			break;
		}
	}
	stop(); //Stop robot
}

void forward_mm(unsigned int DistanceInMM)
{
	forward();
	linear_distance_mm(DistanceInMM);
}

void back_mm(unsigned int DistanceInMM)
{
	back();
	linear_distance_mm(DistanceInMM);
}

void left_degrees(unsigned int Degrees)
{
	// 88 pulses for 360 degrees rotation 4.090 degrees per count
	left(); //Turn left
	velocity(180,180);
	angle_rotate(Degrees);
}



void right_degrees(unsigned int Degrees)
{
	// 88 pulses for 360 degrees rotation 4.090 degrees per count
	right(); //Turn right
	velocity(180,180);
	angle_rotate(Degrees);
}



//Function to initialize all the devices
void init_devices_pos()
{
	cli(); //Clears the global interrupt
	
	port_init_pos();  //Initializes all the ports
	timer5_init();//initialise timer5 for PWM
	left_position_encoder_interrupt_init();
	right_position_encoder_interrupt_init();
	sei();   // Enables the global interrupt
}

void velocity (unsigned char left_motor, unsigned char right_motor)
{
	OCR5AL = (unsigned char)left_motor;
	OCR5BL = (unsigned char)right_motor;
}