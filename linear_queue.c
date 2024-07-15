#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int rear=-1;
int front=-1;
int queue[MAX];

void enqueue(int item){
    if(rear == MAX-1){
        printf("\nQueue is full!!");
        return ;
    }
    //for 1st insertion
    else if(front == -1){
        front=rear=0;
    }
    //for other insertion
    else{
        rear++;
    }
    queue[rear]=item;
}

int dequeue(){
    if(front == -1){
        printf("\nQueue is Empty!!");
        return 0;
    }
    printf("Deleted element is :%d",queue[front]);
    if(front == rear){
        front=rear=-1;
    }
    else{
        front=front+1;
    }
}

void qdisplay(){
    int i;
    if(front == -1){
        printf("\nQueue is Empty!!");
        return ;
    }
    printf("\nThe elements of the queue are: ");
    for(i=front;i<=rear;i++){
        printf("\n%d\n",queue[i]);
    }
}

int main(void){
    int ch, item;
    do
    {
        printf("\nLinear Queue");
        printf("\n1.Insertion");
        printf("\n2.Deletion");
        printf("\n3.Display");
        printf("\n4.Exit");

        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("\nEnter the item to be inserted: ");
                scanf("%d",&item);
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                qdisplay();
                break;
            case 4:
                exit(0);
            default:
                printf("Wrong Input!! Please provide correct input..");
        }
    } while (1);
    return 0;
}