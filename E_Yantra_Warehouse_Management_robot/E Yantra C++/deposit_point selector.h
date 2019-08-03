/*
*
* Team Id: eYRC#2467-WM
* Author List:Ankit Kumar
* Filename: deposit_point selector.h
* Theme: 	Warehouse Management	
* Functions: int smallest_location(int a[]),map * final_point(int),void deposit_point(int a[])
* Global Variables:	NULL
*
*/
	
	
	
	/**************************************************************************
	* Function Name:deposit_point(int a[])
	* Input: a[] -> Integer array  like RED, GREEN,BLUE which stores the deposition zone numbers for the respective color
	* Output:		Decides the nearest deposition point for depositng the color whose array is being passed as argument
	* Logic:		calculates linear displacement between all the points of the specified deposiion zones and selects 
	*				the point with least distance and assigns to final vaiable.
	* Example Call:	deposit_point(RED)
	*
	**************************************************************************/
    /**************************************************************************
	* Function Name:smallest_location(int a[])
	* Input: a[] -> Integer array which stores the disatnces of all deposition zone points. 
	* Output:		returns the location of smallest element in the array passed as argument.
	* Logic:		keeps comparing the values of each element and storing the location of smallest 
	*               element in a local variable being returned.
	* Example Call:	smallest_location(ptr)
	*
	**************************************************************************/
	/**************************************************************************
	* Function Name:map * final_point(int);
	* Input: a[] -> Integer array which stores the disatnces of all deposition zone points. 
	* Output:		returns the nearest point's object pointer e.g obj[7][8]
	* Logic:		keeps comparing the values of each element and storing the location of smallest 
	*               element in a local variable being returned.
	* Example Call:	final=map * final_point(int);
	*
	**************************************************************************/
	
	#include<stdio.h>
    #include<math.h>
    

        
    int smallest_location(int a[]);
    map * final_point(int);
	
    
    
    void deposit_point(int a[])
    {
        //decides final deposition point after considering all the points of the given depostion zones for a particular color box
    	//calulates a rough distance between pickup and all possible deposition points and selects the nearest one.
	
        int temp1,temp2,loc,i=0;
        int ptr[11]={99,99,99,99,99,99,99,99,99,99};//pre-initialised array which stores the calculated distances 
													//from each deposition point 
        
        for(i=0;i<3;i++)
        {
         switch(a[i]){
                      case 1:
                      
                          temp1=fabs(Current->XPOS-2) +fabs(Current->YPOS-2);//calculating approx linear distance b/w current location point and  
                          temp2=fabs(Current->XPOS-4) +fabs(Current->YPOS-2);//deposition zone points
                         if(temp1<=temp2)
                         {
                          
                            ptr[0]=temp1;             
                         }
                         else
                         { 
                           ptr[1]=temp2;    
                         }
                          
                         break;   
                         
                      case 2:
                      
                          temp1=fabs(Current->XPOS-10) + fabs(Current->YPOS-2);//calculating approx linear distance b/w current location point and 
                          temp2=fabs(Current->XPOS-12)+ fabs(Current->YPOS-2);//deposition zone points
                         if(temp1<=temp2)
                         {  
                            ptr[2]=temp1;             
                         }
                         else
                         {  
                              ptr[3]=temp2;    
                         }
                          break;   
                      
                      case(3):
                      
                          temp1=fabs(Current->XPOS-2) +fabs(Current->YPOS-6);
                          temp2=fabs(Current->XPOS-4 )+fabs(Current->YPOS-6);
                         if(temp1<=temp2)
                         {
                            ptr[4]=temp1;             
                         }
                         else
                         {  
                             ptr[5]=temp2;    
                         }
                             break;
                      
                      case(4):
                      
                          temp1=fabs(Current->XPOS-10) +fabs(Current->YPOS-6);
                          temp2=fabs(Current->XPOS-12) +fabs(Current->YPOS-6);
                         if(temp1<=temp2)
                         {  
                            ptr[6]=temp1;             
                         }
                         else
                          {
							ptr[7]=temp2;    
                          }
                          break;
                             
                      
                      case(5):
                      
                          temp1=fabs(Current->XPOS-7) +fabs(Current->YPOS-3);
                          temp2=fabs(Current->XPOS-7) +fabs(Current->YPOS-5);
                         
                         if(temp1<=temp2)
                         {
                            
                            ptr[8]=temp1;             
                         }
                         else
                         {  
                              ptr[9]=temp2;    
                           
                         }
                         break;
         }            
         
        }
    
    loc=smallest_location(ptr);
    final=final_point(loc); 
    
        
    }    
     
                     
    
    
    int smallest_location(int a[])
    {   //gives the location of the smallest element of the array passed
         
         int num=999;
         int loc=0,j=0;
         
         
     while(a[j]!='\0')
     {
         
         if(a[j]<=num)
         {
          num=a[j];
          loc=j;          
         }
         j++; 
     }
    
    return(loc);//return location of the smallest element in the array.
    }
    
    map * final_point(int loc) 
    {	//returns final point object with least distance from the current position.
         
        switch(loc){
                    case 0:
                         
    					 return(&obj[2][2]);//return the object representing the point (2,2) in the map
                         
                    case 1:
                         
                         return(&obj[4][2]);
                    case 2:
                         
    					 return(&obj[10][2]);
                         
                    case 3:
                         
    					 return(&obj[12][2]);
                         
                    case 4:
                         
    					 return(&obj[2][6]);
                         
                    case 5:
                         
    					 return(&obj[4][6]);
                         
                    case 6:
                         
    					 return(&obj[10][6]);
                         
                    case 7:
                         
    					 return(&obj[12][6]);
                         
                    case 8:
                         
    					 return(&obj[7][3]);
                         
                    case 9:
                         
    					 return(&obj[7][5]);
                         }
    }
    void nearest_row_select()
    {	//selects the nearest pickup row to start search again after depositing a box to deposition point.
    	
         if((8-Current->YPOS<=4)&&((obj[1][8].flag==0)||(obj[3][8].flag==0)||(obj[5][8].flag==0)||(obj[9][8].flag==0)||(obj[11][8].flag==0)||(obj[13][8].flag==0)))
         {
            final=&obj[7][8];
    		
    		
         } 
         else if((obj[1][0].flag==0)||(obj[3][0].flag==0)||(obj[5][0].flag==0)||(obj[9][0].flag==0)||(obj[11][0].flag==0)||(obj[13][0].flag==0))
         {
    		final=&obj[7][0];
    	 }
    	
    	
    }
    
