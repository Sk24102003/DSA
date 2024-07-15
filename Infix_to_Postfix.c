#include <stdio.h>
#include <string.h>
#define MAX 50

char infix[MAX], postfix[MAX], stack[MAX];
int top = -1;

void push(char item)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow!!!");
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
int prec(char symbol)
{
    switch (symbol)
    {
    case '(':
        return 0;
    case '-':
    case '+':
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
void infix_to_postfix()
{
    int i, j = 0;
    char next;
    for (i = 0; infix[i] != '\0'; i++)
    {
        if (infix[i] == '(')
        {
            push(infix[i]);
        }
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '%' || infix[i] == '^' || infix[i] == '$')
        {
            while (top != -1 && prec(infix[i]) <= prec(stack[top]))
            {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while ((next = pop()) != '(')
            {
                postfix[j++] = next;
            }
        }
        else
        {
            postfix[j++] = infix[i];
        }
        postfix[j] = '\0';
    }
    while (top != -1)
    {
        postfix[j++] = pop();
    }
}
int main(void)
{
    printf("Enter the infix expression: ");
    gets(infix);
    infix_to_postfix();
    printf("Postfix Expression is: %s", postfix);
    return 0;
}
