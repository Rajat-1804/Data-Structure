#include<stdio.h>
#include<stdlib.h>
#define size 5
struct stack{
	int item[size], top;
};
void push(struct stack*,int);
int pop(struct stack*);
void display(struct stack*);

int main(){
	struct stack s;
	int ch, x;
	s.top=-1;
	while(1){
		printf("\n1.Push \n2.Pop \n3.Display \n4.Exit \nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("\n Enter data to be pushed: ");
				scanf("%d",&x);
				push(&s,x);
				break;
			case 2: x=pop(&s);
				if(x!=-1)
					printf("\n Item Poped is %d", x);
				break;
			case 3: display(&s);
				break;
			case 4: exit(1);
			default:printf("\n wrong choice");
		}
	}
	return 0;
}
void push (struct stack *ps, int x){
	if(ps->top==size-1){
		printf("\n stack overflow");
		exit(1);
	}
	ps-> item[++(ps->top)]=x;
}
int pop(struct stack *ps){
	if(ps->top==-1){
		printf("\n stack underflow");
		exit(1);
	}
	return(ps->item[ps->top--]);
}
void display(struct stack *ps){
	int i;
	if (ps->top==-1)
	{
		printf("\n stack is empty");
		return;
	}
	printf("\n Element are: ");
	for (i = ps->top; i >- 0; i--)
	{
		printf("\n %d", ps->item[i]);
	}
}