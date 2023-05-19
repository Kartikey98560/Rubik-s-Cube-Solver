#include<stdio.h>

#include"Second_layer_solver.cpp"

void oll();
void solve_cross();
void solve_crab();
void super_algo();
void solve_turtle();
void solve_fish(int sum);

void super_algo()
{
	R(0);			U(0);			R(1);			U(0);			R(0);			U(0); U(0);		R(1);
	push('R',0);	push('U',0);	push('R',1);	push('U',0);	push('R',0);	push('U',2);	push('R',1);
	//push('C',0);
}

void solve_crab()
{
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

void solve_turtle()
{
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

void solve_fish(int sum)
{
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

void solve_cross()
{
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

void oll()
{
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

int main()
{
	display2();
//	 U(0); r(0); u(0);
//	R(0); R(0); U(0); U(0);  U(0); r(0); u(0);  R(1); U(1); L(1); U(1); L(0); L(0); U(0); U(0); 
//	R(0); R(0); U(0); U(0); R(1); U(1); L(1); U(0); R(1); U(1);  U(1); L(0); L(0); U(0); U(0); 
//	F(0); R(0); R(0);  U(0); r(0); u(0); U(1); R(1); M(0); E(0);
//	 U(0); X(1);           
//	R(0); F(0); R(0);
//	X(0); F(0); B(0);
//	M(0); E(0); S(0);
//	R(0); R(0);  U(0); r(0); u(0);  U(0); U(0); R(1); U(1); L(1);  R(1); U(1); E(0);  U(0); R(1); U(1); S(0); M(0); E(0); S(0); U(1); L(0); L(0); U(0); U(0); X(1);           
//	R(0); F(0); R(0); R(0); U(1); R(1); U(0); R(1); U(1);  M(0); E(0); U(0); R(1); R(1); U(1); L(1); U(1); L(0); L(0); U(0); U(0); X(0);                 
//	R(0); R(0); U(0); //U(1); R(1); F(0); R(0); R(0); U(1); R(1); M(0); E(0); S(0); F(1); U(0); R(1);  U(0); X(1);           
//	R(0); F(0); R(0); U(1);  R(0); U(0); R(0); U(0); F(0); B(0); U(0); r(0); u(0); M(0);   U(0); r(0); u(0); U(0);// R(1); U(1); E(0);  U(0); R(1); U(1); S(0);
//	F(0); R(0); R(0);  U(0); r(0); u(0);  U(1); R(1);
	//display2();

	for(int i=0;i<102;i++) {
		long int ran = rand();
		int cases = ran%10;
		switch(cases) {
			case 0:
			F(0);
			break;
			case 1:
				R(0);
				break;
			case 3:
				U(0);
				break;
			case 4:
				D(0);
				break;
			case 5:
				U(1);
				break;
			case 6:
				F(1);
				break;
			case 7:
				M(0);
				break;
			case 8:
				E(1);
				break;
			case 9:
				f(0);
				break;
		}
		
	}
	
	
	display2();
	
	white_layer_solver(2);
	display2();
	printf("WHITE SOLVED\n");
	
	solve_second_layer();
	
	
	display2();
	
	oll();
	display2();
	
	print_stack();
}