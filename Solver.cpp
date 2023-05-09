#include<stdio.h>
#include<strings.h>
#include "Cube.cpp"
#include"Algo_storing_stack.cpp"

 
void set_centre_to(char face)
{
	if(DOWN[1][1]==face){
		X(0);
		push('X',0);
	}
	else if(UP[1][1]==face){
		X(1);
		push('X',1);
	}
	else if(LEFT[1][1]==face){
		Y(1);											
		push('Y',1);
	}
	else if(RIGHT[1][1]==face){
		Y(0);
		push('Y',0);
	}
	else if(XRIGHT[1][1]==face){
		Y(0); Y(0);
		push('Y',0);
		push('Y',0);
	}
}

int compare(char *str,char key,int skip1=-1){
	int len=strlen(str);
	for(int i=0;i<len;i++) if(str[i]==key and (i+1)!=skip1) return (i+1);
	return 0;
}
void free(char (* face)[3],int x,int y,char color){    //free the face's [x][y] position from the color,i.e.,that color should not be present at parameter's postion
	if(face[x][y]==color)
	{
		F(0);
		if(face[x][y]!=color){
			push('F',0);  //F
			return;
		}
		F(1); F(1);
		if(face[x][y]!=color){
			push('F',1);	//F'
			return;
		}
		F(1);
		push('F',2);	//F2
	}
}

void righty_alg() {
	R(0);				U(0);				 R(1);				  U(1);
	push('R',0);	push('U',0);	push('R',1);	push('U',1);
}
void lefty_alg() {
	L(1);				U(1);				 L(0);				  U(0);
	push('L',1);	push('U',1);	push('L',0);	push('U',0);
}

void left_corner_insert() {
	printf("lci is called \n");
	U(1);  			L(1); 			U(0); 			L(0);
	push('U',1);	push('L',1);	push('U',0);	push('L',0);
}

void right_corner_insert() {
	printf("rci is called \n");
	U(0);  			R(0); 			U(1); 			R(1);
	push('U',0);	push('R',0);	push('U',1);	push('R',1);
}




void  white_cross_solver()
{
	set_centre_to('Y');
	display();
	
	while(CENTRE[0][1]!='W' || CENTRE[1][0]!='W' || CENTRE[1][2]!='W' || CENTRE[2][1]!='W')
	{
		display();
		char a[]={LEFT[1][2], RIGHT[1][0], UP[2][1], DOWN[0][1]};
		if(compare(a,'W'))
		{
			switch(compare(a,'W'))
			{
				case 1:
					L(0);			F(1);			D(0);
					push('L',0); 	push('F',1);	push('D',0);
					break;
				case 2:
					R(0);			F(1);			U(0);
					push('R',0); 	push('F',1);	push('U',0);
					break;
				case 3:
					U(0);			F(1);			L(0);
					push('U',0); 	push('F',1);	push('L',0);
					break;
				case 4:
					D(0);			F(1);			R(0);
					push('D',0); 	push('F',1);	push('R',0);
					break;
			}
		}
		char b[]={XRIGHT[0][1], XRIGHT[1][0], XRIGHT[1][2], XRIGHT[2][1]};
		if(compare(b,'W'))
		{
			switch(compare(b,'W'))
			{
				case 1:
					free(CENTRE,0,1,'W');
					U(0); U(0);
					push('U',2);
					break;
				case 2:
					free(CENTRE,1,2,'W');
					R(0); R(0);
					push('R',2);
					break;
				case 3:
					free(CENTRE,1,0,'W');
					L(0); L(0);
					push('L',2);
					break;
				case 4:
					free(CENTRE,2,1,'W');
					D(0); D(0);
					push('D',2);
					break;
			}
		}
		char c[]={LEFT[0][1], RIGHT[0][1], UP[1][0], DOWN[1][0],UP[1][2], DOWN[1][2],LEFT[2][1], RIGHT[2][1]};
		if(compare(c,'W')){
			switch(compare(c,'W')){
				case 1:
					free(CENTRE,0,1,'W');
					U(1);
					push('U',1);
					break;
				case 2:
					free(CENTRE,0,1,'W');
					U(0);
					push('U',0);
					break;
				case 3:
					free(CENTRE,1,0,'W');
					L(0);
					push('L',0);
					break;
				case 4:
					free(CENTRE,1,0,'W');
					L(1);
					push('L',1);
					break;
				case 5:
					free(CENTRE,1,2,'W');
					R(1);
					push('R',1);
					break;
				case 6:
					free(CENTRE,1,2,'W');
					R(0);
					push('R',0);
					break;
				case 7:
					free(CENTRE,2,1,'W');
					D(0);
					push('D',0);
					break;
				case 8:
					free(CENTRE,2,1,'W');
					D(1);
					push('D',1);
					break;
			}
		}
		char d[]={LEFT[1][0], RIGHT[1][2], UP[0][1], DOWN[2][1]};
		if(compare(d,'W')){
			switch(compare(d,'W')){
				case 1:
					free(CENTRE,1,0,'W');
					L(0);			F(0);			U(1);
					push('L',0); 	push('F',0);	push('U',1);
					break;
				case 2:
					free(CENTRE,1,2,'W');
					R(0);			F(0);			D(1);
					push('R',0); 	push('F',0);	push('D',1);
					break;
				case 3:
					free(CENTRE,0,1,'W');
					U(0);			F(0);			R(1);
					push('U',0); 	push('F',0);	push('R',1);
					break;
				case 4:
					free(CENTRE,2,1,'W');
					D(0);			F(0);			L(1);
					push('D',0); 	push('F',0);	push('L',1);
					break;
			}
		}
	}
	display();
	
	while(CENTRE[0][1]=='W' || CENTRE[1][0]=='W' || CENTRE[1][2]=='W' || CENTRE[2][1]=='W')
	{
		display();
		if((UP[2][1]==UP[1][1] and CENTRE[0][1]=='W') || (RIGHT[1][0]==RIGHT[1][1] and CENTRE[1][2]=='W') || (LEFT[1][2]==LEFT[1][1] and CENTRE[1][0]=='W') || (DOWN[0][1]==DOWN[1][1] and CENTRE[2][1]=='W'))
		{
			
			if((UP[2][1]==UP[1][1] and CENTRE[0][1]=='W')) 
			{
				U(0); U(0);
				push('U',2);
			}
			if(RIGHT[1][0]==RIGHT[1][1] and CENTRE[1][2]=='W')
			{
				R(0); R(0);
				push('R',2);
			}
			if(LEFT[1][2]==LEFT[1][1] and CENTRE[1][0]=='W')
			{
				L(0); L(0);
				push('L',2);
			}
			if(DOWN[0][1]==DOWN[1][1] and CENTRE[2][1]=='W')
			{
				D(0); D(0);
				push('D',2);
			}
		}
		else
		{
			F(0);
			push('F',0);
		}
	}
	
//	U(0); U(0);		D(0); D(0); 	R(0); R(0); 	L(0); L(0);
//	push('U',2);	push('D',2);	push('R',2);	push('L',2);
//	X(0); X(0);
//	
	printf("White Cross is Solved! \n");
//	display();
//	exit(0);
}


bool is_bottom_layer_solved()
{
	for(int i=0;i<3;i++) for(int j=0;j<3;j++) if(DOWN[i][j]!='W') return 0;
	
	if(CENTRE[1][1]!=CENTRE[2][0] or CENTRE[1][1]!=CENTRE[2][1] or CENTRE[1][1]!=CENTRE[2][2]) return 0;
	if(RIGHT[1][1]!=RIGHT[2][0] or RIGHT[1][1]!=RIGHT[2][1] or RIGHT[1][1]!=RIGHT[2][2]) return 0;
	if(LEFT[1][1]!=LEFT[2][0] or LEFT[1][1]!=LEFT[2][1] or LEFT[1][1]!=LEFT[2][2]) return 0;
	if(XRIGHT[1][1]!=XRIGHT[2][0] or XRIGHT[1][1]!=XRIGHT[2][1] or XRIGHT[1][1]!=XRIGHT[2][2]) return 0;
	return 1;
}



void white_corner_solver(int level)
{
	X(1);
	push('X',1);
	int position,count=0;
	//char possible[]={UP[2][0], UP[2][2], LEFT[0][2], CENTRE[0][0], CENTRE[0][2], RIGHT[0][0], LEFT[2][2], CENTRE[2][0], CENTRE[2][2], RIGHT[2][0], DOWN[0][0], DOWN[0][2]};
	int sequence[]={2, 5, 3 ,0 , 1, 4};
	while(!is_bottom_layer_solved())
	{
		if(count>20) break;
		count++;
		
		display();
		char possible[]={UP[2][0], UP[2][2], LEFT[0][2], CENTRE[0][0], CENTRE[0][2], RIGHT[0][0], LEFT[2][2], CENTRE[2][0], CENTRE[2][2], RIGHT[2][0], DOWN[0][0], DOWN[0][2]};
		position=compare(possible,'W');
		
		if(position==11 and CENTRE[2][0]==CENTRE[1][1]) position=compare(possible,'W',11);
		if(position==12 and CENTRE[2][2]==CENTRE[1][1]) position=0;
		
		printf("%d %d\n",count,position);
		
		if(!position)
		{
			Y(0);
			push('Y',0);
		}
		
		else if(position==7 or position==8 or position==11) lefty_alg();
		else if(position==9 or position==10 or position==12) righty_alg();
		
		else if(position>0 and position<=6)
		{
			//Code for corner(1-6) alingment-start
			if(CENTRE[1][1]!=possible[sequence[position-1]])
			{
				d(0);
				if(CENTRE[1][1]==possible[sequence[position-1]]) push('d',0);
				else
				{
					d(1);  d(1);
					if(CENTRE[1][1]==possible[sequence[position-1]]) push('d',1);
					else
					{
						d(1);
						push('d',2);
					}
				}
			}
			//code for corner(1-6) alingment-end
		}
		display();
		//code for corner insertion-start
		int times=0;
		if(position==1 or position==2) times=3;
		else if(position==3 or position==6) times=1;
		else if(position==4 or position==5 and level==1) times=5;
		
		for(int i=0;i<times;i++)
		{
			if(position==1 or position==3 or position==4) lefty_alg();
			else righty_alg();
		}
		if(level ==2 and position==4) left_corner_insert();
		else if(level ==2 and position==5) right_corner_insert();
		display();
		//code for corner insertion-end
		
	}
}
int main()
{
	display();
	//giv_cube_array();
	R(0); R(0); U(0); U(0); R(1); U(1); L(1); U(1); L(0); L(0); U(0); U(0); 
	
	X(0); F(0); B(0);// U(0); r(0); u(0); 
	M(0); E(0); S(0);
	R(0); R(0); U(0); U(0); R(1); U(1); L(1); U(1); L(0); L(0); U(0); U(0); X(1);            //commenting this 
	R(0); U(0); R(1); R(1); U(1); L(1); U(1); L(0); L(0); U(0); U(0); X(0);                     // and this will return buggy code.
	R(0); R(0); U(0); U(1); R(1); F(0); R(0); R(0); U(1); R(1); F(1); R(0); U(0); //R(0); U(0); F(0); B(0); U(0); r(0); u(0); M(0); E(0); S(0);
	F(0); R(0); R(0); U(1); R(1); 

	
	//IMPORTANT NOTE - LCI OR RIGHTY OR RCI CAN ALTER POSITION OF WHITE AND CAN BRING THEM BACK TO TOPMOST LAYER OF YELLOW SO WE'LL NEED TO CALL 
	//EDGE1 ONCE AGAIN.... SAD.
	
	
    // activate for edge 3 solver case
//	X(0); F(0); B(0);// U(0); r(0); u(0); 
//	M(0); E(0); S(0);
	R(0); R(0); U(0); U(0); R(1); U(1); //L(1); U(1); L(0); L(0); U(0); U(0); X(1);            //commenting this 
//	R(0); U(0); R(1); R(1); U(1); L(1); U(1); L(0); L(0); U(0); U(0); X(0);  				//commenting out this and uncommmenting the lines below will put this code to an infinite loop                   
	R(0); R(0); U(0); U(1); R(1); F(0); R(0); R(0); U(1); R(1);// F(1); R(0); U(0); R(0); U(0); F(0); B(0); U(0); r(0); u(0); M(0); E(0); S(0);
	F(0); R(0);// R(0); U(1); R(1);
	
	display();
	
	white_cross_solver();
	set_centre_to('W');
	display();
	
	
	white_corner_solver(2);
	set_centre_to('W');
	display();
	
	print_stack();
	
	
}
