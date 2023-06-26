#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#define node struct Node*
struct Node{
	char type;			//type tells us whether the node contains a message or  an algorith,  A means algorithm,   M means message
	
	char message[1000];
	
	char move=' ';
	int prime=0;
	
	struct Node *next;
}*top=NULL;


void push_message(char msg[])
{
	if(top==NULL){
		top=(node)malloc(sizeof (struct Node));
		top->type='M';
		strcpy(top->message,msg);
		top->next=NULL;
		return;
	}
	node temp = (node)malloc(sizeof (struct Node));
	strcpy(temp->message,msg);
	temp->type='M';
	temp->next = top;
	top = temp;
}

void push(char n,int p)
{
	if(top==NULL)
	{
		top=(node)malloc(sizeof (struct Node));
		top->move=n;
		top->type='A';
		top->prime=p;
		top->next=NULL;
		return;
	}
	node temp = (node)malloc(sizeof (struct Node));
	temp->move = n;
	temp->type='A';
	temp->prime=p;
	temp->next = top;
	top = temp;
}

void print_stack(node temp = top)
{
	
	
	if(temp->next!=NULL) print_stack(temp->next);
	if(temp->type=='A')
	{
		printf("  %c",temp->move);
		if(temp->prime==1) printf("'");
		else if(temp->prime==2) printf("2");
		
	}
	else if(temp->type=='M' )
	{
		printf("\n\n%s  :",temp->message);
	}
	temp=NULL;
	
}

//int main()
//{	
//	push('c',0);
//	print_stack();
//	
//	push('j',2);
//	print_stack();
//	
//	push('d',0);
//	print_stack();	
//	
//	char msg[]="apply bkfks fbjf";
//	push_message(msg);
//	
//	printf("%c",top->move);
//	printf("%s",top->message);
//
//	
//	push('c',0);
//	print_stack();
//	
//	push('j',1);
//	print_stack();
//	
//	push('d',0);
//	print_stack();
//	
//
//	print_stack();
//	return 0;
//}
