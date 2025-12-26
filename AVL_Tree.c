#include<stdio.h>
#include<stdlib.h>
struct node{
    int key;
    struct node* right;
    struct node* left;
    int height;
};
int height(struct node* n){
    if(n==NULL){
        return 0;
    }
    return n->height;
}
struct node * createNode(int key){
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->key=key;
    p->right=NULL;
    p->left=NULL;
    p->height=1;
    return p;
}
void preOrder(struct node* root){
    if(root!= NULL){
        printf("element is %d\n",root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}
int max(int a,int b){
    return a>b?a:b;
}
int get_BalanceFactor(struct node* n){
    if(n==NULL){
        return 0;
    }
    return height(n->left) - height(n->right);
}
struct node* right_rotate(struct node* y){
    struct node* x = y->left;
    struct node* T2 = x->right;

    x->right = y;
    y->left = T2;


    y->height = max(height(y->right),height(y->left))+1;
    x->height = max(height(x->right),height(x->left))+1;

    return x;
}
struct node* left_rotate(struct node* x){
    struct node* y = x->right;
    struct node* T2 = y->left;

    y->left = x;
    x->right = T2;


    y->height = max(height(y->right),height(y->left))+1;
    x->height = max(height(x->right),height(x->left))+1;

    return y;
}
struct node* insert(struct node* n,int key){
    if(n==NULL){
        return (createNode(key));
    }
    if(key < n->key){
        n->left = insert(n->left,key);
    }
    else if(key > n->key){
        n->right = insert(n->right,key);
    }else{
        return n;
    }
    n->height= 1+ max(height(n->right),height(n->left));

    int BF = get_BalanceFactor(n);

    //left left case
    if(BF>1 && key<n->left->key){
        return right_rotate(n);
    }

    //right right case
    if(BF<-1 && key>n->right->key){
        return left_rotate(n);
    }
    //left right case
    if(BF>1 && key>n->left->key){
        n->left = left_rotate(n->left);
        return right_rotate(n);
    }
    //right left case
    if(BF<-1 && key<n->right->key){
        n->right = left_rotate(n->right);
        return left_rotate(n);
    }
    return n;
}
int main(){
    struct node* root =NULL;
    root = insert(root,1);
    root = insert(root,2);
    root = insert(root,4);
    root = insert(root,5);
    root = insert(root,6);
    root = insert(root,3);
    preOrder(root);
    
    return 0;

}



