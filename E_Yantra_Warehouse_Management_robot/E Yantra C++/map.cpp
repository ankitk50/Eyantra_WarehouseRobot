/*
*
* Team Id: eYRC#2467-WM
* Author-Abhishek Bohra
* Filename: mapp.cpp
* Theme: 	Warehouse Management
* Functions: mapinit(),allocate_moore_value(),mapp(map*,map*),MooreValueAssignerUsingRecursion(map *ptr,map *final,int i,char ch),InitialiseMorreTo100(),directionfetcher().
* Global Variables:	direction[],obj[20][20],objNULL.
*
*/


/************************************************************************/
/* Function Name: mapinit()
/* Input:Null
/* Output:Initializes various properties(like type,xpost,ypos,moore_value) of different points
/* Logic: Simple assignment 
/* Example Call: mapinit()                                                              */
/************************************************************************/

/************************************************************************/
/* Function Name: allocate_moore_value(map *,map *)
/* Input:Two points,starting and final
/* Output: Moore_values of different point are allocated as to make an easiest path.
/* Logic:call functions InitialiseMooreValuesTo100() and MooreValueAssignerUsingRecursion(initial,final,i,'i')
/* Example Call: allocate_moore_value(Current,Final)                                                              */
/************************************************************************/

/************************************************************************/
/* Function Name: directionfetcher(map *, map*)
/* Input: Takes initial and final point
/* Output: Builds a direction array which has contains the direction required to travel from on position to other
/* Logic: Starts from the final point. Takes its moore_value and searches for the moore_less than that around that point. After finding one such point it stores the direction in the array. Now the next found point will go through the same process the final point went. This will go until the initial point is encountered. The direction array is built in the reverse order.
/* Example Call: directionfetcher(initial,final) is called in mapp(initial,final) where the array is corrected to straight order.                                                              */
/************************************************************************/

/************************************************************************/
/* Function Name: InitialiseMooreValueTo100
/* Input: Null
/* Output: Assigns 100 to the moore_value of every point.
/* Logic: As 100 cannot be reached ,it helps in carrying out assigning of correct Moore value
/* Example Call: InitialiseMooreValueTo100                                                               */
/************************************************************************/

/************************************************************************/
/* Function Name: MooreValueAssignerUsingRecursion(map*,map*,int,char)
/* Input:The parameters are (from Left to Right in order) Initiator point Point(ptr),Final Point(final), Moore_value of the initiator point(i), the opposite direction from which initiator was pointed.
/* Output:Assigns moore_values
/* Logic: It is assigning values using Moore's BFS algorithm.
/* Example Call: void MooreValueAssignerUsingRecursion(Current->N,final,2,s)                                                               */
/************************************************************************/

/************************************************************************/
/* Function Name: mapp(map*,map*)
/* Input:First argument is the current position of the bot, next is the destination(final point)
/* Output:Builds the global array direction[]
/* Logic: It calls allocate_moore_value(), directionfetcher(), calculates the step(The Moore_Value of the final point) corrects the reverse direction array
/* Example Call: mapp(initial,final).                                                               */
/************************************************************************/











#define Column 15
#define Row 9



struct map{
	int moore_value;
	int flag;
	char type; //V,H,S,I,c
	int XPOS,YPOS;
	struct map *N;
	struct map *E;
	struct map *S;
	struct map *W;
	
}obj[20][20],objNULL;

map *objNULLptr = &objNULL;

void MooreValueAssignerUsingRecursion(map*,map*,int,char);
void allocate_moore_value(map *,map *);
void InitialiseMooreValuesTo100();
int* directionfetcher(map *,map *);
//For Debugging only ==> void displaymoore();

map *Start,*Current,*initial;
map *final;
int steps;
int direction[99];;

void mapinit()
{
	
	
	{
		
	
		obj[0][0].type='c';
		obj[0][0].N=&obj[0][2];
		obj[0][0].E=&obj[1][0];
		obj[0][0].S=&objNULL;
		obj[0][0].W=&objNULL;
		obj[0][1].type='i';
		obj[0][1].N=&objNULL;
		obj[0][1].E=&objNULL;
		obj[0][1].W=&objNULL;
		obj[0][1].S=&objNULL;
		obj[0][2].type='v';
		obj[0][2].N=&obj[0][6];
		obj[0][2].E=&obj[2][2];
		obj[0][2].S=&obj[0][0];
		obj[0][2].W=&objNULL;
		obj[0][3].type='i';
		obj[0][3].N=&objNULL;
		obj[0][3].E=&objNULL;
		obj[0][3].W=&objNULL;
		obj[0][3].S=&objNULL;
		obj[0][4].type='i';
		obj[0][4].N=&objNULL;
		obj[0][4].E=&objNULL;
		obj[0][4].W=&objNULL;
		obj[0][4].S=&objNULL;
		obj[0][5].type='i';
		obj[0][5].N=&objNULL;
		obj[0][5].E=&objNULL;
		obj[0][5].W=&objNULL;
		obj[0][5].S=&objNULL;
		obj[0][6].type='v';
		obj[0][6].N=&obj[0][8];
		obj[0][6].E=&obj[2][6];
		obj[0][6].S=&obj[0][2];
		obj[0][6].W=&objNULL;
		obj[0][7].type='i';
		obj[0][7].N=&objNULL;
		obj[0][7].E=&objNULL;
		obj[0][7].W=&objNULL;
		obj[0][7].S=&objNULL;
		obj[0][8].type='c';
		obj[0][8].N=&objNULL;
		obj[0][8].E=&obj[1][8];
		obj[0][8].S=&obj[0][6];
		obj[0][8].W=&objNULL;
		obj[1][0].type='h';
		obj[1][0].N=&objNULL;
		obj[1][0].E=&obj[3][0];
		obj[1][0].S=&objNULL;
		obj[1][0].W=&obj[0][0];
		obj[1][1].type='i';
		obj[1][1].N=&objNULL;
		obj[1][1].E=&objNULL;
		obj[1][1].W=&objNULL;
		obj[1][1].S=&objNULL;
		obj[1][2].type='i';
		obj[1][2].N=&objNULL;
		obj[1][2].E=&objNULL;
		obj[1][2].W=&objNULL;
		obj[1][2].S=&objNULL;
		obj[1][3].type='i';
		obj[1][3].N=&objNULL;
		obj[1][3].E=&objNULL;
		obj[1][3].W=&objNULL;
		obj[1][3].S=&objNULL;
		obj[1][4].type='i';
		obj[1][4].N=&objNULL;
		obj[1][4].E=&objNULL;
		obj[1][4].W=&objNULL;
		obj[1][4].S=&objNULL;
		obj[1][5].type='i';
		obj[1][5].N=&objNULL;
		obj[1][5].E=&objNULL;
		obj[1][5].W=&objNULL;
		obj[1][5].S=&objNULL;
		obj[1][6].type='i';
		obj[1][6].N=&objNULL;
		obj[1][6].E=&objNULL;
		obj[1][6].W=&objNULL;
		obj[1][6].S=&objNULL;
		obj[1][7].type='i';
		obj[1][7].N=&objNULL;
		obj[1][7].E=&objNULL;
		obj[1][7].W=&objNULL;
		obj[1][7].S=&objNULL;
		obj[1][8].type='h';
		obj[1][8].N=&objNULL;
		obj[1][8].E=&obj[3][8];
		obj[1][8].S=&objNULL;
		obj[1][8].W=&obj[0][8];
		obj[2][0].type='i';
		obj[2][0].N=&objNULL;
		obj[2][0].E=&objNULL;
		obj[2][0].W=&objNULL;
		obj[2][0].S=&objNULL;
		obj[2][1].type='s';
		obj[2][1].N=&obj[2][2];
		obj[2][1].E=&obj[4][1];
		obj[2][1].S=&objNULL;
		obj[2][1].W=&objNULL;
		obj[2][2].type='s';
		obj[2][2].N=&obj[2][3];
		obj[2][2].E=&objNULL;
		obj[2][2].S=&obj[2][1];
		obj[2][2].W=&obj[0][2];
		obj[2][3].type='s';
		obj[2][3].N=&objNULL;
		obj[2][3].E=&obj[3][3];
		obj[2][3].S=&obj[2][2];
		obj[2][3].W=&objNULL;
		obj[2][4].type='i';
		obj[2][4].N=&objNULL;
		obj[2][4].E=&objNULL;
		obj[2][4].W=&objNULL;
		obj[2][4].S=&objNULL;
		obj[2][5].type='s';
		obj[2][5].N=&obj[2][6];
		obj[2][5].E=&obj[3][5];
		obj[2][5].S=&objNULL;
		obj[2][5].W=&objNULL;
		obj[2][6].type='s';
		obj[2][6].N=&obj[2][7];
		obj[2][6].E=&objNULL;
		obj[2][6].S=&obj[2][5];
		obj[2][6].W=&obj[0][6];
		obj[2][7].type='s';
		obj[2][7].N=&objNULL;
		obj[2][7].E=&obj[4][7];
		obj[2][7].S=&obj[2][6];
		obj[2][7].W=&objNULL;
		obj[2][8].type='i';
		obj[2][8].N=&objNULL;
		obj[2][8].E=&objNULL;
		obj[2][8].W=&objNULL;
		obj[2][8].S=&objNULL;
		obj[3][0].type='h';
		obj[3][0].N=&objNULL;
		obj[3][0].E=&obj[5][0];
		obj[3][0].S=&objNULL;
		obj[3][0].W=&obj[1][0];
		obj[3][1].type='i';
		obj[3][1].N=&objNULL;
		obj[3][1].E=&objNULL;
		obj[3][1].W=&objNULL;
		obj[3][1].S=&objNULL;
		obj[3][2].type='i';
		obj[3][2].N=&objNULL;
		obj[3][2].E=&objNULL;
		obj[3][2].W=&objNULL;
		obj[3][2].S=&objNULL;
		obj[3][3].type='s';
		obj[3][3].N=&obj[3][4];
		obj[3][3].E=&obj[4][3];
		obj[3][3].S=&objNULL;
		obj[3][3].W=&obj[2][3];
		obj[3][4].type='j';
		obj[3][4].N=&obj[3][5];
		obj[3][4].E=&obj[6][4];
		obj[3][4].S=&obj[3][3];
		obj[3][4].W=&objNULL;
		obj[3][5].type='s';
		obj[3][5].N=&objNULL;
		obj[3][5].E=&obj[4][5];
		obj[3][5].S=&obj[3][4];
		obj[3][5].W=&obj[2][5];
		obj[3][6].type='i';
		obj[3][6].N=&objNULL;
		obj[3][6].E=&objNULL;
		obj[3][6].W=&objNULL;
		obj[3][6].S=&objNULL;
		obj[3][7].type='i';
		obj[3][7].N=&objNULL;
		obj[3][7].E=&objNULL;
		obj[3][7].W=&objNULL;
		obj[3][7].S=&objNULL;
		obj[3][8].type='h';
		obj[3][8].N=&objNULL;
		obj[3][8].E=&obj[5][8];
		obj[3][8].S=&objNULL;
		obj[3][8].W=&obj[1][8];
		obj[4][0].type='i';
		obj[4][0].N=&objNULL;
		obj[4][0].E=&objNULL;
		obj[4][0].W=&objNULL;
		obj[4][0].S=&objNULL;
		obj[4][1].type='s';
		obj[4][1].N=&obj[4][2];
		obj[4][1].E=&objNULL;
		obj[4][1].S=&objNULL;
		obj[4][1].W=&obj[2][1];
		obj[4][2].type='s';
		obj[4][2].N=&obj[4][3];
		obj[4][2].E=&obj[7][2];
		obj[4][2].S=&obj[4][1];
		obj[4][2].W=&objNULL;
		obj[4][3].type='s';
		obj[4][3].N=&objNULL;
		obj[4][3].E=&objNULL;
		obj[4][3].S=&obj[4][2];
		obj[4][3].W=&obj[3][3];
		obj[4][4].type='i';
		obj[4][4].N=&objNULL;
		obj[4][4].E=&objNULL;
		obj[4][4].W=&objNULL;
		obj[4][4].S=&objNULL;
		obj[4][5].type='s';
		obj[4][5].N=&obj[4][6];
		obj[4][5].E=&objNULL;
		obj[4][5].S=&objNULL;
		obj[4][5].W=&obj[3][5];
		obj[4][6].type='s';
		obj[4][6].N=&obj[4][7];
		obj[4][6].E=&obj[7][6];
		obj[4][6].S=&obj[4][5];
		obj[4][6].W=&objNULL;
		obj[4][7].type='s';
		obj[4][7].N=&objNULL;
		obj[4][7].E=&objNULL;
		obj[4][7].S=&obj[4][6];
		obj[4][7].W=&obj[2][7];
		obj[4][8].type='i';
		obj[4][8].N=&objNULL;
		obj[4][8].E=&objNULL;
		obj[4][8].W=&objNULL;
		obj[4][8].S=&objNULL;
		obj[5][0].type='h';
		obj[5][0].N=&objNULL;
		obj[5][0].E=&obj[7][0];
		obj[5][0].S=&objNULL;
		obj[5][0].W=&obj[3][0];
		obj[5][1].type='i';
		obj[5][1].N=&objNULL;
		obj[5][1].E=&objNULL;
		obj[5][1].W=&objNULL;
		obj[5][1].S=&objNULL;
		obj[5][2].type='i';
		obj[5][2].N=&objNULL;
		obj[5][2].E=&objNULL;
		obj[5][2].W=&objNULL;
		obj[5][2].S=&objNULL;
		obj[5][3].type='i';
		obj[5][3].N=&objNULL;
		obj[5][3].E=&objNULL;
		obj[5][3].W=&objNULL;
		obj[5][3].S=&objNULL;
		obj[5][4].type='i';
		obj[5][4].N=&objNULL;
		obj[5][4].E=&objNULL;
		obj[5][4].W=&objNULL;
		obj[5][4].S=&objNULL;
		obj[5][5].type='i';
		obj[5][5].N=&objNULL;
		obj[5][5].E=&objNULL;
		obj[5][5].W=&objNULL;
		obj[5][5].S=&objNULL;
		obj[5][6].type='i';
		obj[5][6].N=&objNULL;
		obj[5][6].E=&objNULL;
		obj[5][6].W=&objNULL;
		obj[5][6].S=&objNULL;
		obj[5][7].type='i';
		obj[5][7].N=&objNULL;
		obj[5][7].E=&objNULL;
		obj[5][7].W=&objNULL;
		obj[5][7].S=&objNULL;
		obj[5][8].type='h';
		obj[5][8].N=&objNULL;
		obj[5][8].E=&obj[7][8];
		obj[5][8].S=&objNULL;
		obj[5][8].W=&obj[3][8];
		obj[6][0].type='i';
		obj[6][0].N=&objNULL;
		obj[6][0].E=&objNULL;
		obj[6][0].W=&objNULL;
		obj[6][0].S=&objNULL;
		obj[6][1].type='i';
		obj[6][1].N=&objNULL;
		obj[6][1].E=&objNULL;
		obj[6][1].W=&objNULL;
		obj[6][1].S=&objNULL;
		obj[6][2].type='i';
		obj[6][2].N=&objNULL;
		obj[6][2].E=&objNULL;
		obj[6][2].W=&objNULL;
		obj[6][2].S=&objNULL;
		obj[6][3].type='s';
		obj[6][3].N=&obj[6][4];
		obj[6][3].E=&obj[7][3];
		obj[6][3].S=&objNULL;
		obj[6][3].W=&objNULL;
		obj[6][4].type='s';
		obj[6][4].N=&obj[6][5];
		obj[6][4].E=&objNULL;
		obj[6][4].S=&obj[6][3];
		obj[6][4].W=&obj[3][4];
		obj[6][5].type='s';
		obj[6][5].N=&objNULL;
		obj[6][5].E=&obj[7][5];
		obj[6][5].S=&obj[6][4];
		obj[6][5].W=&objNULL;
		obj[6][6].type='i';
		obj[6][6].N=&objNULL;
		obj[6][6].E=&objNULL;
		obj[6][6].W=&objNULL;
		obj[6][6].S=&objNULL;
		obj[6][7].type='i';
		obj[6][7].N=&objNULL;
		obj[6][7].E=&objNULL;
		obj[6][7].W=&objNULL;
		obj[6][7].S=&objNULL;
		obj[6][8].type='i';
		obj[6][8].N=&objNULL;
		obj[6][8].E=&objNULL;
		obj[6][8].W=&objNULL;
		obj[6][8].S=&objNULL;
		obj[7][0].type='h';
		obj[7][0].N=&obj[7][2];
		obj[7][0].E=&obj[9][0];
		obj[7][0].S=&objNULL;
		obj[7][0].W=&obj[5][0];
		obj[7][1].type='i';
		obj[7][1].N=&objNULL;
		obj[7][1].E=&objNULL;
		obj[7][1].W=&objNULL;
		obj[7][1].S=&objNULL;
		obj[7][2].type='j';
		obj[7][2].N=&obj[7][3];
		obj[7][2].E=&obj[10][2];
		obj[7][2].S=&obj[7][0];
		obj[7][2].W=&obj[4][2];
		obj[7][3].type='s';
		obj[7][3].N=&objNULL;
		obj[7][3].E=&obj[8][3];
		obj[7][3].S=&obj[7][2];
		obj[7][3].W=&obj[6][3];
		obj[7][4].type='i';
		obj[7][4].N=&objNULL;
		obj[7][4].E=&objNULL;
		obj[7][4].W=&objNULL;
		obj[7][4].S=&objNULL;
		obj[7][5].type='s';
		obj[7][5].N=&obj[7][6];
		obj[7][5].E=&obj[8][5];
		obj[7][5].S=&objNULL;
		obj[7][5].W=&obj[6][5];
		obj[7][6].type='j';
		obj[7][6].N=&obj[7][8];
		obj[7][6].E=&obj[10][6];
		obj[7][6].S=&obj[7][5];
		obj[7][6].W=&obj[4][6];
		obj[7][7].type='i';
		obj[7][7].N=&objNULL;
		obj[7][7].E=&objNULL;
		obj[7][7].W=&objNULL;
		obj[7][7].S=&objNULL;
		obj[7][8].type='h';
		obj[7][8].N=&objNULL;
		obj[7][8].E=&obj[9][8];
		obj[7][8].S=&obj[7][6];
		obj[7][8].W=&obj[5][8];
		obj[8][0].type='i';
		obj[8][0].N=&objNULL;
		obj[8][0].E=&objNULL;
		obj[8][0].W=&objNULL;
		obj[8][0].S=&objNULL;
		obj[8][1].type='i';
		obj[8][1].N=&objNULL;
		obj[8][1].E=&objNULL;
		obj[8][1].W=&objNULL;
		obj[8][1].S=&objNULL;
		obj[8][2].type='i';
		obj[8][2].N=&objNULL;
		obj[8][2].E=&objNULL;
		obj[8][2].W=&objNULL;
		obj[8][2].S=&objNULL;
		obj[8][3].type='s';
		obj[8][3].N=&obj[8][4];
		obj[8][3].E=&objNULL;
		obj[8][3].S=&objNULL;
		obj[8][3].W=&obj[7][3];
		obj[8][4].type='s';
		obj[8][4].N=&obj[8][5];
		obj[8][4].E=&obj[11][4];
		obj[8][4].S=&obj[8][3];
		obj[8][4].W=&objNULL;
		obj[8][5].type='s';
		obj[8][5].N=&objNULL;
		obj[8][5].E=&objNULL;
		obj[8][5].S=&obj[8][4];
		obj[8][5].W=&obj[7][5];
		obj[8][6].type='i';
		obj[8][6].N=&objNULL;
		obj[8][6].E=&objNULL;
		obj[8][6].W=&objNULL;
		obj[8][6].S=&objNULL;
		obj[8][7].type='i';
		obj[8][7].N=&objNULL;
		obj[8][7].E=&objNULL;
		obj[8][7].W=&objNULL;
		obj[8][7].S=&objNULL;
		obj[8][8].type='i';
		obj[8][8].N=&objNULL;
		obj[8][8].E=&objNULL;
		obj[8][8].W=&objNULL;
		obj[8][8].S=&objNULL;
		obj[9][0].type='h';
		obj[9][0].N=&objNULL;
		obj[9][0].E=&obj[11][0];
		obj[9][0].S=&objNULL;
		obj[9][0].W=&obj[7][0];
		obj[9][1].type='i';
		obj[9][1].N=&objNULL;
		obj[9][1].E=&objNULL;
		obj[9][1].W=&objNULL;
		obj[9][1].S=&objNULL;
		obj[9][2].type='i';
		obj[9][2].N=&objNULL;
		obj[9][2].E=&objNULL;
		obj[9][2].W=&objNULL;
		obj[9][2].S=&objNULL;
		obj[9][3].type='i';
		obj[9][3].N=&objNULL;
		obj[9][3].E=&objNULL;
		obj[9][3].W=&objNULL;
		obj[9][3].S=&objNULL;
		obj[9][4].type='i';
		obj[9][4].N=&objNULL;
		obj[9][4].E=&objNULL;
		obj[9][4].W=&objNULL;
		obj[9][4].S=&objNULL;
		obj[9][5].type='i';
		obj[9][5].N=&objNULL;
		obj[9][5].E=&objNULL;
		obj[9][5].W=&objNULL;
		obj[9][5].S=&objNULL;
		obj[9][6].type='i';
		obj[9][6].N=&objNULL;
		obj[9][6].E=&objNULL;
		obj[9][6].W=&objNULL;
		obj[9][6].S=&objNULL;
		obj[9][7].type='i';
		obj[9][7].N=&objNULL;
		obj[9][7].E=&objNULL;
		obj[9][7].W=&objNULL;
		obj[9][7].S=&objNULL;
		obj[9][8].type='h';
		obj[9][8].N=&objNULL;
		obj[9][8].E=&obj[11][8];
		obj[9][8].S=&objNULL;
		obj[9][8].W=&obj[7][8];
		obj[10][0].type='i';
		obj[10][0].N=&objNULL;
		obj[10][0].E=&objNULL;
		obj[10][0].W=&objNULL;
		obj[10][0].S=&objNULL;
		obj[10][1].type='s';
		obj[10][1].N=&obj[10][2];
		obj[10][1].E=&obj[12][1];
		obj[10][1].S=&objNULL;
		obj[10][1].W=&objNULL;
		obj[10][2].type='s';
		obj[10][2].N=&obj[10][3];
		obj[10][2].E=&objNULL;
		obj[10][2].S=&obj[10][1];
		obj[10][2].W=&obj[7][2];
		obj[10][3].type='s';
		obj[10][3].N=&objNULL;
		obj[10][3].E=&obj[11][3];
		obj[10][3].S=&obj[10][2];
		obj[10][3].W=&objNULL;
		obj[10][4].type='i';
		obj[10][4].N=&objNULL;
		obj[10][4].E=&objNULL;
		obj[10][4].W=&objNULL;
		obj[10][4].S=&objNULL;
		obj[10][5].type='s';
		obj[10][5].N=&obj[10][6];
		obj[10][5].E=&obj[11][5];
		obj[10][5].S=&objNULL;
		obj[10][5].W=&objNULL;
		obj[10][6].type='s';
		obj[10][6].N=&obj[10][7];
		obj[10][6].E=&objNULL;
		obj[10][6].S=&obj[10][5];
		obj[10][6].W=&obj[7][6];
		obj[10][7].type='s';
		obj[10][7].N=&objNULL;
		obj[10][7].E=&obj[12][7];
		obj[10][7].S=&obj[10][6];
		obj[10][7].W=&objNULL;
		obj[10][8].type='i';
		obj[10][8].N=&objNULL;
		obj[10][8].E=&objNULL;
		obj[10][8].W=&objNULL;
		obj[10][8].S=&objNULL;
		obj[11][0].type='h';
		obj[11][0].N=&objNULL;
		obj[11][0].E=&obj[13][0];
		obj[11][0].S=&objNULL;
		obj[11][0].W=&obj[9][0];
		obj[11][1].type='i';
		obj[11][1].N=&objNULL;
		obj[11][1].E=&objNULL;
		obj[11][1].W=&objNULL;
		obj[11][1].S=&objNULL;
		obj[11][2].type='i';
		obj[11][2].N=&objNULL;
		obj[11][2].E=&objNULL;
		obj[11][2].W=&objNULL;
		obj[11][2].S=&objNULL;
		obj[11][3].type='s';
		obj[11][3].N=&obj[11][4];
		obj[11][3].E=&obj[12][3];
		obj[11][3].S=&objNULL;
		obj[11][3].W=&obj[10][3];
		obj[11][4].type='j';
		obj[11][4].N=&obj[11][5];
		obj[11][4].E=&objNULL;
		obj[11][4].S=&obj[11][3];
		obj[11][4].W=&obj[8][4];
		obj[11][5].type='s';
		obj[11][5].N=&objNULL;
		obj[11][5].E=&obj[12][5];
		obj[11][5].S=&obj[11][4];
		obj[11][5].W=&obj[10][5];
		obj[11][6].type='i';
		obj[11][6].N=&objNULL;
		obj[11][6].E=&objNULL;
		obj[11][6].W=&objNULL;
		obj[11][6].S=&objNULL;
		obj[11][7].type='i';
		obj[11][7].N=&objNULL;
		obj[11][7].E=&objNULL;
		obj[11][7].W=&objNULL;
		obj[11][7].S=&objNULL;
		obj[11][8].type='h';
		obj[11][8].N=&objNULL;
		obj[11][8].E=&obj[13][8];
		obj[11][8].S=&objNULL;
		obj[11][8].W=&obj[9][8];
		obj[12][0].type='i';
		obj[12][0].N=&objNULL;
		obj[12][0].E=&objNULL;
		obj[12][0].W=&objNULL;
		obj[12][0].S=&objNULL;
		obj[12][1].type='s';
		obj[12][1].N=&obj[12][2];
		obj[12][1].E=&objNULL;
		obj[12][1].S=&objNULL;
		obj[12][1].W=&obj[10][1];
		obj[12][2].type='s';
		obj[12][2].N=&obj[12][3];
		obj[12][2].E=&obj[14][2];
		obj[12][2].S=&obj[12][1];
		obj[12][2].W=&objNULL;
		obj[12][3].type='s';
		obj[12][3].N=&objNULL;
		obj[12][3].E=&objNULL;
		obj[12][3].S=&obj[12][2];
		obj[12][3].W=&obj[11][3];
		obj[12][4].type='i';
		obj[12][4].N=&objNULL;
		obj[12][4].E=&objNULL;
		obj[12][4].W=&objNULL;
		obj[12][4].S=&objNULL;
		obj[12][5].type='s';
		obj[12][5].N=&obj[12][6];
		obj[12][5].E=&objNULL;
		obj[12][5].S=&objNULL;
		obj[12][5].W=&obj[11][5];
		obj[12][6].type='s';
		obj[12][6].N=&obj[12][7];
		obj[12][6].E=&obj[14][6];
		obj[12][6].S=&obj[12][5];
		obj[12][6].W=&objNULL;
		obj[12][7].type='s';
		obj[12][7].N=&objNULL;
		obj[12][7].E=&objNULL;
		obj[12][7].S=&obj[12][6];
		obj[12][7].W=&obj[10][7];
		obj[12][8].type='i';
		obj[12][8].N=&objNULL;
		obj[12][8].E=&objNULL;
		obj[12][8].W=&objNULL;
		obj[12][8].S=&objNULL;
		obj[13][0].type='h';
		obj[13][0].N=&objNULL;
		obj[13][0].E=&obj[14][0];
		obj[13][0].S=&objNULL;
		obj[13][0].W=&obj[11][0];
		obj[13][1].type='i';
		obj[13][1].N=&objNULL;
		obj[13][1].E=&objNULL;
		obj[13][1].W=&objNULL;
		obj[13][1].S=&objNULL;
		obj[13][2].type='i';
		obj[13][2].N=&objNULL;
		obj[13][2].E=&objNULL;
		obj[13][2].W=&objNULL;
		obj[13][2].S=&objNULL;
		obj[13][3].type='i';
		obj[13][3].N=&objNULL;
		obj[13][3].E=&objNULL;
		obj[13][3].W=&objNULL;
		obj[13][3].S=&objNULL;
		obj[13][4].type='i';
		obj[13][4].N=&objNULL;
		obj[13][4].E=&objNULL;
		obj[13][4].W=&objNULL;
		obj[13][4].S=&objNULL;
		obj[13][5].type='i';
		obj[13][5].N=&objNULL;
		obj[13][5].E=&objNULL;
		obj[13][5].W=&objNULL;
		obj[13][5].S=&objNULL;
		obj[13][6].type='i';
		obj[13][6].N=&objNULL;
		obj[13][6].E=&objNULL;
		obj[13][6].W=&objNULL;
		obj[13][6].S=&objNULL;
		obj[13][7].type='i';
		obj[13][7].N=&objNULL;
		obj[13][7].E=&objNULL;
		obj[13][7].W=&objNULL;
		obj[13][7].S=&objNULL;
		obj[13][8].type='h';
		obj[13][8].N=&objNULL;
		obj[13][8].E=&obj[14][8];
		obj[13][8].S=&objNULL;
		obj[13][8].W=&obj[11][8];
		obj[14][0].type='c';
		obj[14][0].N=&obj[14][2];
		obj[14][0].E=&objNULL;
		obj[14][0].S=&objNULL;
		obj[14][0].W=&obj[13][0];
		obj[14][1].type='i';
		obj[14][1].N=&objNULL;
		obj[14][1].E=&objNULL;
		obj[14][1].W=&objNULL;
		obj[14][1].S=&objNULL;
		obj[14][2].type='v';
		obj[14][2].N=&obj[14][6];
		obj[14][2].E=&objNULL;
		obj[14][2].S=&obj[14][0];
		obj[14][2].W=&obj[12][2];
		obj[14][3].type='i';
		obj[14][3].N=&objNULL;
		obj[14][3].E=&objNULL;
		obj[14][3].W=&objNULL;
		obj[14][3].S=&objNULL;
		obj[14][4].type='i';
		obj[14][4].N=&objNULL;
		obj[14][4].E=&objNULL;
		obj[14][4].W=&objNULL;
		obj[14][4].S=&objNULL;
		obj[14][5].type='i';
		obj[14][5].N=&objNULL;
		obj[14][5].E=&objNULL;
		obj[14][5].W=&objNULL;
		obj[14][5].S=&objNULL;
		obj[14][6].type='v';
		obj[14][6].N=&obj[14][8];
		obj[14][6].E=&objNULL;
		obj[14][6].S=&obj[14][2];
		obj[14][6].W=&obj[12][6];
		obj[14][7].type='i';
		obj[14][7].N=&objNULL;
		obj[14][7].E=&objNULL;
		obj[14][7].W=&objNULL;
		obj[14][7].S=&objNULL;
		obj[14][8].type='c';
		obj[14][8].N=&objNULL;
		obj[14][8].E=&objNULL;
		obj[14][8].S=&obj[14][6];
		obj[14][8].W=&obj[13][8];
	}
	
	{
		obj[0][0].XPOS=0;
		obj[0][0].YPOS=0;

		obj[0][1].XPOS=0;
		obj[0][1].YPOS=1;

		obj[0][2].XPOS=0;
		obj[0][2].YPOS=2;

		obj[0][3].XPOS=0;
		obj[0][3].YPOS=3;

		obj[0][4].XPOS=0;
		obj[0][4].YPOS=4;

		obj[0][5].XPOS=0;
		obj[0][5].YPOS=5;

		obj[0][6].XPOS=0;
		obj[0][6].YPOS=6;

		obj[0][7].XPOS=0;
		obj[0][7].YPOS=7;

		obj[0][8].XPOS=0;
		obj[0][8].YPOS=8;

		obj[1][0].XPOS=1;
		obj[1][0].YPOS=0;

		obj[1][1].XPOS=1;
		obj[1][1].YPOS=1;

		obj[1][2].XPOS=1;
		obj[1][2].YPOS=2;

		obj[1][3].XPOS=1;
		obj[1][3].YPOS=3;

		obj[1][4].XPOS=1;
		obj[1][4].YPOS=4;

		obj[1][5].XPOS=1;
		obj[1][5].YPOS=5;

		obj[1][6].XPOS=1;
		obj[1][6].YPOS=6;

		obj[1][7].XPOS=1;
		obj[1][7].YPOS=7;

		obj[1][8].XPOS=1;
		obj[1][8].YPOS=8;

		obj[2][0].XPOS=2;
		obj[2][0].YPOS=0;

		obj[2][1].XPOS=2;
		obj[2][1].YPOS=1;

		obj[2][2].XPOS=2;
		obj[2][2].YPOS=2;

		obj[2][3].XPOS=2;
		obj[2][3].YPOS=3;

		obj[2][4].XPOS=2;
		obj[2][4].YPOS=4;

		obj[2][5].XPOS=2;
		obj[2][5].YPOS=5;

		obj[2][6].XPOS=2;
		obj[2][6].YPOS=6;

		obj[2][7].XPOS=2;
		obj[2][7].YPOS=7;

		obj[2][8].XPOS=2;
		obj[2][8].YPOS=8;

		obj[3][0].XPOS=3;
		obj[3][0].YPOS=0;

		obj[3][1].XPOS=3;
		obj[3][1].YPOS=1;

		obj[3][2].XPOS=3;
		obj[3][2].YPOS=2;

		obj[3][3].XPOS=3;
		obj[3][3].YPOS=3;

		obj[3][4].XPOS=3;
		obj[3][4].YPOS=4;

		obj[3][5].XPOS=3;
		obj[3][5].YPOS=5;

		obj[3][6].XPOS=3;
		obj[3][6].YPOS=6;

		obj[3][7].XPOS=3;
		obj[3][7].YPOS=7;

		obj[3][8].XPOS=3;
		obj[3][8].YPOS=8;

		obj[4][0].XPOS=4;
		obj[4][0].YPOS=0;

		obj[4][1].XPOS=4;
		obj[4][1].YPOS=1;

		obj[4][2].XPOS=4;
		obj[4][2].YPOS=2;

		obj[4][3].XPOS=4;
		obj[4][3].YPOS=3;

		obj[4][4].XPOS=4;
		obj[4][4].YPOS=4;

		obj[4][5].XPOS=4;
		obj[4][5].YPOS=5;

		obj[4][6].XPOS=4;
		obj[4][6].YPOS=6;

		obj[4][7].XPOS=4;
		obj[4][7].YPOS=7;

		obj[4][8].XPOS=4;
		obj[4][8].YPOS=8;

		obj[5][0].XPOS=5;
		obj[5][0].YPOS=0;

		obj[5][1].XPOS=5;
		obj[5][1].YPOS=1;

		obj[5][2].XPOS=5;
		obj[5][2].YPOS=2;

		obj[5][3].XPOS=5;
		obj[5][3].YPOS=3;

		obj[5][4].XPOS=5;
		obj[5][4].YPOS=4;

		obj[5][5].XPOS=5;
		obj[5][5].YPOS=5;

		obj[5][6].XPOS=5;
		obj[5][6].YPOS=6;

		obj[5][7].XPOS=5;
		obj[5][7].YPOS=7;

		obj[5][8].XPOS=5;
		obj[5][8].YPOS=8;

		obj[6][0].XPOS=6;
		obj[6][0].YPOS=0;

		obj[6][1].XPOS=6;
		obj[6][1].YPOS=1;

		obj[6][2].XPOS=6;
		obj[6][2].YPOS=2;

		obj[6][3].XPOS=6;
		obj[6][3].YPOS=3;

		obj[6][4].XPOS=6;
		obj[6][4].YPOS=4;

		obj[6][5].XPOS=6;
		obj[6][5].YPOS=5;

		obj[6][6].XPOS=6;
		obj[6][6].YPOS=6;

		obj[6][7].XPOS=6;
		obj[6][7].YPOS=7;

		obj[6][8].XPOS=6;
		obj[6][8].YPOS=8;

		obj[7][0].XPOS=7;
		obj[7][0].YPOS=0;

		obj[7][1].XPOS=7;
		obj[7][1].YPOS=1;

		obj[7][2].XPOS=7;
		obj[7][2].YPOS=2;

		obj[7][3].XPOS=7;
		obj[7][3].YPOS=3;

		obj[7][4].XPOS=7;
		obj[7][4].YPOS=4;

		obj[7][5].XPOS=7;
		obj[7][5].YPOS=5;

		obj[7][6].XPOS=7;
		obj[7][6].YPOS=6;

		obj[7][7].XPOS=7;
		obj[7][7].YPOS=7;

		obj[7][8].XPOS=7;
		obj[7][8].YPOS=8;

		obj[8][0].XPOS=8;
		obj[8][0].YPOS=0;

		obj[8][1].XPOS=8;
		obj[8][1].YPOS=1;

		obj[8][2].XPOS=8;
		obj[8][2].YPOS=2;

		obj[8][3].XPOS=8;
		obj[8][3].YPOS=3;

		obj[8][4].XPOS=8;
		obj[8][4].YPOS=4;

		obj[8][5].XPOS=8;
		obj[8][5].YPOS=5;

		obj[8][6].XPOS=8;
		obj[8][6].YPOS=6;

		obj[8][7].XPOS=8;
		obj[8][7].YPOS=7;

		obj[8][8].XPOS=8;
		obj[8][8].YPOS=8;

		obj[9][0].XPOS=9;
		obj[9][0].YPOS=0;

		obj[9][1].XPOS=9;
		obj[9][1].YPOS=1;

		obj[9][2].XPOS=9;
		obj[9][2].YPOS=2;

		obj[9][3].XPOS=9;
		obj[9][3].YPOS=3;

		obj[9][4].XPOS=9;
		obj[9][4].YPOS=4;

		obj[9][5].XPOS=9;
		obj[9][5].YPOS=5;

		obj[9][6].XPOS=9;
		obj[9][6].YPOS=6;

		obj[9][7].XPOS=9;
		obj[9][7].YPOS=7;

		obj[9][8].XPOS=9;
		obj[9][8].YPOS=8;

		obj[10][0].XPOS=10;
		obj[10][0].YPOS=0;

		obj[10][1].XPOS=10;
		obj[10][1].YPOS=1;

		obj[10][2].XPOS=10;
		obj[10][2].YPOS=2;

		obj[10][3].XPOS=10;
		obj[10][3].YPOS=3;

		obj[10][4].XPOS=10;
		obj[10][4].YPOS=4;

		obj[10][5].XPOS=10;
		obj[10][5].YPOS=5;

		obj[10][6].XPOS=10;
		obj[10][6].YPOS=6;

		obj[10][7].XPOS=10;
		obj[10][7].YPOS=7;

		obj[10][8].XPOS=10;
		obj[10][8].YPOS=8;

		obj[11][0].XPOS=11;
		obj[11][0].YPOS=0;

		obj[11][1].XPOS=11;
		obj[11][1].YPOS=1;

		obj[11][2].XPOS=11;
		obj[11][2].YPOS=2;

		obj[11][3].XPOS=11;
		obj[11][3].YPOS=3;

		obj[11][4].XPOS=11;
		obj[11][4].YPOS=4;

		obj[11][5].XPOS=11;
		obj[11][5].YPOS=5;

		obj[11][6].XPOS=11;
		obj[11][6].YPOS=6;

		obj[11][7].XPOS=11;
		obj[11][7].YPOS=7;

		obj[11][8].XPOS=11;
		obj[11][8].YPOS=8;

		obj[12][0].XPOS=12;
		obj[12][0].YPOS=0;

		obj[12][1].XPOS=12;
		obj[12][1].YPOS=1;

		obj[12][2].XPOS=12;
		obj[12][2].YPOS=2;

		obj[12][3].XPOS=12;
		obj[12][3].YPOS=3;

		obj[12][4].XPOS=12;
		obj[12][4].YPOS=4;

		obj[12][5].XPOS=12;
		obj[12][5].YPOS=5;

		obj[12][6].XPOS=12;
		obj[12][6].YPOS=6;

		obj[12][7].XPOS=12;
		obj[12][7].YPOS=7;

		obj[12][8].XPOS=12;
		obj[12][8].YPOS=8;

		obj[13][0].XPOS=13;
		obj[13][0].YPOS=0;

		obj[13][1].XPOS=13;
		obj[13][1].YPOS=1;

		obj[13][2].XPOS=13;
		obj[13][2].YPOS=2;

		obj[13][3].XPOS=13;
		obj[13][3].YPOS=3;

		obj[13][4].XPOS=13;
		obj[13][4].YPOS=4;

		obj[13][5].XPOS=13;
		obj[13][5].YPOS=5;

		obj[13][6].XPOS=13;
		obj[13][6].YPOS=6;

		obj[13][7].XPOS=13;
		obj[13][7].YPOS=7;

		obj[13][8].XPOS=13;
		obj[13][8].YPOS=8;

		obj[14][0].XPOS=14;
		obj[14][0].YPOS=0;

		obj[14][1].XPOS=14;
		obj[14][1].YPOS=1;

		obj[14][2].XPOS=14;
		obj[14][2].YPOS=2;

		obj[14][3].XPOS=14;
		obj[14][3].YPOS=3;

		obj[14][4].XPOS=14;
		obj[14][4].YPOS=4;

		obj[14][5].XPOS=14;
		obj[14][5].YPOS=5;

		obj[14][6].XPOS=14;
		obj[14][6].YPOS=6;

		obj[14][7].XPOS=14;
		obj[14][7].YPOS=7;

		obj[14][8].XPOS=14;
		obj[14][8].YPOS=8;


	}
}
void mapp(map *I,map *F)
{
	Start = &obj[7][0];
	initial = I;
	//Current = &obj[7][0];
	//final = &obj[0][0];
	
	
	allocate_moore_value(initial,final);
	steps=final->moore_value;
	
	
	//cout<<steps<<"\n";
	int *a;
	a=directionfetcher(initial,final);	
	for (int i=0, j=steps-1;i<steps;i++,j--)
	{
		direction[i]=a[j];
		//lcd_print(1,i+1,direction[i],1);
		//_delay_ms(1000);

	}
	
	
	
	//cout<<"Direction is\n";
	//for(int i=0;i<steps;i++)
	{
		//cout<<direction[i]<<"\n";
		
	}
	

//getch();	
	
}




void allocate_moore_value(map *initial, map *final)
{
	//static int j;
	int i=0;
	InitialiseMooreValuesTo100();
	MooreValueAssignerUsingRecursion(initial,final,i,'i');
	//cout<<"\nAllocated,now displaying\n";
	//For DEbuging Purpose ==> displaymoore();
	//cout<<"Display Finished";
}

/*
For DeBugging Purposes Only
void displaymoore()
{
	cout<<"display called";
	for(int i=0;i<Column;i++)
	{
		for(int j=0;j<Row;j++)
		{
			if(obj[i][j].moore_value!=100)
			{
				cout<<"obj["<<i<<"]["<<j<<"] = "<<obj[i][j].moore_value<<"\n";
			}
		}
	}
}*/

void InitialiseMooreValuesTo100()
{
	for(int i=0;i<Column;i++)
	{
		for(int j=0;j<Row;j++)
		{
			obj[i][j].moore_value=100;
		}
	}
}

void MooreValueAssignerUsingRecursion(map *ptr,map *final,int i,char ch)
{
	map *objNULLptr = &objNULL;
	ptr->moore_value=i++;
	if(ptr==objNULLptr){/*cout<<"null";*/}
	else if(ptr==final)
	{
		if(ptr->moore_value>i)
		{
			ptr->moore_value=i;
		}
	}
	else
	{
		
		switch (ch)
		{
		
			case 'i':
			{
				if(ptr->N->moore_value>i)
					MooreValueAssignerUsingRecursion(ptr->N,final,i,'n');
				if(ptr->E->moore_value>i)
					MooreValueAssignerUsingRecursion(ptr->E,final,i,'e');
				if(ptr->S->moore_value>i)
					MooreValueAssignerUsingRecursion(ptr->S,final,i,'s');
				if(ptr->W->moore_value>i)
					MooreValueAssignerUsingRecursion(ptr->W,final,i,'w');
			}
			break;
			
			case 'e':
			{
				if(ptr->N->moore_value>i)
					MooreValueAssignerUsingRecursion(ptr->N,final,i,'n');
				if(ptr->E->moore_value>i)
					MooreValueAssignerUsingRecursion(ptr->E,final,i,'e');
				if(ptr->S->moore_value>i)
					MooreValueAssignerUsingRecursion(ptr->S,final,i,'s');
			}
			break;
			
			case 'n':
			{
				if(ptr->N->moore_value>i)
					MooreValueAssignerUsingRecursion(ptr->N,final,i,'n');
				if(ptr->E->moore_value>i)
					MooreValueAssignerUsingRecursion(ptr->E,final,i,'e');
				if(ptr->W->moore_value>i)
					MooreValueAssignerUsingRecursion(ptr->W,final,i,'w');
			}
			break;
			
			case 'w':
			{
				
				if(ptr->N->moore_value>i)
					MooreValueAssignerUsingRecursion(ptr->N,final,i,'n');
				if(ptr->S->moore_value>i)
					MooreValueAssignerUsingRecursion(ptr->S,final,i,'s');
				if(ptr->W->moore_value>i)
					MooreValueAssignerUsingRecursion(ptr->W,final,i,'w');
			}
			break;
			
			case 's':
			{	
				if(ptr->E->moore_value>i)
					MooreValueAssignerUsingRecursion(ptr->E,final,i,'e');
				if(ptr->S->moore_value>i)
					MooreValueAssignerUsingRecursion(ptr->S,final,i,'s');
				if(ptr->W->moore_value>i)
					MooreValueAssignerUsingRecursion(ptr->W,final,i,'w');
				
			}
			break;
		}
	}
}



int * directionfetcher(map *initial,map *final)
{
	int N,E,S,W;
	N=1;E=2;S=3;W=4;
	map *ptr;
	int a[99];
	ptr=final;
	int i=0;
	while (ptr!=initial)
	{
		//cout<<"\nin while\n";
		 if (ptr->N!=objNULLptr && ptr->moore_value>ptr->N->moore_value)
		{
			//cout<<"N";
			a[i]=S;
			ptr=ptr->N;
		} 
		else if (ptr->E!=objNULLptr && ptr->moore_value>ptr->E->moore_value)
		{
			//cout<<"E";
			a[i]=W;
			ptr=ptr->E;
		}
		else if (ptr->S!=objNULLptr && ptr->moore_value>ptr->S->moore_value)
		{
			//cout<<"S";
			a[i]=N;
			ptr=ptr->S;
		}
		else if (ptr->W!=objNULLptr && ptr->moore_value>ptr->W->moore_value)
		{
			//cout<<"W";
			a[i]=E;
			ptr=ptr->W;
		}
		i++;
		
	}
	return a;
	
		
}

