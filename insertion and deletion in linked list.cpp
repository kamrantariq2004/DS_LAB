#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node* next;
};


struct node* createnode(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
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


void insertion(struct node** head, int posn, int newvalue) {
    struct node* newnode = createnode(newvalue);

    
    if (posn == 1) {
        newnode->next = *head;
        *head = newnode;
        return;
    }

    struct node* temp = *head;
    for (int i = 1; temp != NULL && i < posn - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}


void deletion(struct node** head, int pos) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct node* temp = *head;

    
    if (pos == 1) {
        *head = temp->next;  
        free(temp);
        return;
    }

    
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range!\n");
        return;
    }

    struct node* delnode = temp->next;
    temp->next = delnode->next;
    free(delnode);
}


int main() {
    int n, value;
    struct node* head = NULL;
    struct node* temp = NULL;

    printf("Enter the number of nodes in your list: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Enter value for node %d: ", i);
        scanf("%d", &value);
        struct node* newnode = createnode(value);

        if (head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    printf("\nInitial Linked List: ");
    printlist(head);

    
    int posn, newvalue;
    printf("\nEnter the position where you want to insert a new node: ");
    scanf("%d", &posn);
    printf("Enter the value of the new node: ");
    scanf("%d", &newvalue);

    insertion(&head, posn, newvalue);

    printf("\nList after insertion: ");
    printlist(head);

    
    int pos;
    printf("\nEnter the position of the node you want to delete: ");
    scanf("%d", &pos);

    deletion(&head, pos);

    printf("\nList after deletion: ");
    printlist(head);

    return 0;
}