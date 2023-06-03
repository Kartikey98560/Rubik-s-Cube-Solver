#include<stdio.h>
#include <time.h>
#include<math.h>
#include"Second_layer_solver.cpp"

void oll();
void solve_cross();
void solve_crab();
void super_algo();
void solve_turtle();
void solve_fish(int sum);
void scramble();
void edgeACW();
void hAlgo();

void edgeACW()
{
	R(0);			U(1);			R(0);			U(0);			R(0);			U(0);			R(0);			U(1);			R(1);				U(1);				R(1); R(1);
	push('R',0);	push('U',1);	push('R',0);	push('U',0);	push('R',0);	push('U',0);	push('R',0);	push('U',1);	push('R',1);		push('U',1);		push('R',2);	
}

void hAlgo()
{
	//R U R' U' R' F R2 U' R' U' R U R' F'
	R(0);			 U(0);			 R(1);			 U(1);			 R(1);			 F(0);			 R(1); R(1);
	push('R',0);	 push('U',0);	 push('R',1);	 push('U',1);	 push('R',1);	 push('F',0);	 push('R',2);
	
	U(1);			 R(1);			 U(1);			 R(0);			 U(0);			 R(1);			 F(1);
	push('U',1);	 push('R',1);	 push('U',1);	 push('R',0);	 push('U',0);	 push('R',1);	 push('F',1);				
}

void scramble(int sample_size)
{
	void (*moves[])(int)={D, U, L, R, F, B, X, Y, Z, M, E, S, u, d, l, r, f, b};
	char names[]={'D', 'U', 'L', 'R', 'F', 'B', 'X', 'Y', 'Z', 'M', 'E', 'S', 'u', 'd', 'l', 'r', 'f', 'b'};
	char performed[sample_size][2];
	srand(time(0));
	for(int i=0;i<sample_size;i++) 
	{
		int index = rand()%18;
		int prime=rand()%2;
		performed[i][0]=names[index];
		performed[i][1]=(prime==1)?'1':'0';
		
		(*moves[index])(prime);
	}
	printf("Scrambled: \n");
	for(int i=0;i<sample_size;i++) 
	{
		printf("\t%c",performed[i][0]);
		if (performed[i][1]=='1') printf("'");
//		printf("\t");
	}
	printf("\n\n\n");
}

void super_algo()
{
	R(0);			U(0);			R(1);			U(0);			R(0);			U(0); U(0);		R(1);
	push('R',0);	push('U',0);	push('R',1);	push('U',0);	push('R',0);	push('U',2);	push('R',1);
	//push('C',0);
}

void solve_crab(){
	printf("CRAB\n");
	int count=0;
	while(CENTRE[0][0]!='Y')
	{
		count++;
		U(0);
	}
	if(count==1) push('U',0);
	else if(count==2) push('U',2);
	else if(count==3) push('U',1);
	
	super_algo();
	
	solve_fish(122);
}

void solve_turtle(){
	printf("TURTLE\n");
	int count=0;
	while(CENTRE[0][0]!='Y')
	{
		count++;
		U(0);
	}
	if(count==1) push('U',0);
	else if(count==2) push('U',2);
	else if(count==3) push('U',1);
	
	
	if(CENTRE[0][2]=='Y') 
	{
		super_algo();
		solve_fish(91);
	}
	else
	{
		super_algo();
		solve_fish(218);
	}	
}

void solve_fish(int sum){
	display2();
	printf("FISH\n");
	if(sum==91)
	{
		U(1);
		push('U',1);
	}
	else if(sum==94)
	{
		U(1);
		U(1);
		push('U',2);
	}
	else if(sum==218)
	{
		U(0);
		push('U',0);
	}
	
	if(CENTRE[0][2]=='Y') super_algo();
	else
	{
		super_algo();
		U(0); U(0);
		push('U',2);
		super_algo();
	}
}

void solve_cross(){
	printf("CROSS\n");
	int count=0;
	while(LEFT[0][0]!='Y' and LEFT[0][2]!='Y')
	{
		count++;
		U(0);
	}
	if(count==1) push('U',0);
	else if(count==2) push('U',2);
	else if(count==3) push('U',1);
	
	super_algo();
	oll();
}

void oll(){
	display2();
	int sum=0;
	int weightage[]={1,2,4,8,0,16,32,64,128};
	for(int i=0;i<3;i++) for(int j=0;j<3;j++) if(UP[i][j] == 'Y')   sum+=weightage[i*3+j];
	
	printf("%d\n",sum);
	
	if(sum==255) return;
	
	if(sum==126 or sum==219) solve_crab();
	
	else if(sum==91 or sum==94 or sum==218 or sum==122) solve_fish(sum);
	
	else if(sum==95 or sum==222 or sum==250 or sum==123) solve_turtle();
	
	else if(sum==90) solve_cross();
	
	else if((UP[0][1]=='Y' and UP[2][1]=='Y') or (UP[1][0]=='Y' and UP[1][2]=='Y'))
	{
		printf("LINE\n");
		if(UP[0][1]=='Y' and UP[2][1]=='Y')
		{
			printf("VLINE\n");
			U(0);
			push('U',0);
		}
		F(0); 
		push('F',0);
		righty_alg();
		F(1);
		push('F',1);
		
		oll();
	}
	else if((UP[0][1]=='Y' and UP[1][0]=='Y') or (UP[0][1]=='Y' and UP[1][2]=='Y') or (UP[1][0]=='Y' and UP[2][1]=='Y') or (UP[1][2]=='Y' and UP[2][1]=='Y'))
	{
		printf("L\n");
		int count=0;
		while(!(UP[1][2]=='Y' and UP[2][1]=='Y'))
		{
			count++;
			U(0);
		}
		if(count==1) push('U',0);
		else if(count==2) push('U',2);
		else if(count==3) push('U',1);
		
		
		f(0); 
		push('f',0);
		righty_alg();
		f(1);
		push('f',1);
		
		oll();
	}
	else
	{
		
		printf("DOT\n");
		F(0); 
		push('F',0);
		righty_alg();
		F(1);
		push('F',1);
		f(0); 
		push('f',0);
		righty_alg();
		f(1);
		push('f',1);
		display2();
		oll();
	}
}

void pll(){
	display2();
	int sum=0;
	//int weightage={1,2,4,8};
	for(int i=0;i<4;i++,Y(0)) if(CENTRE[0][0]==CENTRE[0][2]) sum+=pow(2,i);
	
	if(sum==15) 
	{
		
		//aligning corners--start
		int count=0;
		while(XRIGHT[0][0]!=XRIGHT[1][0]) 
		{
			U(0);
			count++;
		}
		if(count==1) push('U',0);
		if(count==2) push('U',2);
		if(count==3) push('U',1);
		//aligning corners--end
		
		display2();
		
		//finding bar and applying  respective algorithm
		int i;
		for(i=0;i<4;i++)
		{
			if(XRIGHT[0][0]==XRIGHT[0][1]) break;
			Y(0);
			
		}
		
		display2();
		
		if(CENTRE[0][0]==CENTRE[0][1]) return;		//already solved 
		
		if(CENTRE[0][0]!=CENTRE[0][1] and i==4)		//no bar found
		{
			edgeACW();
			pll();
			return;
		}
		
		if(CENTRE[1][1]==RIGHT[0][1]) edgeACW();
		edgeACW();
		display2();
		return;
		//pll();
	}
	
	switch(sum)
	{
		case 0:
			hAlgo();
			pll();
			break;
		case 1:
			U(0);
			push('U',0);
			break;
		case 2:
			U(0); U(0);
			push('U',2);
			break;
		case 4:
			U(1);
			push('U',1);
			break;
	}
	hAlgo();
	pll();
	//if()
	//printf("sum= %d",sum);
}

int main()
{
	
	display2();
	
	
	scramble(101);
	display2();
	
	white_layer_solver(2);
	display2();
	printf("WHITE SOLVED\n");
	
	solve_second_layer();
	
	
	display2();
	
	oll();
	display2();
	
	pll();
	print_stack();
	
	
}
