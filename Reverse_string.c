#include<stdio.h>
#include<string.h>
#define MAX 50
int top=-1;
char stack[MAX];
void push(char item)
{
	if(top==MAX-1)
	{
		printf("Stack Overflow");
		return;
	}
	stack[++top]=item;
}
char pop()
{
	if(top==-1)
	{
		printf("Empty Stack");
		return 0;
	}
	return stack[top--];
}
int main()
{
	char s[MAX],i=0;
	printf("Enter the String:");
	gets(s);
	while(s[i]!='\0')
	{
		push(s[i]);
		i++;
	}
	i=0;
	while(top!=-1)
	{
		s[i]=pop();
		i++;
	}
	s[i]='\0';	
	printf("Reversed String is %s",s);
	return 0;
}