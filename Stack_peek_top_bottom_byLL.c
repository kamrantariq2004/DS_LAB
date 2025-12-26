#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
void linkedlist_traversal(struct node *ptr){
    while(ptr!=NULL){
        printf("Element: %d\n",ptr->data);
        ptr = ptr->next;
    
    }
}
int isFull(struct node *top){ //full when we cannot add any node further
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr==NULL){
        return 1;
    }else{
        return 0;
    }
}
struct node* Push(struct node *top,int data){
    if(isFull(top)){
        printf("Stack Overflow");
    }else{
        struct node* ptr = (struct node*)malloc(sizeof(struct node));
        ptr->data=data;
        ptr->next = top;
        top = ptr;
    }
    return top;
}
int peek(struct node* top,int position){ //index = position -1
    struct node* ptr = top;
    for(int i =0;(i<position -1 && ptr!= NULL);i++){
        ptr = ptr-> next;
    }
    if(ptr!=NULL){
        return ptr->data;
    }else{
        return -1;
    }
}
int Stacktop(struct node* top){
    return top ->data;
}
int StackBottom(struct node* top){
    struct node* ptr = top;
    for(int i =0;ptr->next!= NULL;i++){
        ptr = ptr-> next;
    }
    return ptr->data;
}
int main(){
    struct node* top =NULL; //firstly empty stack ,we used top instead of head as in stack we use top
    
    top = Push(top,34);
    top = Push(top,9);
    top = Push(top,90);
    top = Push(top,78);
    linkedlist_traversal(top);

    for(int j=1;j<=4;j++){
        printf("the value at position %d is %d:\n",j,peek(top,j));
    }

    printf("the element at top is %d\n",Stacktop(top));
    printf("the element at bottom is %d",StackBottom(top));


}