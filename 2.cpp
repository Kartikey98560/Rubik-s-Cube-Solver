char CENTRE[][3]={{'B','R','G'},{'W','R','Y'},{'W','O','R'}};
char UP[][3]={{'B','R','Y'},{'Y','W','W'},{'Y','B','O'}};
char DOWN[][3]={{{'O','W','G'},{'R','Y','W'},{'W','Y','R'}};
char LEFT[][3]={{{'R','G','O'},{'B','G','B'},{'G','Y','B'}};
char RIGHT[][3]={{'W','G','G'},{'B','B','G'},{'Y','R','B'}};
char XRIGHT[][3]={{'O','G','W'},{'O','O','O'},{'Y','O','R'}};


//R2 U2 R' U' L' U' L2 U2 X R2 U2 R' U' L' U' L2 U2
R(0); R(0); U(0); U(0); R(1); U(1); L(1); U(1); L(0); L(0); U(0); U(0); X(0); R(0); R(0); U(0); U(0); R(1); U(1); L(1); U(1); L(0); L(0); U(0); U(0);


void giv_array(char (* face)[3]){
	printf("{")
	for(int i=0;i<3;i++) printf("{/'%c/',/'%c/',/'%c},",face[i][0],face[i][1],face[i][2]);
	printf("}\n");
}
void giv_cube_array()
{
	giv_array(CENTRE);
	giv_array(UP);
	giv_array(DOWN);
	giv_array(LEFT);
	giv_array(RIGHT);
	giv_array(XRIGHT);
}


	R(0);
	R(0);
//	display(0);
	
	U(0);
	U(0);
//	display(0);
	
	R(1); 
//	display(0);
	
	U(1);
//	display(0);
	
	L(1);
//	display(0);
	
	U(1);
//	display(0);
	
	L(0);
	L(0);
//	display(0);
	
	U(0);
	U(0);
//	display(0);
	
	X(0);
//	display(0);
	
	R(0);
	R(0);
//	display(0);
	
	U(0);
	U(0);
//	display(0);
	
	R(1);
//	display(0);
	
	U(1);
//	display(0);
	
	L(1);
//	display(0);
	
	U(1);
//	display(0);
	
	L(0);
	L(0);
//	display(0);
	
	U(0);
	U(0);
//	display();

