#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define Max 30

void push(int);
int pop();
int eval_post();

char postfix[Max];
int top=-1, stack[Max];

int main(){
    int value;
    printf("\n Enter the Postfix Expression: ");
    gets(postfix);
    value = eval_post();
    printf("\n Value of Expression is: %d",value);
    return 0;
}
void push(int s){
    if(top==Max-1){
        printf("\n Stack Overflow");
        exit(1);
    }
    stack[++top]=s;
}
int pop(){
    if(top==-1){
        printf("\n Stack Underflow");
        exit(1);
    }
    return(stack[top--]);
}
int eval_post(){
    int a,b,temp,i;
    for(i=0;i<strlen(postfix);i++){
        if(postfix[i]<='9' && postfix[i]>='0'){
            push(postfix[i] - '0');
        }
        else{
            a=pop();
            b=pop();
            switch(postfix[i]){
                case '+': temp = b+a;
                    break;
                case '-': temp = b-a;
                    break;
                case '*': temp = b*a;
                    break;
                case '/': temp = b/a;
                    break;
                default: printf("\n Invalid Operator: %c", postfix[i]);
                exit(1);
            }
            push(temp);
        }
    }
    return pop();
}
