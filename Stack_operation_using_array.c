#include <stdio.h>
#include <stdlib.h>

int *stack;
int top = -1, n;

void push(int item)
{
    if (top == n - 1)
    {
        printf("Stack Overflow!!!\n");
        return;
    }
    *(stack + (++top)) = item;
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow!!!\n");
        return;
    }
    printf("Deleted item is %d\n", *(stack + (top--)));
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty!!!\n");
        return;
    }
    printf("Stack elements are :\n");
    for (int i = top; i >= 0; i--)
    {
        printf("%d\n", *(stack + i));
    }
}

int main(void)
{
    int ch, item;

    printf("Enter the size : ");
    scanf("%d", &n);

    stack = (int *)malloc(n * sizeof(int));
    if (stack == NULL)
    {
        printf("Unsuccessful Memory Allocation!!!");
        exit(0);
    }

    do
    {
        printf("\n***********Menu************\n");
        printf("1.PUSH\n");
        printf("2.POP\n");
        printf("3.DISPLAY\n");
        printf("4.EXIT\n");

        printf("Enter Your Choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the item to be inserted : ");
            scanf("%d", &item);
            push(item);
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);

        default:
            printf("Wrong Option! Please enter valid option!!");
        }

    } while (1);
}