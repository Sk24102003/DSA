#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node* lchild;
    int data;
    struct node* rchild;
};

struct node* create(struct node* ptr, int item){    
    if(ptr==NULL){
        ptr = (struct node* )malloc(sizeof(struct node));
        ptr->data=item;
        ptr->lchild=NULL;
        ptr->rchild=NULL;
    }
    else if(item<ptr->data){
        ptr->lchild=create(ptr->lchild, item);  
    }
    else if(item>ptr->data){
        ptr->rchild=create(ptr->rchild, item);  
    }
    else{
        printf("Duplicate keys!!\n");
    }
    return ptr; 
}
void preorder(struct node* ptr){
    if(ptr!=NULL){
        printf("%d\t", ptr->data);
        preorder(ptr->lchild);
        preorder(ptr->rchild);
    }
}
void inorder(struct node* ptr){
    if(ptr!=NULL){
        inorder(ptr->lchild);
        printf("%d\t", ptr->data);
        inorder(ptr->rchild);
    }
}
void postorder(struct node* ptr){
    if(ptr!=NULL){
        postorder(ptr->lchild);
        postorder(ptr->rchild);
        printf("%d\t", ptr->data);
    }
}
int main(void)
{
    int ch, item;
    struct node* root = NULL;
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
                root = create(root, item);
                break;
            case 2:
                printf("\nPreorder Traversal: ");
                preorder(root);
                break;
            case 3:
                printf("\nInorder Traversal: ");
                inorder(root);
                break;
            case 4:
                printf("\nPostorder Traversal: ");
                postorder(root);
                break;
            case 5:
                exit(0);
            default:
                printf("\nWrong Input!!"); 
        }   
    }while(1);
    return 0;
}