#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define MAX 50

int top = -1;
int stack[MAX];

void push(int rem)                      //push(1)
{
    if (top == MAX - 1)                 
    {
        printf("Stack Overflow!!");
        return;
    }
    stack[++top] = rem;                    //1100       //top=3
}

int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow!!");
        return;
    }
    return stack[top--];                //return 1
}
int main(void)
{
    int num, rem;
    printf("Enter the number: ");
    scanf("%d", &num);      //12

    while (num != 0)        //F
    {
        rem = num % 2;      //1
        push(rem);          //push(1)
        num = num / 2;      //0
    }

    while (top != -1)           //T
    {
        printf("%d", pop());        //1
    }
    return 0;
}