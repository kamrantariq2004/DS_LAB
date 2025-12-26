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
void preOrder(struct node* root){
    if(root!= NULL){
        printf("element is %d\n",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(struct node* root){
    if(root!= NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("element is %d\n",root->data);
    }
}
void inOrder(struct node* root){
    if(root!= NULL){
        inOrder(root->left);
        printf("element is %d\n",root->data);
        inOrder(root->right);
    }
}

int main(){
    //constructing the root node ,can be done manually but using function makes it easy
    struct node *p = create_node(2);
    struct node *p1 = create_node(1);
    struct node *p2 = create_node(4);
    struct node *p3 = create_node(5);
    struct node *p4 = create_node(7);


    // linking root node with left and right children
    p->left = p1;
    p->right =p2;
    p1->left = p3;
    p1->right = p4;

    //         2
    //       /   \
    //      1     4
    //     / \
    //    5   7

    printf("PreOrder traversal\n");
    preOrder(p);


    printf("PostOrder traversal\n");
    postOrder(p);


    printf("inOrder traversal\n");
    inOrder(p);
}