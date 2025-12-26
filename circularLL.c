#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void linkedlist_traversal(struct node *head){
    struct node* ptr = head;
    do{
        printf("element is :%d\n",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
    
}


//insert at first

struct node *insert_at_first(struct node* head,int data){
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    struct node* ptr = head->next;
    while(ptr->next!=head){
        ptr=ptr->next;
    }
    ptr->next=newNode;
    newNode->next = head;
    head = newNode;
    return head;



}
int main(){
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;
    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));
    fourth = (struct node*)malloc(sizeof(struct node));
    head->data = 4;
    head->next = second;
    second->data = 3;
    second->next = third;
    third->data = 2;
    third->next = fourth;
    fourth->data = 1;
    fourth->next = head;

    linkedlist_traversal(head);


    head= insert_at_first(head,98);
    printf("\nLL after Insertion\n");
    linkedlist_traversal(head);

    return 0;
}
