#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int rear=-1;
int front=-1;
int pqueue[MAX];

void pqinsert(int item){
    int i, j, temp;
    if(rear==MAX-1){
        printf("\nQueue is full!!");
        return ;
    }
    else if(front==-1){
        front=rear=0;
    }
    else{
        rear++;
    }
    pqueue[rear]=item;
    for(i=front;i<rear;i++){
        for(j=i+1;j<=rear;j++){
            if(pqueue[i]>pqueue[j]){
                temp=pqueue[i];
                pqueue[i]=pqueue[j];
                pqueue[j]=temp;
            }
        }
    }
}

int pqdelete(){
    if(front == -1){
        printf("\nQueue is Empty!!");
        return 0;
    }
    printf("\nDeleted element is :%d",pqueue[front]);
    if(front == rear){
        front=rear=-1;
    }
    else{
        front=front+1;
    }
}

void pqdisplay(){
    int i;
    if(front == -1){
        printf("\nQueue is Empty!!");
        return ;
    }
    printf("\nThe elements of the queue are: ");
    for(i=front;i<=rear;i++){
        printf("\n%d",pqueue[i]);
    }
}

int main(void){
    int ch, item;
    do{
        printf("\n******Priority Queue Implementation Using Linear Queue******");
        printf("\n1.Insert");
        printf("\n2.Delete");
        printf("\n3.Display");
        printf("\n4.Exit");

        printf("\nEnter your choice: ");
        scanf("%d",&ch);

        switch (ch)
        {
            case 1:
                printf("\nEnter the item to be inserted: ");
                scanf("%d",&item);
                pqinsert(item);
                break;
            case 2:
                pqdelete();
                break;
            case 3:
                pqdisplay();
                break;
            case 4:
                exit(0);
            default:
                printf("Wrong Input!! Please provide correct input..");
        }
    }while(1);
    return 0;
}