#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};

int isEmpty(struct node *top){
    if(top==NULL){
        return 1;
    }else{
        return 0;
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
void linkedlist_traversal(struct node *ptr){
    while(ptr!=NULL){
        printf("Element: %d\n",ptr->data);
        ptr = ptr->next;
    
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
int Pop(struct node **top){ // one star for pointer ,one for call by reference thing
    if(isEmpty(*top)){
        printf("Stack underflow");
        return 0;
    }else{
        struct node* ptr = *top;
        *top = (*top) ->next;
        int value = ptr->data;
        free(ptr);
        return value;
    }
}
int main(){
    struct node* top =NULL; //firstly empty stack ,we used top instead of head as in stack we use top
    if(isEmpty(top)){
        printf("Stack is empty\n");
    }
    top = Push(top,34);
    top = Push(top,9);
    top = Push(top,90);
    top = Push(top,78);
    linkedlist_traversal(top);

    int element = Pop(&top); //call by reference ,so that top value changes in forward
    printf("Popped element is %d\n",element);
    linkedlist_traversal(top);
    //if we dont want to call by reference thing ,make top a global variable at first and change local variable name from top to something different

}