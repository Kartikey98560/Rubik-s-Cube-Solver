#include<stdio.h>
#include<stdlib.h>
#define node struct Node*
struct Node{
	char move;
	int prime;
	struct Node *next;
}*top=NULL;;

void push(char n,int p)
{
	if(top==NULL){
		top=(node)malloc(sizeof (struct Node));
		top->move=n;
		top->prime=p;
		top->next=NULL;
		return;
	}
	node temp = (node)malloc(sizeof (struct Node));
	temp->move = n;
	temp->prime=p;
	temp->next = top;
	top = temp;
}
void pop()
{
	node temp = (node)malloc (sizeof (struct Node));
	if(top== NULL)
		return;
		//printf("Underflow");
	else{
		temp = top;
		top = top->next;
		free(temp);
	}
}
void print_stack()
{
	node temp = top;
	while(temp!=NULL)
	{
		printf("  %c",temp->move);
		if(temp->prime==1) printf("'  ");
		else if(temp->prime==2) printf("2  ");
		temp=temp->next;
	}
	printf("\n");
}
//int main()
//{	
//	push('c',0);
//	print_stack();
//	push('d',0);
//	print_stack();
//	push('g',1);
//	print_stack();
//	push('k',1);
//	print_stack();
//	pop();
//	print_stack();
//	pop();
//	pop();
//	pop();
//	pop();
//	pop();
//	print_stack();
//	return 0;
//}
