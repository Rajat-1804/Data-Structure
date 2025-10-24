#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int queue[MAX], front, rear;

int isfull(){
    if(rear==-1){
        return 1;
    }else{
        return 0;
    }
}

int isempty(){
    if(front==-1 || front==rear+1){
        return 1;
    }else{
        return 0;
    }
}

void enq(int x){
    if(isfull){
        printf("\nQueue is Overflow");
    }
    if(front==-1){
        front = 0;
    }
    queue[++rear] = x;
}

int deq(){
    int x;
    if(isempty){
        printf("\nQueue is Underflow");
        return -1;
    }
    x = queue[front];
    front++;
    return x;
}

void display(){
    int i;
    if(isempty){
        printf("\nQueue is Empty");
    }
    printf("\nElements in Queue are: ");
    for(i=front; i<= rear; i++){
        printf("\n%d",queue[i]);
    }
}

void main(){
    int ch, item;
    front=rear=-1;
    while(1){
        printf("\n1.Enqueue\n2.Dequeue\n3.display\n4.Exit\nEnter you choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("\nEnter the item to be added: ");
                scanf("%d",&item);
                enq(item);
                break;
            case 2:
                item= deq();
                if(item!=-1){
                    printf("\nDeleted item is: %d",item);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                exit(1);
            default: printf("\nWrong choice");
        }
    }
}