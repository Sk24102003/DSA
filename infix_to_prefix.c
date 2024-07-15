#include <stdio.h>
#include <string.h>
#define MAX 50

char infix[MAX], prefix[MAX], stack[MAX];
int top = -1;
int len;
void push(char item){
    if(top==MAX-1){
        printf("\nStack Overflow!!");
        return ;
    }
    stack[++top]=item;
}

char pop(){
    if(top==-1){
        printf("\nStack Underflow!!");
        return 0;
    }
    return stack[top--];
}

int prec(char symbol){
    switch(symbol){
        case ')':
                return 0;
        case '+':
        case '-':
                return 1;
        case '*':
        case '/':
        case '%':
                return 2;
        case '^':
        case '$':
                return 3;
    }
}

void infix_to_prefix(){
    int i, j=0;
    char next;
    for(i=len-1;i>=0;i--){
        if(infix[i]==')'){
            push(infix[i]);
        }
        else if(infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='/'||infix[i]=='%'||infix[i]=='^'||infix[i]=='$'){
            while(top!=-1 && prec(infix[i])<prec(stack[top])){
                prefix[j++] = pop();
            }
            push(infix[i]);
        }
        else if(infix[i]=='('){
            while((next=pop())!=')'){
                prefix[j++]=next;
            }
        }
        else{
            prefix[j++]=infix[i];
        }
        prefix[j]='\0';
    }
    while(top!=-1){
        prefix[j++]=pop();
    }
}
int main(void){
    printf("Enter the infix expression: ");
    gets(infix);
    len=strlen(infix);
    infix_to_prefix();
    printf("The prefix expression is: ");
    for(int i=len-1;i>=0;i--){
        printf("%c",prefix[i]);
    }
    return 0;
}