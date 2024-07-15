#include<stdio.h>
#include<stdlib.h>
#define MAX 50
struct node{
    struct node* lchild;
    int data;
    struct node* rchild;
};
struct node* stack[MAX];
int top = -1;
struct node* root = NULL;
void push(struct node* item){
    if(top==MAX-1){
        printf("Stack Overflow\n");
        return ;
    }
    stack[++top]=item;
}
struct node* pop(){
    if(top==-1){
        printf("Stack Underflow\n");
        return 0;
    }
    return stack[top--];
}
void create(int item){
    struct node *temp, *par=NULL, *ptr;
    ptr = root;
    while(ptr!=NULL){
        par = ptr;
        if(item<ptr->data){
            ptr = ptr->lchild;
        }
        else if(item>ptr->data){
            ptr = ptr->rchild;
        }
        else{
        	printf("Duplicate value can't be inserted!!\n'");
        	return ;
		}
    }
    temp = (struct node* )malloc(sizeof(struct node));
    if(temp==NULL){
        printf("\nInsufficient Memory!!");
        return ;
    }
    temp->data = item;
    temp->lchild = NULL;
    temp->rchild = NULL;

    if(par==NULL){
        root=temp;
    }
    else if(item<par->data){
        par->lchild=temp;
    }
    else{
    	par->rchild=temp;
	}
}

void nrec_pre(struct node* ptr){
    push(ptr);
    do{
        ptr = pop();
        printf("%d ", ptr->data);
        if(ptr->rchild!=NULL){
            push(ptr->rchild);
        }
        if(ptr->lchild!=NULL){
            push(ptr->lchild);
        }
    }while(top!=-1);
}
void nrec_in(struct node* ptr){
    do{
        while(ptr->lchild!=NULL){
            push(ptr);
            ptr = ptr->lchild;
        }
        while(ptr->rchild==NULL){
            printf("%d ",ptr->data);
            if(top==-1)
                return ;
            ptr = pop();
        }
        printf("%d ",ptr->data);
        ptr=ptr->rchild;
    }while(1);
}
void nrec_post(struct node* ptr){
    struct node* q;
    do{
        while(ptr->lchild!=NULL){
            push(ptr);
            ptr = ptr->lchild;
        }
        q = ptr;
        while(ptr->rchild==NULL || ptr->rchild==q){
            printf("%d ", ptr->data);
            q = ptr;
            if(top==-1)
                return ;
            ptr = pop();
        }
        push(ptr);
        ptr = ptr->rchild;
    }while(1);
}
int main(void)
{
    int ch, item;
    do
    {
        printf("\n1.Insert node in the tree");
        printf("\n2.Preorder traversal");
        printf("\n3.Inorder Traversal");
        printf("\n4.Postorder Traversal");
        printf("\n5.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&ch);

        switch (ch)
        {
            case 1:
                printf("\nEnter the item to insert:");
                scanf("%d",&item);
                create(item);
                break;
            case 2:
                printf("\nPreorder Traversal: ");
                nrec_pre(root);
                break;
            case 3:
                printf("\nInorder Traversal: ");
                nrec_in(root);
                break;
            case 4:
                printf("\nPostorder Traversal: ");
                nrec_post(root);
                break;
            case 5:
                exit(0);
            default:
                printf("\nWrong Input!!"); 
        }   
    }while(1);
    return 0;
}