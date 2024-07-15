#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
};
struct node* top = NULL;
void push(int item){
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    if(temp == NULL){
        printf("Insufficient Memory");
        return ;
    }
    temp->data = item;
    temp->link = top;
    top = temp;
}
void pop(){
    struct node* temp;
    if(top == NULL){
        printf("\nEmpty Stack!!");
        return ;
    }
    temp = top;
    top = top->link;
    printf("\nThe deleted element is %d", temp->data);
    free(temp);
}
void display(){
    struct node* ptr;
    if(top == NULL){
        printf("\nEmpty Stack");
        return ;
    }
    ptr = top;
    printf("Start->");
    while(ptr!=NULL){
        printf("%d->",ptr->data);
        ptr = ptr->link;
    }
    printf("NULL");
}
int main(void){
    int ch, item, pos;
    do{
        printf("\nLinked Stack\n");
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Display");
        printf("\n4.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("\nEnter the item to be inserted:");
                scanf("%d",&item);
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
                printf("\nWrong Input!!!");
                printf("Please provide correct choice.");
        }
    }while(1);
    return 0;
}
