#include<stdio.h>
#include<strings.h>

#include"Solver.cpp"

//void set_down_to(char face){
//	
//	if(DOWN[1][1]==face){
//		X(0);
//		push('X',0);
//	}
//	else if(UP[1][1]==face){
//		X(1);
//		push('X',1);
//	}
//	else if(LEFT[1][1]==face){
//		Y(1);											
//		push('Y',1);
//	}
//	else if(RIGHT[1][1]==face){
//		Y(0);
//		push('Y',0);
//	}
//	else if(XRIGHT[1][1]==face){
//		Y(0); Y(0);
//		push('Y',0);
//		push('Y',0);
//	}
//}

bool is_second_layer_solved()
{
	if(CENTRE[1][1]!=CENTRE[1][0] or CENTRE[1][1]!=CENTRE[1][2]) return 0;
	if(LEFT[1][1]!=LEFT[1][0] or LEFT[1][1]!=LEFT[1][2]) return 0;
	if(RIGHT[1][1]!=RIGHT[1][0] or RIGHT[1][1]!=RIGHT[1][2]) return 0;
	if(XRIGHT[1][1]!=XRIGHT[1][0] or XRIGHT[1][1]!=XRIGHT[1][2]) return 0;
	return 1;
}


int SLET()		//searches for Second Layer Edges in Third layer
{
	if(CENTRE[0][1]!='Y' and UP[2][1]!='Y') return 1;
	if(RIGHT[0][1]!='Y' and UP[1][2]!='Y') return 2;
	if(LEFT[0][1]!='Y' and UP[1][0]!='Y') return 3;
	if(XRIGHT[0][1]!='Y' and UP[0][1]!='Y') return 4;
	return 0;
}

int SLES()		//searches for Second Layer Edges in Second layer
{
	if(CENTRE[1][0]!= 'Y' and   LEFT[1][2]!='Y')
	{
		if(CENTRE[1][0]!=CENTRE[1][1] or LEFT[1][2]!=LEFT[1][1]) return 1;
	}
	if(CENTRE[1][2]!= 'Y' and   RIGHT[1][0]!='Y')
	{
		if(CENTRE[1][2]!=CENTRE[1][1] or RIGHT[1][0]!=RIGHT[1][1]) return 2;
	}
	if(LEFT[1][0]!='Y'   and   XRIGHT[1][2]!='Y')
	{
		if(LEFT[1][0]!=LEFT[1][1] or XRIGHT[1][2]!=XRIGHT[1][1]) return 3;
	}
	if(RIGHT[1][2]!='Y'   and   XRIGHT[1][0]!='Y') 
	{
		if(RIGHT[1][2]!=RIGHT[1][1] or XRIGHT[1][0]!=XRIGHT[1][1]) return 4;	
	}
	return 0;
}

void solve_second_layer()
{
	if(DOWN[1][1]!='W')
	{
		set_centre_to('W');
		X(1);
		push('X',1);
	}
	
	while(!is_second_layer_solved())
	{
		display2();
		char ch;
		int x;
		while(x=SLET()){
			
			//bring solvable edge to centre-start
			if(x==2){ 
				Y(0); push('Y',0);
			}
			else if(x==3){
				Y(1); push('Y',1); 
			}
			else if(x==4){
				Y(1); Y(1); push('Y',2); 
			}
			//bring solvable edge to centre-start
			
			
			//align edge-start
			int count=-1;
			while(CENTRE[1][1]!=CENTRE[0][1])
			{
				count++;
				d(0);
			}
			if(count==1) count=2;
			else if(count==2) count=1;
			
			if(count!=-1) push('d',count);
			//align edge-end
			
			
			//insert edge --start
			if(LEFT[1][1]==UP[2][1])
			{
				U(1); 
				push('U',1);
				lefty_alg();
				Y(1);
				push('Y',1);
				righty_alg();
			}
			else if(RIGHT[1][1]==UP[2][1])
			{
				U(0); 
				push('U',0);
				righty_alg();
				Y(0);
				push('Y',0);
				lefty_alg();
			}
			//insert edge --end
			
		}
		
		if(x=SLES())
		{
			
			if(x==3)
			{
				Y(1);
				push('Y',1);
				x=1;
			}
			else if(x==4)
			{
				Y(0);
				push('Y',0);
				x=2;
			}
			if(x==1)
			{
				lefty_alg();
				Y(1);
				push('Y',1);
				righty_alg();
			}
			else if(x==2)
			{
				righty_alg();
				Y(0);
				push('Y',0);
				lefty_alg();
			}
		}
		
	}
}

//int main()
//{
//	display2();
//	//display();
//	R(0); R(0); U(0); U(0); R(1); U(1); L(1); U(1); L(0); //L(0); U(0); U(0); 
//	R(0); R(0); U(0); U(0); R(1); U(1); L(1); U(1); //L(0); L(0); U(0); U(0); 
//	
//	X(0); F(0); B(0);
//	M(0); //E(0); S(0);
//	R(0); R(0); U(0); U(0); R(1); U(1); L(1); U(1); L(0); L(0); U(0); U(0); X(1);           
//	R(0); U(0); R(1); R(1); U(1); L(1); U(1);// L(0); L(0); U(0); U(0); X(0);                 
//	R(0); R(0); U(0); U(1); R(1); F(0); R(0); R(0); U(1); R(1); F(1); R(0); U(0); R(0); U(0); F(0); B(0); U(0); r(0); u(0); //M(0); E(0); S(0);
//	F(0); R(0); R(0); U(1); R(1);
//	
//	printf("The cube is now Jumbled\n");
//	display2();
//	printf("Solving...\n");
//	
//	
//	white_layer_solver(2);
//	//display2();
//	
//	solve_second_layer();
//	printf("Second layer Solved! \n");
//	display2();
//
//	U(0); 
//	Y(0);
//	Y(0);
//	Z(0);Z(0);
//	righty_alg(); righty_alg(); righty_alg(); righty_alg();
//	D(0); D(0);
//	righty_alg(); righty_alg();
//	D(0); D(0);
//	set_centre_to('W');
//
//	printf("Cube Solved! \n");
//	display2();
//	print_stack();
//}

int main()
{
	display2();
	 U(0); r(0); u(0);
	R(0); R(0); U(0); U(0);  U(0); r(0); u(0);  R(1); U(1); L(1); U(1); L(0); //L(0); U(0); U(0); 
	R(0); R(0); U(0); U(0); R(1); U(1); L(1); U(0); R(1); U(1);  U(1); //L(0); L(0); U(0); U(0); 
	F(0); R(0); R(0);  U(0); r(0); u(0); U(1); R(1); M(0); E(0);
	 U(0); X(1);           
	R(0); F(0); R(0);
	X(0); F(0); B(0);
	M(0); //E(0); S(0);
	R(0); R(0);  U(0); r(0); u(0);  U(0); U(0); R(1); U(1); L(1);  M(0); E(0); S(0); U(1); L(0); L(0); U(0); U(0); X(1);           
	R(0); F(0); R(0); R(0); U(1); R(1); U(0); R(1); U(1);  M(0); E(0); U(0); R(1); R(1); U(1); L(1); U(1);// L(0); L(0); U(0); U(0); X(0);                 
	R(0); R(0); U(0); U(1); R(1); F(0); R(0); R(0); U(1); R(1); M(0); E(0); S(0); F(1); U(0); R(1);  U(0); X(1);           
	R(0); F(0); R(0); U(1);  R(0); U(0); R(0); U(0); F(0); B(0); U(0); r(0); u(0); M(0);   U(0); r(0); u(0); U(0); R(1); U(1); E(0);  U(0); R(1); U(1); S(0);
	F(0); R(0); R(0);  U(0); r(0); u(0);  U(1); R(1);
	display2();
	
	white_layer_solver(2);
	display2();
	printf("WHITE SOLVED\n");
	
	solve_second_layer();
	
	//set_centre_to('W');
	display2();
	print_stack();
}