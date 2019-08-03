/*
*
* Team Id: eYRC#2467-WM
* Author-Abhishek Bohra, Ankit Kumar
* Filename: E YantraC++.cpp
* Theme: 	Warehouse Management
* 
*/


/************************************************************************/
/* Function Name: check_for_box()
/* Input: Takes no parameter. Takes ADC conversion of Sharp IR sensors and then Color Sensors
/* Output: Return a number associated to a color. 10 for Red, 11 for Blue,12 for Gree,-1 for black and 0 if nothing found
/* Logic: First the Sharp IR sensor detect the presence of the package. If the package is there it checks for color and returns its associated number or else it return zero if nothing is found
/* Example Call: int color=check_for_box()                                                                     */
/************************************************************************/

/************************************************************************/
/* Function Name:checknode()
/* Input: Takes no parameter. The values of white line sensor are checked as input
/* Output:Returns 1 if a node is found or else returns 0
/* Logic: If all the sensors OR combination of sensor:Middle-Left OR Middle-Right are more than a specific threshold value(means the are detecting black surface) then a node is considered i.e. 1 is returned
/* Example Call: checknode() --It is used in the function stepmove which is explained next.                                                              */
/************************************************************************/

/************************************************************************/
/* Function Name: stepmove(int a)
/* Input: a-an integer which takes number of steps to be moved
/* Output: Bot moves the distance specified by the number of steps
/* Logic: one step is of 30mm.The bot completes its one step(30mm) in the intervals of 1mm. After moving 1mm the bot corrects its alignment by calling the function line_check().Since the position encoders are not accurate we are using a function checknode() which breaks this function when a node is encountered. 
/* Example Call: stepmove(9) will move 270mm                                                               */
/************************************************************************/

/************************************************************************/
/* Function Name:  Travel(int direction[])
/* Input: direction array-a global integer array made by directionfetcher in mapp.cpp
/* Output: It calls the function Move and MakeDirection
/* Logic: It uses Move and MakeDirection and guides the bot along its path to its destination
/* Example Call:  Travel(int direction[])                                                             */
/************************************************************************/

/************************************************************************/
/* Function Name: Move()
/* Input: No parameters but uses Global variable dir and the obj's(the points) type
/* Output: Calls stepmove() with a parameter which is decided in the function
/* Logic: Move checks the direction of the bot,type of the node at which it is and the node it is facing. Since the nodes are not equidistant it choses the parameter of stepmove() function accordingly and calls stepmove with the parameter.
/* Example Call: Move()                                                               */
/************************************************************************/

/************************************************************************/
/* Function Name: search()
/* Input: Takes no parameter.Checks different flags and the position of the bot
/* Output: Bot performs search at each pickup points and deposits the valid packages if found.The function is broken after calling nearest_row_select()
/* Logic: search uses number of function like goto(),check_for_box(),pickup(),drop(),nearest_row_select() which perfom various task according to their implementation.
/* Example Call:search()                                                               */
/************************************************************************/

/************************************************************************/
/* Function Name: MakeDirection(int d)
/* Input: d is the direction to be made. It also uses dir, which is the current direction
/* Output: The bot turns to the desired direction and updates the  global dir using left()/right()
/* Logic: It keeps on using  the functions Left()/Right() until its dir=d. 
/* Example Call: MakeDirection(3) makes the bot point to towards south.                                                              */
/************************************************************************/

/************************************************************************/
/* Function Name: Left()
/* Input: No input parameters
/* Output: The bot turns Left by 90 degrees and updates the direction
/* Logic: using left_degrees(90) it turns the bot 90 degress left and then updates the dir,the global variable for bots current direction
/* Example Call: Left() is called in MakeDirection(2)                                                              */
/************************************************************************/


/************************************************************************/
/* Function Name: Right()
/* Input: No input parameters
/* Output: The bot turns Right by 90 degrees and updates the direction
/* Logic: using right_degrees(90) it turns the bot 90 degress right and then updates the dir,the global variable for bots current direction
/* Example Call: right() is called in MakeDirection(2)                                                              */
/************************************************************************/

/************************************************************************/
/* Function Name: size_of_array(int a[])
/* Input: integer array as input
/* Output: Returns the number of deposition zones
/* Logic: Stops counting when 99 is detected.
/* Example Call: size_of_array(RED) where RED is the array containing deposition zones for Red colored Packages                                                               */
/************************************************************************/

/************************************************************************/
/* Function Name: Goto(unsigned char x, unsigned char y)
/* Input: The cordinates of the point where we want the bot to go.
/* Output: Takes the Bot through the easiest path
/* Logic: Assigns final point, calls mapp and then travel funtion.
/* Example Call: Goto(7,0) will take the bot to the start.                                                              */
/************************************************************************/

/************************************************************************/
/* Function Name: dropit()
/* Input: Takes no parameter
/* Output: Arm performs drop action using servo functions from servo.h
/* Logic: call several servo functions with different input parameters for precise actuation
/* Example Call: dropit()                                                               */
/************************************************************************/

/************************************************************************/
/* Function Name: move_after_node()
/* Input: null
/* Output: makes the bot move 80 mm
/* Logic: When the bot detects the node,the node is detected by its line sensor. SO the bot has to make 80mm forward so that its wheels come on the line and the bot performs accurate turns about the axis perpendicular to its wheels.
/* Example Call: move_after_node() is called in stepmove() after checknode returns 1(i.e. node has been detected)                                                                */
/************************************************************************/

/************************************************************************/
/* Function Name: line_check()
/* Input:No input parameters but takes adc conversions of the three white line sensors
/* Output: Aligns the bot with the line
/* Logic: Checks various cases using the adc values and manipulates the motion of wheels in such a way that the bot dos not deviate from the line
/* Example Call: line_check() is called in step move after every 1mm                                                            */
/************************************************************************/

/************************************************************************/
/* Function Name: ADC_conversion(char ch)
/* Input:Takes conversion channel num as input parameter
/* Output:returns the ADC conversion value of the channel ch
/* Logic: Starts conversion using ADCSRA and waits for the conversion to complete.And then returns the conversion output and then clears all the set flags involved with ADC conversion.
/* Example Call:ADC_conversion(1) takes ADC values of Left_white_line sensors                                                               */
/************************************************************************/
/************************************************************************/
/* Function Name:adc_init()
/* Input:takes no input parameters
/* Output:initializes various register involved in ADC conversion
/* Logic:ADCSRA = 0x00;ADCSRB,ADMUX,ADLAR,ACSR,ADCSRA  are initialized
/* Example Call:adc_init()                                                               */
/************************************************************************/
/************************************************************************/
/* Function Name:adc_pin_config()
/* Input:takes no input parameters
/* Output:sets directions to to all the ADC pins
/* Logic:sets ADC pins for input
/* Example Call: adc_pin_config()                                                              */
/************************************************************************/

/************************************************************************/
/* Function Name:print_sensor(char row, char coloumn,unsigned char channel)
/* Input:row- specifies the row of lcd to print the values,coloumn specifies the column of lcd for printing values, channel is the ADC conversion value to be printed on the lcd.
/* Output:ADC conversion value gets printed on the lcd
/* Logic:calls print_lcd()
/* Example Call:                                                               */
/************************************************************************/













#define F_CPU 14745600
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include <math.h> //included to support power function
int	size_of_array(int []);
#include "Pos_Con_Interrupts.h"
#include "map.cpp"
#include "color.h"
#include "servo.h"
#include "deposit_point selector.h"
#include "buzzer_beep.h"
int GREEN[3]= {1,5,99};
int RED[3]=   {2,99,99};
int BLUE[3]=	{3,4,99};
int red_count=size_of_array(RED);
int green_count=size_of_array(GREEN);
int blue_count=size_of_array(BLUE);
unsigned char r_counter=1;
unsigned char b_counter=1;
unsigned char g_counter=1;

#define clrscr lcd_wr_command(0x01);

	

int PickupPointXpos;
int PickupPointYpos;
void dropit();
void move_after_node();
void MakeDirectionExclusivelyForDropPoint(int);


	
int BRowDone=0;
int URowDone=0;
#define SHARP_THRESHOLD 70	
#define BUZZER_ON 1
#define BUZZER_OFF 1
int color;//new variable to be return from check for box	
int checknode();
void port_init();
void timer5_init();

void motors_delay();

void print_sensor(char , char,unsigned char );
unsigned char x_pos,y_pos,dir;
unsigned char ADC_Value;
unsigned char flag0 = 0;
unsigned char flag = 0;
unsigned char flag1 = 0;
unsigned char flag2 = 0;
unsigned char Front_Sharp_Sensor=0;
unsigned char Front_IR_Sensor=0;
int Holding;
void stepmove(int);


//Function to configure LCD port

//ADC pin configuration
void adc_pin_config (void)
{
 DDRF = 0x00; 
 PORTF = 0x00;
 DDRK = 0x00;
 PORTK = 0x00;
}

//Function to configure ports to enable robot's motion


//Function to Initialize PORTS
void port_init()
{
	lcd_port_config();
	adc_pin_config();
	motion_pin_config();	
}

// Timer 5 initialized in PWM mode for velocity control
// Prescale:256
// PWM 8bit fast, TOP=0x00FF
// Timer Frequency:225.000Hz


void adc_init()
{
	ADCSRA = 0x00;
	ADCSRB = 0x00;		//MUX5 = 0
	ADMUX = 0x20;		//Vref=5V external --- ADLAR=1 --- MUX4:0 = 0000
	ACSR = 0x80;
	ADCSRA = 0x86;		//ADEN=1 --- ADIE=1 --- ADPS2:0 = 1 1 0
}

//Function For ADC Conversion
unsigned char ADC_Conversion(unsigned char Ch) 
{
	unsigned char a;
	if(Ch>7)
	{
		ADCSRB = 0x08;
	}
	Ch = Ch & 0x07;  			
	ADMUX= 0x20| Ch;	   		
	ADCSRA = ADCSRA | 0x40;		//Set start conversion bit
	while((ADCSRA&0x10)==0);	//Wait for conversion to complete
	a=ADCH;
	ADCSRA = ADCSRA|0x10; //clear ADIF (ADC Interrupt Flag) by writing 1 to it
	ADCSRB = 0x00;
	return a;
}

//Function To Print Sensor Values At Desired Row And Column Location on LCD
void print_sensor(char row, char coloumn,unsigned char channel)
{
	
	ADC_Value = ADC_Conversion(channel);
	lcd_print(row, coloumn, ADC_Value, 3);
}

//Function for velocity control






void init_devices_adc (void)
{
 	cli(); //Clears the global interrupts
	port_init();
	adc_init();

	sei();   //Enables the global interrupts
}

void start();
void search();
int check_for_box();
void Left();
void Right();
void Move();
void Travel(int []);
void MakeDirection(int);

void line_check();

void Goto(unsigned char ,unsigned char );

void Goto(unsigned char x ,unsigned char y )
{
	final=&obj[x][y];
	mapp(Current,final);
	Travel(direction);
}

//Main Function
int main()
{
	
	
	
	init_devices_adc();
	init_devices_pos();
	lcd_set_4bit();
	lcd_init();
	init_buzzer();
	init_devices_servo();
	init_devices_color();
	color_sensor_scaling();
	mapinit();
	
	dir=1;
	stepmove(9);
	Current = &obj[7][0];
	while(1)
	{
		
		if ((obj[1][0].flag==1 && obj[3][0].flag==1 && obj[5][0].flag==1 && obj[9][0].flag==1 && obj[11][0].flag==1 && obj[13][0].flag==1) || (Current->YPOS==8))
		{
			Goto(7,8);
			search();
		}
		else if(Current->YPOS==0 && (obj[1][0].flag==0 || obj[3][0].flag==0 || obj[5][0].flag==0 || obj[9][0].flag==0 || obj[11][0].flag==0 || obj[13][0].flag==0 ))
		{
			if(Current->YPOS==0)
			{
				search();
			}
		}
		if(obj[1][0].flag==1 && obj[3][0].flag==1 && obj[5][0].flag==1 && obj[9][0].flag==1 && obj[11][0].flag==1 && obj[13][0].flag==1 && obj[1][8].flag==1 && obj[3][8].flag==1 && obj[5][8].flag==1 && obj[9][8].flag==1 && obj[11][8].flag==1 && obj[13][8].flag==1) break; //buzzer
		
		
		
	}
		buzzer_on();
}



void Travel(int direction[])
{
	
	
	for(int i=0;i<steps;i++)
	{
		
		
		MakeDirection(direction[i]);
		Move();
		lcd_print(2,5,Current->XPOS,3);
		lcd_print(2,9,Current->YPOS,3);
		
	}
}

void MakeDirection(int d)
{
	while (dir!=d)
	{
		
		if (dir==1 && d==4)
		{
			Left();
			
		} 
		else if(dir==4 && d==1)
		{
			Right();
			
		}
		else if (d>dir)
		{
			Right();
			
		}
		else if (d<dir)
		{
			Left();
			
		}
		
		
	}
}

void MakeDirectionExclusivelyForDropPoint(int d)
{
	while (dir!=d)
	{
		
		if (dir==1 && d==4)
		{
			Left();
		}
		else if(dir==4 && d==1)
		{
			Right();
		}
		else if (d>dir)
		{
			Right();
		}
		else if (d<dir)
		{
			Left();
		}
		
		//Left();
	}
}
void search()
{
	if (Current->YPOS==0)
	{
		for (int i=1;i<=3;i++)
		{
			if (obj[5][0].flag==0 || obj[3][0].flag==0 || obj[1][0].flag==0)
			{
				Goto(7-2*i,0);
				if (Current->flag==0)
				{
					MakeDirection(3);
					_delay_ms(500);
					color=check_for_box();
					//back_mm(30);
					if (color>0)
					{
						switch(color)
						{
							
							case 10:
							deposit_point(RED);
							mapp(Current,final);
							Travel(direction);
							dropit();
							nearest_row_select();
							break;
							case 11:
							deposit_point(GREEN);
							mapp(Current,final);
							Travel(direction);
							dropit();
							nearest_row_select();
							break;
							case 12:
							deposit_point(BLUE);
							mapp(Current,final);
							Travel(direction);
							dropit();
							nearest_row_select();
							break;
						}
						mapp(Current,final);
						Travel(direction);
						break;
					}
					else
					{
						Current->flag=1;
						if (color==-1)
						{
							buzzer_on();
							_delay_ms(1000);
							buzzer_off();
						}
					}
					
				}
			}
			else
			{
				Goto(7+2*i,0);
				if (Current->flag==0)
				{
					MakeDirection(3);
					_delay_ms(500);
					color=check_for_box();
					//back_mm(30);
					if (color>0)
					{
						switch(color)
						{
							case 10:
							deposit_point(RED);
							mapp(Current,final);
							Travel(direction);
							dropit();
							nearest_row_select();
							break;
							case 11:
							deposit_point(GREEN);
							mapp(Current,final);
							Travel(direction);
							dropit();
							nearest_row_select();
							break;
							case 12:
							deposit_point(BLUE);
							mapp(Current,final);
							Travel(direction);
							dropit();
							nearest_row_select();
							break;
						}
						mapp(Current,final);
						Travel(direction);
						break;
					}
					else
					{
						Current->flag=1;
						if (color==-1)
						{
							buzzer_on();
							_delay_ms(1000);
							buzzer_off();
						}
					}
					

				}
			}
			
			
		}
	}
	
	
	
	
	
	else if (Current->YPOS==8)
	{
		for (int i=1;i<=3;i++)
		{
			if (obj[5][8].flag==0 || obj[3][8].flag==0 || obj[1][8].flag==0)
			{
				Goto(7-2*i,8);
				if (Current->flag==0)
				{
					MakeDirection(1);
					_delay_ms(500);
					color=check_for_box();
					//back_mm(20);
					if (color>0)
					{
						switch(color)
						{
							
							case 10:
							deposit_point(RED);
							mapp(Current,final);
							Travel(direction);
							dropit();
							nearest_row_select();
							break;
							case 11:
							deposit_point(GREEN);
							mapp(Current,final);
							Travel(direction);
							dropit();
							nearest_row_select();
							break;
							case 12:
							deposit_point(BLUE);
							mapp(Current,final);
							Travel(direction);
							dropit();
							nearest_row_select();
							break;
						}
						mapp(Current,final);
						Travel(direction);
						break;
					}
					else
					{
						Current->flag=1;
						if (color==-1)
						{
							buzzer_on();
							_delay_ms(1000);
							buzzer_off();
						}
					}
					

				}
			}
			else
			{
				Goto(7+2*i,8);
				if (Current->flag==0)
				{
					MakeDirection(1);
					_delay_ms(500);
					color=check_for_box();
					//back_mm(20);
					if (color>0)
					{
						switch(color)
						{
							
							case 10:
							deposit_point(RED);
							mapp(Current,final);
							Travel(direction);
							dropit();
							nearest_row_select();
							break;
							case 11:
							deposit_point(GREEN);
							mapp(Current,final);
							Travel(direction);
							dropit();
							nearest_row_select();
							break;
							case 12:
							deposit_point(BLUE);
							mapp(Current,final);
							Travel(direction);
							dropit();
							nearest_row_select();
							break;
						}
						mapp(Current,final);
						Travel(direction);
						break;
					}
					else
					{
						Current->flag=1;
						if (color==-1)
						{
							buzzer_on();
							_delay_ms(1000);
							buzzer_off();
						}
					}
					

				}
			}
			
			
		}
	}
	
	
}





void Left()
{
	//line_check();
	left_degrees(90);
	//line_check();
	if(dir==1)
	{
		dir=4;
	}
	else
	{
		dir--;
	}
	
}

void Right()
{
//	line_check();
	right_degrees(90);
	
	//line_check();
	if(dir==4)
	{
		dir=1;
	}
	else
	{
		dir++;
	}
}

void Move()
{
	
	switch(dir)
	{
		case 1:
		{
			
			
			if (Current->type=='c')
			{
				stepmove(12);
			}
			else if(Current->type=='v')
			{
				if(Current->N->type=='v') stepmove(24);
				else if(Current->N->type=='c') stepmove(12);
			}
			else if(Current->type=='h')
			{
				stepmove(12);
			}
			else if(Current->type=='j')
			{
				if(Current->N->type=='h')
				{
					stepmove(12);
				}
				else stepmove(6);
			}
			else if(Current->type=='s' || Current->type=='S')
			{
				stepmove(6);
			}
			Current=Current->N;
			break;
		}
		case 2:
		{
			
			if (Current->type=='c')
			{
				stepmove(9);
			}
			else if(Current->type=='v')
			{
				stepmove(12);
			}
			else if(Current->type=='h')
			{
				stepmove(9);
			}
			else if(Current->type=='j')
			{
				stepmove(12);
			}
			else if(Current->type=='s')
			{
				if(Current->E->type=='S') stepmove(6);
				else stepmove(12);
			}
			else if(Current->type=='S')
			{
				stepmove(6);
			}
			Current=Current->E;
			break;
		}
		case 3:
			{
				
				if (Current->type=='c')
				{
					stepmove(12);
				}
				else if(Current->type=='v')
				{
					if(Current->S->type=='v') stepmove(24);
					else if(Current->S->type=='c') stepmove(12);
				}
				else if(Current->type=='h')
				{
					stepmove(12);
				}
				else if(Current->type=='j')
				{
					if(Current->S->type=='h')
					{
						stepmove(12);
					}
					else stepmove(6);
				}
				else if(Current->type=='s')
				{
					stepmove(6);
				}
				Current=Current->S;
				break;
			}
		case 4:
			{
				if (Current->type=='c')
				{
					stepmove(9);
				}
				else if(Current->type=='v')
				{
					stepmove(12);
				}
				else if(Current->type=='h')
				{
					stepmove(9);
				}
				else if(Current->type=='j')
				{
					stepmove(12);
				}
				else if(Current->type=='s')
				{
					if(Current->W->type=='S') stepmove(6);
					else stepmove(12);
				}
				else if(Current->type=='S')
				{
					stepmove(6);
				}
				Current=Current->W;
				break;
			}
	}
	
}
void line_check()
{
	
	while(1)
	{
		Left_white_line = ADC_Conversion(3);	//Getting data of Left WL Sensor
		Center_white_line = ADC_Conversion(2);	//Getting data of Center WL Sensor
		Right_white_line = ADC_Conversion(1);	//Getting data of Right WL Sensor
		if((Left_white_line<15 && Center_white_line<15))// && (flag==0))
		{
			
			flag=1;
			right();
			velocity(150,150);
			while(Center_white_line<70)
			{
				Center_white_line = ADC_Conversion(2);
			}
			break;
			//forward();
			//velocity(200,50);
		}

		 else if((Right_white_line<15 && Center_white_line<15))// && (flag==1))
		{
			flag=0;
			left();
			velocity(150,150);
			while(Center_white_line<70)
			{
				Center_white_line = ADC_Conversion(2);
			}
			break;
		}
		 else if (Left_white_line>20)// && flag==1)
		{
			flag=0;
			left();
			velocity(150,150);
			while(Center_white_line<70)
			{
				Center_white_line = ADC_Conversion(2);
			}
			break;
		}
		 else if (Right_white_line>20)// && flag==0)
		{
			flag=1;
			right();
			velocity(150,150);
			while(Center_white_line<70)
			{
				Center_white_line = ADC_Conversion(2);
			}
			break;
		}
		else if(Left_white_line<15 && Right_white_line<15 && Center_white_line <15 && flag==1)
		{
			left();	
			velocity(150,150);
			while(Center_white_line<70)
			{
				Center_white_line = ADC_Conversion(2);
			}
			break;
		}
		else if(Left_white_line<15 && Right_white_line<15 && Center_white_line <15 && flag==0)
		{
			right();
			velocity(150,150);
			while(Center_white_line<70)
			{
				Center_white_line = ADC_Conversion(2);
			}
			break;
		}
		else break;
				
		
	}
	flag=0;
	velocity(200,200);
	
}

void stepmove(int a)
{
	
		for (int i=0;i<30*a;i++)
		{
			_delay_ms(1);
			forward_mm(1);
			_delay_ms(2);
			line_check();
			DDRJ=0xff;
			//PORTJ=i+1;
			if (checknode())
			{

				move_after_node();
				break;
			}
		}
	
	
}
int check_for_box()
{
	Front_Sharp_Sensor = ADC_Conversion(11);//Getting data of front sharp ir Sensor
	
	if(Front_Sharp_Sensor>SHARP_THRESHOLD)
	{
		PickupPointXpos = Current->XPOS;
		PickupPointYpos = Current->YPOS;
		
		red_read(); //display the pulse count when red filter is selected
		_delay_ms(500);
		green_read(); //display the pulse count when green filter is selected
		_delay_ms(500);
		blue_read(); //display the pulse count when blue filter is selected
		_delay_ms(500);
		if ((Red>Blue)&&(Red>Green)&&(Red>THRESHOLD))
		{
			lcd_wr_command(0x01);
			lcd_string("Result= RED");
			if (r_counter<=2*red_count)
			{
				pickup();
				r_counter++;
				return(10);
				_delay_ms(500);
			}
			else return 0;
			
			
			
		
		}
		else if ((Blue>Red)&&(Blue>Green)&&(Blue>THRESHOLD))
		{
			lcd_wr_command(0x01);
			lcd_string("Result= BLUE");
			if (b_counter<=2*blue_count )
			{
				pickup();
				b_counter++;
				return(12);
				_delay_ms(500);
			}
			else return 0;
			
		}
		else if ((Green>Red)&&(Green>Blue)&&(Green>THRESHOLD))
		{
			lcd_wr_command(0x01);
			lcd_string("Result= GREEN");
			if (g_counter<=2*green_count )
			{
				pickup();
				g_counter++;
				return(11);
				
				_delay_ms(500);
			}
			else return 0;
			
		}
		else if((Green<THRESHOLD)&&(Red<THRESHOLD)&&(Blue<THRESHOLD))
		{
			lcd_wr_command(0x01);
			lcd_string("Result= BLACK");
			
			//buzzers on for 1 sec
			return(-1);
			_delay_ms(500);
		}
		lcd_wr_command(0x01);
	}
		
	else return 0;
}

int checknode()
{
	Left_white_line = ADC_Conversion(3);	//Getting data of Left WL Sensor
	Center_white_line = ADC_Conversion(2);	//Getting data of Center WL Sensor
	Right_white_line = ADC_Conversion(1);	//Getting data of Right WL Sensor
	if((Left_white_line>TH_LEFT &&Center_white_line>TH_CENTER)||(Center_white_line>TH_CENTER&& Right_white_line>TH_RIGHT)||(Right_white_line>TH_RIGHT &&Center_white_line>TH_CENTER&&Left_white_line>TH_LEFT))//||(Center_white_line>TH_CENTER01))
	{
		DDRJ=0xFF;
		PORTJ=0x80;
		return 1;
	}
	else return 0;	
}
void dropit()
{  
	if(Current->XPOS==2 || Current->XPOS==10)
	{
		MakeDirectionExclusivelyForDropPoint(2);
	}
	else if(Current->XPOS==4 || Current->XPOS==13)
	{
		
		MakeDirectionExclusivelyForDropPoint(4);
	}
	else if(Current->YPOS==3)
	{
		MakeDirectionExclusivelyForDropPoint(1);
	}
	else if (Current->YPOS==5)
	{
		MakeDirectionExclusivelyForDropPoint(3);
	}
	back_mm(30);
	servo_1(100);
	_delay_ms(1000);
	servo_2(100);
	
	
	_delay_ms(1000);
	
	_delay_ms(1000);
	servo_1(180);
	_delay_ms(1000);
	servo_1_free();
	servo_2_free();
	Current->flag=1;
	obj[PickupPointXpos][PickupPointYpos].flag=1;
	//back_mm(30);
	
	
}

void move_after_node()
{
	motion_set(0x06);
	velocity(240,230);
	linear_distance_mm(80);
	
}
int size_of_array(int arr[])
{
	int i=0;
	while(arr[i]!=99)
	{
		i++;
	}
	return(i);
}
