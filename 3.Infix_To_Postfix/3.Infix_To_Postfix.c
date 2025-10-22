#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Max 30

void push(char);
char pop();
void infix_to_postfix();
int priority(char);
int IsEmpty();

char stack[Max];
int top;
char inf[Max], post[Max];
int main(){
    top=-1;
    printf("\n Enter Infix Expression: ");
    gets(inf);
    infix_to_postfix();
    printf("\n Postfix Expression is %s",post);
    return 0;
}
void infix_to_postfix(){
    int i, p=0;
    char next, symbol;
    for(i=0;i<strlen(inf);i++){
        symbol=inf[i];
        switch(symbol){
            case '(': push(symbol); break;
            case ')': while((next=pop())!='('){post[p++]=next;} break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '$':
                while(!IsEmpty() && priority(symbol)<=priority(stack[top])){
                    post[p++]=pop();}
                    push(symbol);
                break;
            default: post[p++]=symbol;
        }
    }
    while(!IsEmpty())
        post[p++]=pop();
    post[p]='\0';   
}
int priority(char s){
    switch(s){
        case '(': return 0;
        case '+': 
        case '-': return 1;
        case '*': 
        case '/': return 2;
        case '$': return 3;
        default : return -1;
    }
}
int IsEmpty(){
    if(top==-1)
        return 1;
    else
        return 0;
    /*return top==-1;*/
}
void push(char/*int is cancled*/ s){
    if(top==Max-1){
        printf("\n Stack Overflow");
        exit(1);
    }
    stack[++top]=s;
    //char is taken bcoz it pushes symbol's in stack not numbers
}
char /*int is cancled*/ pop(){
    if(IsEmpty()){
        printf("\n Stack Underflow");
        exit(1);
    }
    return(stack[top--]);
}