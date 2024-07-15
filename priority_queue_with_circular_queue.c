#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int front=-1;
int rear=-1;
int pqueue[MAX];

void pqinsert(int item){
    int i, j, temp;
    if(front==(rear+1)%MAX){
        printf("Queue is full!!\n");
        return ;
    }
    else if(front == -1){
        front=rear=0;
    }
    else{
        rear=(rear+1)%MAX;
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
    if(front==-1){
        printf("Queue is empty!!\n");
        return ;
    }
    printf("The elements of the queue are:\n");
    if(front<=rear){
        for(i=front;i<=rear;i++){
            printf("%d\n",pqueue[i]);
        }
    }
    else{
        for(i=front;i<=MAX-1;i++){
            printf("%d\n",pqueue[i]);
        }
        for(i=0;i<=rear;i++){
            printf("%d\n",pqueue[i]);
        }
    }
}

int main(void){
    int ch, item;
    do
    {
        printf("\n**Priority Queue Implementation With CIrcular Queue**\n");
        printf("1.insert\n");
        printf("2.delete\n");
        printf("3.display\n");
        printf("4.Exit\n");
        
        printf("Enter your choice:\n");
        scanf("%d",&ch);

        switch (ch)
        {
            case 1:
                printf("Enter the item to be inserted:\n");
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
                printf("Wrong Input!!!\n");
                break;
        }
    } while (1);
    return 0;
}