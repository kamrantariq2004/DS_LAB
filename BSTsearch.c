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
struct node * search(struct node * root,int key){
    if(root==NULL){
        return NULL;
    }else if(root->data==key){
        return root;
    }else if(root->data>key){
        return search(root->left,key);
    }else{
        return search(root->right,key);
    }

}
struct node * search_by_iteration(struct node * root,int key){
    while(root!=NULL){
        if(key==root->data){
        return root;
        }else if(root->data>key){
        root = root->left;
        }else{
        root=root->right;
        }
    }
    return NULL;
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

    printf("PreOrder traversal\n");
    preOrder(p);


    printf("PostOrder traversal\n");
    postOrder(p);


    printf("inOrder traversal\n");
    inOrder(p);

    if(isBST(p)){
        printf("\nit is BST");
    }


    struct node *n = search(p,4);
    if(n!=NULL){
        printf("\nfound: %d",n->data);
    }else{
        printf("Element not found");
    }

    struct node *m = search_by_iteration(p,1);
    if(m!=NULL){
        printf("\nfound: %d",m->data);
    }else{
        printf("Element not found");
    }
}