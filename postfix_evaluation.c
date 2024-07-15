#include<stdio.h>
#include<math.h>
#include<ctype.h>
#define MAX 50
char postfix[MAX];
int x[MAX];
int top=-1;
char stack[MAX];

void push(int item){
    if(top==MAX-1){
        printf("Stack Overflow!!\n");
        return ;
    }
    stack[++top]=item;
}

int pop(){
    if(top==-1){
        printf("Stack Underflow!!\n");
        return 0;
    }
    return stack[top--];
}

int postfix_Evaluation(){
    int a, b, temp, i=0;
    while(postfix[i]!='\0'){
        if(isalpha(postfix[i])){
            push(x[i]);
        }
        else{
            a=pop();
            b=pop();
            switch(postfix[i]){
                case '+':
                        temp=b+a;
                        break;
                case '-':
                        temp=b-a;
                        break;
                case '*':
                        temp=b*a;
                        break;
                case '/':
                        temp=b/a;
                        break;
                case '%':
                        temp=b%a;
                        break;
                case '^':
                        temp=pow(b,a);
                        break;
            }
            push(temp);
        }
        i++;
    }
    return pop();
}

int main(void){
    int i=0;
    printf("Enter the expression: ");
    gets(postfix);
    while(postfix[i]!='\0'){
        if(isalpha(postfix[i])){
            printf("\nEnter the value for the operand %c : ",postfix[i]);
            scanf("%d",&x[i]);
        }
        i++;
    }
    printf("The value of postfix expression is : %d",postfix_Evaluation());
    return 0;
}