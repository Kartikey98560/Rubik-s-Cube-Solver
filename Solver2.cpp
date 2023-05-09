#include<stdio.h>
#include "Cube.cpp"
#include"Algo_storing_stack.cpp"
#include<strings.h>
//set_centre_to(char face);



void set_centre_to(char face)
{
	if(DOWN[1][1]==face) X(0);
	else if(UP[1][1]==face) X(1);
	else if(LEFT[1][1]==face) Z(0);
	else if(RIGHT[1][1]==face) Z(1);
	else if(XRIGHT[1][1]==face){
		Z(0);
		Z(0);
	}
}

int compare(char *str,char key){
	int len=strlen(str);
	for(int i=0;i<len;i++) if(str[i]==key) return (i+1);
	return 0;
}
void free(char (* face)[3],int x,int y,char color){
	if(face[x][y]==color)
	{
		if(x==1 && y==2){
			if(face[0][1]!='W') F(0);
			else if(face[1][0]!='W'){
				F(0); F(0);
			}
			else F(1);
		}
		else{
			if(face[0][1]!='W') F(1);
			else if(face[1][2]!='W'){
				F(0); F(0);
			}
			else F(0);
		}
	}
}

void  first_layer_solver()
{
	set_centre_to('Y');
	display();
	
	while(CENTRE[0][1]!='W' || CENTRE[1][0]!='W' || CENTRE[1][2]!='W' || CENTRE[2][1]!='W')
	{
		char a[]={LEFT[1][2], RIGHT[1][0], UP[2][1], DOWN[0][1]};
		if(compare(a,'W'))
		{
			printf("1\n");
			printf("%d\n",compare(a,'W'));
			switch(compare(a,'W'))
			{
				case 1:
					L(0);	F(1);	D(0);
					break;
				case 2:
					R(0);	F(1);	U(0);
					break;
				case 3:
					U(0);	F(1);	L(0);
					break;
				case 4:
					D(0);	F(1);	R(0);
					break;
			}
			display();
		}
		char b[]={XRIGHT[0][1], XRIGHT[1][0], XRIGHT[1][2], XRIGHT[2][1]};
		if(compare(b,'W'))
		{
			printf("2\n");
			printf("%d\n",compare(b,'W'));
			switch(compare(b,'W'))
			{
				case 1:
					Z(0);
					free(CENTRE,1,2,'W');
					R(0); R(0); Z(1);
					break;
				case 2:
					free(CENTRE,1,2,'W');
					R(0); R(0);
					break;
				case 3:
					free(CENTRE,1,0,'W');
					L(0); L(0);
					break;
				case 4:
					Z(0);
					free(CENTRE,1,0,'W');
					L(0); L(0); Z(1);
					break;
			}
			display();
		}
		char c[]={LEFT[0][1], RIGHT[0][1], UP[1][0], DOWN[1][0],UP[1][2], DOWN[1][2],LEFT[2][1], RIGHT[2][1]};
		if(compare(c,'W')){
			printf("3\n");
			printf("%d\n",compare(c,'W'));
			switch(compare(c,'W')){
				
				case 1:
					Z(1);
					free(CENTRE,1,0,'W');
					L(1); Z(0);
					break;
				case 2:
					Z(0);
					free(CENTRE,1,2,'W');
					R(0); Z(0);
					break;
				case 3:
					Z(0); Z(0);
					free(CENTRE,1,2,'W');
					R(0); Z(1); Z(1);
					break;
				case 4:
					free(CENTRE,1,0,'W');
					L(1);
					break;
				case 5:
					Z(0); Z(0);
					free(CENTRE,1,0,'W');
					L(1); Z(1); Z(1);
					break;
				case 6:
					free(CENTRE,1,2,'W');
					R(0);
					break;
				case 7:
					Z(1);
					free(CENTRE,2,1,'W');
					R(0); Z(0);
					break;
				case 8:
					Z(0);
					free(CENTRE,1,0,'W');
					L(1); Z(1);
					break;
			}
			display();
		}
		char d[]={LEFT[1][0], RIGHT[1][2], UP[1][0], DOWN[2][1]};
		if(compare(d,'W')){
			printf("4\n");
			printf("%d\n",compare(d,'W'));
			display();
			switch(compare(d,'W')){
				case 1:
					free(CENTRE,1,0,'W');
					L(0); F(0); U(1);
					break;
				case 2:
					free(CENTRE,1,2,'W');
					R(0); F(0); D(1);
					break;
				case 3:
					Z(0);
					free(CENTRE,1,2,'W');
					R(0); F(0); D(1); Z(1);
					break;
				case 4:
					Z(1);
					free(CENTRE,1,2,'W');
					R(0); F(0); D(1); Z(0);
					break;
			}
		}
	}
}

int main()
{
	display();
	//giv_cube_array();
	//R U R' U' R' F R2 U' R' F' F R U R U F B U u M E S
	R(0); U(0); R(1); U(1); R(1); F(0); R(0); R(0); U(1); R(1); F(1); R(0); U(0); R(0); U(0); F(0); B(0); U(0); r(0); u(0); M(0); E(0); S(0);
	display();
	
	first_layer_solver();
	display();
	
	
}
