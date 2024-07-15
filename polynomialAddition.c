#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coeff;
    int expo;
    struct node* link;
};

struct node* create(struct node* start){
    int n, i, a, b;
    struct node* ptr, *temp;
    printf("\nEnter the no. of nodes:");
    scanf("%d",&n);
    for(i=1; i<=n; i++){
        printf("Enter the coefficient term #%d:",i);
        scanf("%d",&a);
        printf("Enter the exponent term #%d:",i);
        scanf("%d",&b);

        temp=(struct node* )malloc(sizeof(struct node));
        temp->coeff=a;
        temp->expo=b;
        if(start==NULL || b>start->expo){
            temp->link=start;
            start=temp;
        }
        else{
            ptr=start;
            while(ptr->link!=NULL && ptr->link->expo>=b){
                ptr=ptr->link;
            }
            temp->link=ptr->link;
            ptr->link=temp;
        }
    }
    return start;
}
void polyAdd(struct node *p, struct node *q){
    struct node *temp, *start=NULL, *ptr;
    while(p!=NULL && q!=NULL){
        if(p->expo>q->expo){
            temp=(struct node* )malloc(sizeof(struct node));
            temp->coeff=p->coeff;
            temp->expo=p->expo;
            temp->link=NULL;
            if(start==NULL){
                start=temp;
            }
            else{
                ptr=start;
                while(ptr->link!=NULL){
                    ptr=ptr->link;
                }
                ptr->link=temp;
            }
            p=p->link;
        }
        else if(p->expo<q->expo){
            temp=(struct node* )malloc(sizeof(struct node));
            temp->coeff=q->coeff;
            temp->expo=q->expo;
            temp->link=NULL;
            if(start==NULL){
                start=temp;
            }
            else{
                ptr=start;
                while(ptr->link!=NULL){
                    ptr=ptr->link;
                }
                ptr->link=temp;
            }
            q=q->link;
        }
        else if(p->expo==q->expo){
            temp=(struct node* )malloc(sizeof(struct node));
            temp->coeff=p->expo+q->coeff;
            temp->expo=p->expo;
            temp->link=NULL;
            if(start==NULL){
                start=temp;
            }
            else{
                ptr=start;
                while(ptr->link!=NULL){
                    ptr=ptr->link;
                }
                ptr->link=temp;
            }
            p=p->link;
            q=q->link;
        }
    }
    while(p!=NULL){
        temp=(struct node* )malloc(sizeof(struct node));
            temp->coeff=p->expo;
            temp->expo=p->expo;
            temp->link=NULL;
            if(start==NULL){
                start=temp;
            }
            else{
                ptr=start;
                while(ptr->link!=NULL){
                    ptr=ptr->link;
                }
                ptr->link=temp;
            }
            p=p->link;
    }
    while(q!=NULL){
        temp=(struct node* )malloc(sizeof(struct node));
            temp->coeff=q->expo;
            temp->expo=q->expo;
            temp->link=NULL;
            if(start==NULL){
                start=temp;
            }
            else{
                ptr=start;
                while(ptr->link!=NULL){
                    ptr=ptr->link;
                }
                ptr->link=temp;
            }
            q=q->link;
    }
    display(start);
}
void display(struct node *ptr){
    if(ptr==NULL){
        printf("\nNo node in the linked list to display!!");
        return ;
    }
    while(ptr!=NULL){
        printf("%dx^%d->",ptr->coeff,ptr->expo);
        ptr=ptr->link;
    }
    printf("NULL");
}
int main(void){
    int ch;
    struct node *start1=NULL, *start2=NULL;
    do{
        printf("\n1.Enter the first polynomial");
        printf("\n2.Enter the second polynomial");
        printf("\n3.Addition of first polynomial and second polynomial");
        printf("\nEnter your Choice:");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                start1=create(start1);
                break;
            
            case 2:
                start2=create(start2);
                break;
            
            case 3:
                polyAdd(start1,start2);
                break;
        }
    }while(1);
    return 0;
}