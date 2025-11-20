#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};


struct node* createnode(int value)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}


void printlist(struct node* head)
{
    struct node* temp = head;
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("\nCircular Linked List :- ");
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}


void insertion(struct node** head, int pos, int value)
{
    struct node* newnode = createnode(value);
    if (*head == NULL)
    {
        *head = newnode;
        newnode->next = *head;
        return;
    }

    struct node* temp = *head;

    if (pos == 1)
    {
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = *head;
        *head = newnode;
        return;
    }

    for (int i = 1; i < pos - 1 && temp->next != *head; i++)
    {
        temp = temp->next;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}



void deletion(struct node** head, int pos)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct node* temp = *head;
    struct node* delnode;

    if (pos == 1)
    {
        if (temp->next == *head)
        {
            printf("Deleted node: %d\n", temp->data);
            free(temp);
            *head = NULL;
            return;
        }

        while (temp->next != *head)
        {
            temp = temp->next;
        }

        delnode = *head;
        temp->next = (*head)->next;
        *head = (*head)->next;
        printf("Deleted node: %d\n", delnode->data);
        free(delnode);
        return;
    }

    for (int i = 1; i < pos - 1 && temp->next != *head; i++)
    {
        temp = temp->next;
    }

    if (temp->next == *head)
    {
        printf("Invalid position!\n");
        return;
    }

    delnode = temp->next;
    temp->next = delnode->next;
    printf("Deleted node: %d\n", delnode->data);
    free(delnode);
}


int main()
{
    struct node* head = NULL;
    struct node* temp = NULL;
    int n, value, pos, choice;

    printf("Enter the number of nodes you want to create :- ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        printf("Enter the value for node %d :- ", i);
        scanf("%d", &value);
        insertion(&head, i, value);
    }

    printlist(head);

    do
    {
        printf("\n1. Insert node\n2. Delete node\n3. Display list\n4. Exit");
        printf("\nEnter your choice :- ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nEnter position where you want to insert :- ");
                scanf("%d", &pos);
                printf("Enter value :- ");
                scanf("%d", &value);
                insertion(&head, pos, value);
                printlist(head);
                break;

            case 2:
                printf("\nEnter position you want to delete :- ");
                scanf("%d", &pos);
                deletion(&head, pos);
                printlist(head);
                break;

            case 3:
                printlist(head);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 4);

    return 0;
}
