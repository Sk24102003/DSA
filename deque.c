#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int rear=-1;
int front=-1;
int deque[MAX];

void dqinsert_at_rear(int item){
    if(front==(rear+1)%MAX){
        printf("Queue is full!!\n");
        return ;
    }
    else if(front==-1){
        front=rear=0;
    }
    else{
        rear=(rear+1)%MAX;
    }
    deque[rear]=item;
}

void dqinsert_at_front(int item){
    if(front==(rear+1)%MAX){
        printf("Queue is full!!\n");
        return ;
    }
    else if(front==-1){
        front=rear=0;
    }
    else{
        front=(front+MAX-1)%MAX;
    }
    deque[front]=item;
}

void dqdelete_at_front(){
    if(front==-1){
        printf("Queue is empty!!\n");
        return ;
    }
    printf("Deleted element is : %d\n",deque[front]);
    if(front==rear){
        front=rear=-1;
    }
    else{
        front=(front+1)%MAX;
    }
}

void dqdelete_at_rear(){
    if(front==-1){
        printf("Queue is empty!!\n");
        return ;
    }
    printf("Deleted element is : %d\n",deque[rear]);
    if(front==rear){
        front=rear=-1;
    }
    else{
        rear=(rear+MAX-1)%MAX;
    }
}

void dqdisplay1(){
    int i;
    if(front==-1){
        printf("Queue is empty!!\n");
        return ;
    }
    printf("The elements of the queue are:\n");
    if(front<=rear){
        for(i=front;i<=rear;i++){
            printf("%d\n",deque[i]);
        }
    }
    else{
        for(i=front;i<=MAX-1;i++){
            printf("%d\n",deque[i]);
        }
        for(i=0;i<=rear;i++){
            printf("%d\n",deque[i]);
        }
    }
}

void dqdisplay2(){
    int i;
    if(front==-1){
        printf("Queue is empty!!\n");
        return ;
    }
    printf("The elements of the queue are:\n");
    if(front<=rear){
        for(i=rear;i>=front;i--){
            printf("%d\n",deque[i]);
        }
    }
    else{
        for(i=0;i<=rear;i++){
            printf("%d\n",deque[i]);
        }
        for(i=MAX-1;i>=front;i--){
            printf("%d\n",deque[i]);
        }
    }
}

int main(void){
    int ch, item;
    do
    {
        printf("\n**Deque**\n");
        printf("1.Insertion at rear end\n");
        printf("2.Insertion at front end\n");
        printf("3.Deletion at front end\n");
        printf("4.Deletion at rear end\n");
        printf("5.Display 1\n");
        printf("6.Display 2\n");
        printf("7.Exit\n");

        printf("Enter your choice:\n");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1:
            printf("Enter the element to be inserted:\n");
            scanf("%d",&item);
            dqinsert_at_rear(item);
            break;
        case 2:
            printf("Enter the element to be inserted:\n");
            scanf("%d",&item);
            dqinsert_at_front(item);
            break;
        case 3:
            dqdelete_at_front();
            break;
        case 4:
            dqdelete_at_rear();
            break;
        case 5:
            dqdisplay1();
            break;
        case 6:
            dqdisplay2();
            break;
        case 7:
            exit(0);
        default:
            printf("Wrong Input!\n");
            printf("Please provide correct input.\n");
            break;
        }
    } while (1);
    return 0;
}