#include<stdio.h>

char CENTRE[][3]={{'R','R','R'},{'R','R','R'},{'R','R','R'}};
char UP[][3]={{'W','W','W'},{'W','W','W'},{'W','W','W'}};
char DOWN[][3]={{'Y','Y','Y'},{'Y','Y','Y'},{'Y','Y','Y'}};
char LEFT[][3]={{'G','G','G'},{'G','G','G'},{'G','G','G'}};
char RIGHT[][3]={{'B','B','B'},{'B','B','B'},{'B','B','B'}};
char XRIGHT[][3]={{'O','O','O'},{'O','O','O'},{'O','O','O'}};

void revolve_cube(char (* st)[3],char (* nd)[3],char (* rd)[3],char (* th)[3],int dr);
void rotate(char (* face)[3], int dr);
void display();
void revolve(char *st,char *nd,char *rd,char *th,int dr);

//char CENTRE[][3]={{'Y','Y','W'},{'O','R','R'},{'O','R','W'}};
//char UP[][3]={{'W','W','Y'},{'O','W','W'},{'G','G','B'}};
//char DOWN[][3]={{'Y','W','O'},{'R','Y','W'},{'R','Y','Y'}};
//char LEFT[][3]={{'O','G','O'},{'B','G','B'},{'W','Y','B'}};
//char RIGHT[][3]={{'R','O','B'},{'G','B','B'},{'G','B','G'}};
//char XRIGHT[][3]={{'R','G','B'},{'R','O','Y'},{'R','O','G'}};
//
//char DOWN[][3]={{'B','O','R'},{'G','Y','B'},{'W','Y','G'}};

void giv_array(char (* face)[3]){
	printf("{");
	for(int i=0;i<3;i++) printf("{\'%c\',\'%c\',\'%c\'},",face[i][0],face[i][1],face[i][2]);
	printf("}\n");
}
void giv_cube_array(){
	giv_array(CENTRE);
	giv_array(UP);
	giv_array(DOWN);
	giv_array(LEFT);
	giv_array(RIGHT);
	giv_array(XRIGHT);
}

void display(){
	for(int i=0;i<3;i++) printf("      | %c %c %c |\n",UP[i][0],UP[i][1],UP[i][2]);
	printf("_____________________________\n");
	for(int i=0;i<3;i++) printf("%c %c %c | %c %c %c | %c %c %c | %c %c %c\n",LEFT[i][0],LEFT[i][1],LEFT[i][2],CENTRE[i][0],CENTRE[i][1],CENTRE[i][2],RIGHT[i][0],RIGHT[i][1],RIGHT[i][2],XRIGHT[i][0],XRIGHT[i][1],XRIGHT[i][2]);
	printf("_____________________________\n");
	for(int i=0;i<3;i++) printf("      | %c %c %c |\n",DOWN[i][0],DOWN[i][1],DOWN[i][2]);
	printf("\n\n");
}

//for revolution of one layer
void revolve(char *st,char *nd,char *rd,char *th,int dr){				//dr-direction   1=acw, 0=cw

	char temp;
	if(dr==1) for(int i=0;i<3;temp=st[i], st[i]=nd[i], nd[i]=rd[i], rd[i]=th[i], th[i]=temp,i++);	//acw
	else for(int i=0;i<3;temp=st[i], st[i]=th[i], th[i]=rd[i], rd[i]=nd[i], nd[i]=temp,i++);		//cw
}


//for revolution of whole cube
void revolve_cube(char (* st)[3],char (* nd)[3],char (* rd)[3],char (* th)[3],int dr){			//dr-direction   1=abnormal, 0=normal

	char temp[3][3];
	if(dr==1)
	{
		for(int i=0;i<3;i++) for(int j=0;j<3;j++) temp[i][j]=st[i][j];
		for(int i=0;i<3;i++) for(int j=0;j<3;j++) st[i][j]=nd[i][j];
		for(int i=0;i<3;i++) for(int j=0;j<3;j++) nd[i][j]=rd[i][j];
		for(int i=0;i<3;i++) for(int j=0;j<3;j++) rd[i][j]=th[i][j];
		for(int i=0;i<3;i++) for(int j=0;j<3;j++) th[i][j]=temp[i][j];
	}
	else
	{
		for(int i=0;i<3;i++) for(int j=0;j<3;j++) temp[i][j]=st[i][j];
		for(int i=0;i<3;i++) for(int j=0;j<3;j++) st[i][j]=th[i][j];
		for(int i=0;i<3;i++) for(int j=0;j<3;j++) th[i][j]=rd[i][j];
		for(int i=0;i<3;i++) for(int j=0;j<3;j++) rd[i][j]=nd[i][j];
		for(int i=0;i<3;i++) for(int j=0;j<3;j++) nd[i][j]=temp[i][j];
	}
	//st=nd,nd=rd,rd=th,th=temp;
}


void rotate(char (* face)[3], int dr){									//dr-direction   1=acw, 0=cw

	char temp;
	if(dr==1)
	{
		temp=face[0][0],face[0][0]=face[0][2],face[0][2]=face[2][2],face[2][2]=face[2][0],face[2][0]=temp;	//acw
		temp=face[0][1],face[0][1]=face[1][2],face[1][2]=face[2][1],face[2][1]=face[1][0],face[1][0]=temp;
	}
	else
	{
		temp=face[0][0],face[0][0]=face[2][0],face[2][0]=face[2][2],face[2][2]=face[0][2],face[0][2]=temp;	//cw
		temp=face[0][1],face[0][1]=face[1][0],face[1][0]=face[2][1],face[2][1]=face[1][2],face[1][2]=temp;
	}
}

void D(int flag_prime){     											//D(0)=D   D(1)=D'  

	revolve(&LEFT[2][0],&CENTRE[2][0],&RIGHT[2][0],&XRIGHT[2][0],flag_prime);
	rotate(DOWN,flag_prime);
}
void U(int flag_prime){
	
	revolve(&LEFT[0][0],&CENTRE[0][0],&RIGHT[0][0],&XRIGHT[0][0],!flag_prime);
	rotate(UP,flag_prime);
}


void X(int flag_prime){													//Revolution in R directon
	revolve_cube(CENTRE,UP,XRIGHT,DOWN,flag_prime);
	rotate(RIGHT,flag_prime);
	rotate(LEFT,!flag_prime);
	if(!flag_prime)
	{
		rotate(DOWN,flag_prime);
		rotate(DOWN,flag_prime);
	}
	if(flag_prime)
	{
		rotate(UP,flag_prime);
		rotate(UP,flag_prime);
	}
	
	rotate(XRIGHT,flag_prime);
	rotate(XRIGHT,flag_prime);
}
void Y(int flag_prime){
	
	revolve_cube(CENTRE,LEFT,XRIGHT,RIGHT,flag_prime);
	rotate(UP,flag_prime);
	rotate(DOWN,!flag_prime);
}
void Z(int flag_prime){
	revolve_cube(UP,RIGHT,DOWN,LEFT,flag_prime);
	rotate(CENTRE,flag_prime);
	rotate(UP,flag_prime);
	rotate(RIGHT,flag_prime);
	rotate(LEFT,flag_prime);
	rotate(DOWN,flag_prime);
	rotate(XRIGHT,!flag_prime);
}


void R(int flag_prime){													//dr-direction   1=acw, 0=cw
	Z(0);
	D(flag_prime);
	Z(1);
}
void L(int flag_prime){
	Z(0);
	U(flag_prime);
	Z(1);
}

void F(int flag_prime){
	X(0);
	U(flag_prime);
	X(1);
}
void B(int flag_prime){
	X(1);
	U(flag_prime);
	X(0);
}

void M(int flag_prime){
	R(flag_prime);
	L(!flag_prime);
	X(!flag_prime);
}
void E(int flag_prime){
	U(flag_prime);
	D(!flag_prime);
	Y(!flag_prime);
}
void S(int flag_prime){
	F(!flag_prime);
	B(flag_prime);
	Z(flag_prime);
}

void u(int flag_prime){
	D(flag_prime);
	Y(flag_prime);
}
void d(int flag_prime){
	U(flag_prime);
	Y(!flag_prime);
}
void r(int flag_prime){
	L(flag_prime);
	X(flag_prime);
}
void l(int flag_prime){
	R(flag_prime);
	X(!flag_prime);
}
void f(int flag_prime){
	B(flag_prime);
	Z(flag_prime);
}
void b(int flag_prime){
	F(flag_prime);
	Z(!flag_prime);
}


//int main()
//{
//	display();
//	R(0); R(0); U(0); U(0); R(1); U(1); L(1); U(1); L(0); L(0); U(0); U(0); X(0);
//	R(0); R(0); U(0); U(0); R(1); U(1); L(1); U(1); L(0); L(0); U(0); U(0); X(1);
//	
//	display();
//	Y(0);
//	display();
//	Y(1);
//	display();
//	giv_cube_array();
//		
//}
