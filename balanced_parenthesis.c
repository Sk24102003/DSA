#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define MAX 50
int top=-1;
char stack[MAX];

void push(char item)
{
    if (top ==MAX- 1)
    {
        printf("Stack Overflow!!!\n");
        return;
    }
    stack[++top] = item;
}

char pop()
{
    if (top == -1)
    {
        printf("Stack Underflow!!!\n");
        return 0;
    }
    return stack[top--];
}

int main(void){
    int i;
    char s[MAX], temp;
    int valid=1;
    printf("Enter the expression:\n");
    gets(s);

    for(i=0;s[i]!='\0';i++){
        if(s[i]=='('||s[i]=='{'||s[i]=='['){
            push(s[i]);
        }
        else if(s[i]==')'||s[i]=='}'||s[i]==']'){
            if(top==-1){
                valid=0;    //Invalid 
            }
            else{
                temp=pop();
                if(s[i]==')'&&(temp=='{'||temp=='[')){
                    valid=0;
                    break;
                }
                if(s[i]=='}'&&(temp=='('||temp=='[')){
                    valid=0;
                    break;
                }
                if(s[i]==']'&&(temp=='('||temp=='{')){
                    valid=0;
                    break;
                }
            }
        }
    }
    if(top>=0){
        valid=0;
    }
    if(valid==0){
        printf("Not balanced.");
    }
    else{
        printf("Balanced.");
    }
}