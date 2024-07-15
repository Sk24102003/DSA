#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int front = -1;
int rear = -1;
int cqueue[MAX];

void cqinsert(int item){
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
    cqueue[rear]=item;
}

int cqdelete(){
    if(front==-1){
        printf("Queue is empty!!\n");
        return 0;
    }
    printf("Deleted element is : %d\n",cqueue[front]);
    if(front==rear){
        front=rear=-1;
    }
    else{
        front=(front+1)%MAX;
    }
}

void cqdisplay(){
    int i;
    if(front==-1){
        printf("Queue is empty!!\n");
        return ;
    }
    printf("The elements of the queue are:\n");
    if(front<=rear){
        for(i=front;i<=rear;i++){
            printf("%d\n",cqueue[i]);
        }
    }
    else{
        for(i=front;i<=MAX-1;i++){
            printf("%d\n",cqueue[i]);
        }
        for(i=0;i<=rear;i++){
            printf("%d\n",cqueue[i]);
        }
    }
}

int main(void){
    int ch, item;
    do
    {
        printf("**Circular Queue Operations**\n");
        printf("1.cqinsert\n");
        printf("2.cqdelete\n");
        printf("3.cqdisplay\n");
        printf("4.Exit\n");
        
        printf("Enter your choice:\n");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1:
            printf("Enter the item to be inserted:\n");
            scanf("%d",&item);
            cqinsert(item);
            break;
        case 2:
            cqdelete();
            break;
        case 3:
            cqdisplay();
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