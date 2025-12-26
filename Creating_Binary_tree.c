#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node * create_node(int data){
    struct node *n; //creating a node pointer
    n = (struct node*)malloc(sizeof(struct node)); // allocating memory in the heap
    n->data = data; // setting the data
    n->right = NULL;// setting the left and right children to null
    n->left = NULL;
    return n;
}
int main(){
    //constructing the root node ,can be done manually but using function makes it easy
    struct node *p = create_node(2);
    struct node *p1 = create_node(1);
    struct node *p2 = create_node(4);

    // linking root node with left and right children
    p->left = p1;
    p->right =p2;
}