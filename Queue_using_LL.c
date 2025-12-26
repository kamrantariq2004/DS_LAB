#include<stdio.h>
#include<stdlib.h>
struct node* front = NULL;//make them global variable
struct node* rear= NULL;
struct node{
    int data;
    struct node* next;
};
void LLTRaversal(struct node* ptr){
    while(ptr != NULL){
        printf("Element : %d\n",ptr->data);
        ptr=ptr->next;
    }
}
void Enqueue(int val){ //we didn't use struct node *front & rear as arguments bcz we already took them as global
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr==NULL){ //new element null then LL is full
        printf("Queue is full");
    }else{
        ptr->data = val;
        ptr->next = NULL;
        if(front == NULL){
            front = rear = ptr;
        }else{
            rear->next = ptr;
            rear = ptr;
        }
    }
}
int Dequeue(){
    int a = -1;
    struct node *ptr = front;
    if(front==NULL){
        printf("Queue is empty");
    }else{
        front = front->next;
        a = ptr->data;
        free(ptr);
    }
    return a;
}
int main(){

    printf("\nDequeue element : %d\n",Dequeue()); // return -1 since a =-1 and queue is empty
    Enqueue(56);
    Enqueue(78);
    Enqueue(90);
    LLTRaversal(front);
    printf("\nDequeue element : %d",Dequeue());
    printf("\nDequeue element : %d",Dequeue());





}