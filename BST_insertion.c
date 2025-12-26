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


int isBST(struct node* root){
    struct node* prev = NULL;
    if(root!= NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }else{
        return 1;
    }
}
void insert(struct node* root,int key){
    struct node* prev = NULL;
    while(root!=NULL){
        prev = root; // used bcz at last of loop completion root = NULL so for previous nose to save we made prev variable
        if(root->data==key){
            printf("\n cannot insert %d",key);
            return;
        }else if (root->data > key){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    struct node* new = create_node(key); // directly using function to create new node
    if(key<prev->data){
        prev->left = new;
    }else{
        prev->right = new;
    }
}


int main(){
    //constructing the root node ,can be done manually but using function makes it easy
    struct node *p = create_node(5);
    struct node *p1 = create_node(3);
    struct node *p2 = create_node(6);
    struct node *p3 = create_node(1);
    struct node *p4 = create_node(4);


    // linking root node with left and right children
    p->left = p1;
    p->right =p2;
    p1->left = p3;
    p1->right = p4;

    //         5
    //       /   \
    //      3     6
    //     / \
    //    1   4

    
    printf("\n %d",isBST(p)); // if BST then gives 1

    insert(p,5);
    insert(p,7);
    printf("\n%d",p->right->right->data); //shows inserted node also done by p2->right->data as 7 will be inserted on right of 6 in this BST

}