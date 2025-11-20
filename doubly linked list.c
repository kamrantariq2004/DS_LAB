#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next,*prev;
};


struct node* createnode( int value)
{
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=value;
	newnode->next=NULL;
	newnode->prev=NULL;
	return newnode;

	
}

void printlist(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void deletion(struct node**head,int pos)
{
	struct node*temp=*head;
	if(pos==1)
	{
		*head=temp->next;
		temp->prev=NULL;
		
	}
	else
	{
	
	for(int i=1;i<=pos-2 && temp!=NULL;i++)
	{
		temp=temp->next;
	}
	temp->next=temp->next->next;
	temp->next->prev=temp;
}
	return;
}


void insertion(struct node**head,int posn,int v)
{
	
	struct node*temp=*head;
		struct node*newnode=(struct node*)malloc(sizeof(struct node));
			newnode->data=v;
		if(posn==1)
		{
			newnode->data=v;
		
			newnode->next=*head;
			newnode->prev=NULL;
		*head=newnode;
			
		}
		else
		{
		
		  for (int i = 1; i < posn - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newnode;

    temp->next = newnode;
}
		return;
	
}

int main()
{
	struct node*head=NULL;
	struct node*temp=NULL;
	int n,value,pos,posn,v;
	printf("enter the no of nodes in your linked list :- ");
	scanf("%d",&n);
	for(int i=1;i<n+1;i++)
	{
		printf("\nenter the value for node %d :- ",i);
		scanf("%d",&value);
		struct node*newnode=createnode(value);
		if(head==NULL)
		{
		head=newnode;
		temp=newnode;
		temp->prev=NULL;
		}
		else
		{
			temp->next=newnode;
			newnode->prev=temp;
			temp=temp->next;
		}
	}
	
	 printlist(head);
	 printf("\nenter the position from which you want to delete a node :-");
	 scanf("%d",&pos);
	deletion(&head,pos);
	printf("\nupdated list :-  ");
	 printlist(head);
	printf("\nenter the position where you want to insert a new node :- ");
	scanf("%d",&posn);
	printf("\nenter the value for new node :- ");
	scanf("%d",&v);
	insertion(&head,posn,v);
		printf("\nupdated list :-  ");
	 printlist(head);
	}