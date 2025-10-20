#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int stack[SIZE],TOS=-1;
void push(int);
int pop();
void display();

int main(){
    int choice,item;
    while(1){
        printf("\n 1.Push\n 2.Pop\n 3.Display\n 4.Exit\n Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("\n\n Enter the element to be Pushed: ");
                scanf("%d",&item);
                push(item);
                break;
            case 2:item=pop();
                if(item!=-1){
                    printf("\n Popped item is %d",item);
                }
                break;
            case 3:display();
                break;
            case 4:exit(1);
            default:printf("\n Entered wrong choice");
        }
    }
    return 0;
}
void push(int x){
    if(TOS==(SIZE-1)){
        printf("\n Stack Overflow\n\n");
        return;
    }
    stack[++TOS]=x;
}
int pop(){
    int x;
    if(TOS==-1){
        printf("\n Stack Underflow\n\n");
        return(-1);
    }
    x=stack[TOS];
    TOS--;
    return x;
}
void display(){
    int i;  
    if(TOS==-1){
        printf("\n Stack is Empty\n\n");
        return;
    }
    printf("\n Elements in Stack are: \n");
    for(i=TOS;i>=0;i--){
        printf("\n %d",stack[i]);
        printf("\n");
    }
}
