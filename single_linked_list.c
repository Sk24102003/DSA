#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* link;
};
struct node *start=NULL;
void sllInsertAtBegin(int item){
	struct node *temp;
	temp=(struct node* )malloc(sizeof(struct node));
	if(temp==NULL){
		printf("Insufficient Memory!!\n");
		return ;
	}
	temp->data=item;
	temp->link=start;
	start=temp;
}
void sllInsertAtEnd(int item){
	struct node *temp, *ptr;
	temp=(struct node* )malloc(sizeof(struct node));
	if(temp==NULL){
		printf("Insufficient Memory!!\n");
		return ;
	}
	temp->data=item;
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
}
void sllInsertAtAny(int item, int pos){
	struct node *temp, *ptr;
	int i;
	temp=(struct node* )malloc(sizeof(struct node));
	if(temp==NULL){
		printf("Insufficient Memory!!\n");
		return ;
	}
	temp->data=item;
	/*for 1st insertion*/
	if(pos==1){
		temp->link=start;
		start=temp;
	}
	else{
		ptr=start;
		for(i=1;i<=pos-2 && ptr!=NULL;i++){
			ptr=ptr->link;
		}
		if(ptr==NULL){
			printf("Invalid Position.\n");
			free(temp);
			return ;
		}
		temp->link=ptr->link;
		ptr->link=temp;
	}
}
void sllDeleteAtBegin(){
	struct node *ptr;
	if(start==NULL){
		printf("No node in the single linked list to delete.\n");
		return ;
	}
	ptr=start;
	start=start->link;
	free(ptr);
}
void sllDeleteFromEnd(){
	struct node *ptr, *prevptr;
	int i;
	/*No node in the single linked list*/
	if(start==NULL){
		printf("No node in the single linked list to delete.\n");
		return ;
	}
	/*There is exactly one node in the single linked list*/
	ptr=start;
	if(ptr->link==NULL){
		start=NULL;
	}
	/*There is more than one node*/
	else{
		while(ptr->link!=NULL){
			prevptr=ptr;
			ptr=ptr->link;
		}
		prevptr->link=NULL;
	}
	free(ptr);	
}
void sllDeleteFromAny(int pos){
	struct node *ptr, *prevptr;
	int i;
	/*No node to delete*/
	if(start==NULL){
		printf("No node in the single linked list to delete.\n");
		return ;
	}
	ptr=start;
	if(pos==1){
		start=NULL;
	}
	else{
		for(i=1;i<=pos-1;i++){
			prevptr=ptr;
			ptr=ptr->link;
			if(ptr==NULL){
				printf("Invalid Position.\n");
				return ;
			}	
		}
		prevptr->link=ptr->link;
	}
	free(ptr);
	ptr=NULL;
}
void reverse(){
	struct node *curr, *next=NULL, *prev=NULL;
	curr=start;
	while(curr!=NULL){
		next=curr->link;
		curr->link=prev;
		prev=curr;
		curr=next;
	}
	start=prev;
}

void swap(struct node *ptr1, struct node *ptr2){
	int temp = ptr1->data;
	ptr1->data=ptr2->data;
	ptr2->data=temp;
}
void sort(){
	int swapped;
	struct node *last=NULL, *ptr;
	if(start==NULL){
		printf("No node in the single linked list!!\n");
		return ;
	}
	do{
		ptr=start;
		swapped=0;
		while(ptr->link!=last){
			if(ptr->data>ptr->link->data){
				swap(ptr, ptr->link);
				swapped=1;
			}
			ptr=ptr->link;
		}
		last=ptr;
	}while(swapped);
}
int count(){
	struct node *ptr;
	int nodeCount=0;
	if(start==NULL){
		return 0;
	}
	ptr=start;
	while(ptr!=NULL){
		nodeCount++;
		ptr=ptr->link;
	}
	return nodeCount;
}
void sllMaxMin(){
	int max, min;
	struct node *ptr;
	if(start==NULL){
		return 0;
	}
	
}
void sllDisplay(){
	struct node *ptr;
	if(start==NULL){
		printf("No node in single linked list in display.\n");
		return ;
	}
	ptr=start;
	printf("Start->");
	while(ptr!=NULL){
		printf("%d->",ptr->data);
		ptr=ptr->link;
	}
	printf("NULL");
}
int main(void){
	int ch,item,pos;
	
	do{
		printf("\n\n**********Single Linked List**********");
		
		printf("\n1.Create Single Linked List by Insertion At Begin");
		printf("\n2.Create Single Linked List by Insertion At End");
		printf("\n3.Insert at any position of Single Linked List");
		
		printf("\n4.Delete from Begin Position of Single Linked List");
		printf("\n5.Delete from End Position of Single Linked List");
		printf("\n6.Delete from Any Position of Single Linked List");
		
		printf("\n7.Reverse the Single Linked List:");
		printf("\n8.Sort the Linked List");
		printf("\n9.Count the no of nodes in the Single Linked List");
		
		printf("\n10.Find the largest and smallest element in the Single Linked List");
		
		printf("\n11.Display the Linked List");
		printf("\n12.Exit");
		
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		
		switch(ch){
			
			case 1:
					printf("Enter the item to be insert:");
					scanf("%d",&item);
					sllInsertAtBegin(item);
					break;
			case 2:
					printf("Enter the item to be insert:");
					scanf("%d",&item);
					sllInsertAtEnd(item);
					break;
			case 3:
				   	printf("Enter the item to be insert:");
				   	scanf("%d",&item);  // 100
				   	
				   	printf("Enter position of insertion >=1:");
				   	scanf("%d",&pos);
				   	
				   	sllInsertAtAny(item,pos);
					break;
			case 4:
					sllDeleteAtBegin();
					break;
			case 5:
					sllDeleteFromEnd();
					break;
			case 6:
				    printf("Enter position of deletion:");
				    scanf("%d",&pos);
					sllDeleteFromAny(pos);
					break;
			case 7:
					reverse();
					break;	
			case 8:
					sort();
					break;
			case 9:
					printf("No of nodes in the Single Linked List is %d",count());
					break;
				
			case 10:
					sllMaxMin();
					break;
										
			case 11:
					sllDisplay();
					break;
			case 12:
					exit(0);	
			default:
					printf("Wrong  Choice !!!");
		}
		
	}while(1);
	return 0;
}
