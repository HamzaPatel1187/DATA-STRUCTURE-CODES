/*	Implementation of Doubly Linked List
Doubly Linked Lists are used in navigation systems, undo/redo features, browsers’ back-forward functionality, and music playlists.
*/

#include<stdio.h>
#include<stdlib.h>

// Node structure
struct node
{
    int data;
    struct node *next, *prev;
};

// Function to insert node at the end of a given DLL
struct node *insertAtEnd(struct node *h, int d)
{
    struct node *p, *tmp;
    p = (struct node *)malloc(sizeof(struct node)); // creating a new node
    if (p == NULL)
    {
        printf("\nMemory allocation failed.");
        return h;
    }
    p->data = d;
    p->next = NULL;
    p->prev = NULL;

    if (h == NULL)
    {   // DLL is empty
        h = p;
    }
    else
    {   // DLL is not empty
        tmp = h;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = p;
        p->prev = tmp;
    }
    return h;
}

// Function to insert node at the start
struct node *insertAtStart(struct node *h, int d)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL)
    {
        printf("\nMemory allocation failed.");
        return h;
    }
    p->data = d;
    p->prev = NULL;
    p->next = h;
    if (h != NULL)
        h->prev = p;
    h = p;
    return h;
}

// Function to insert a node after a given key
struct node *insertAfter(struct node *h, int key, int d)
{
    struct node *p, *tmp;
    p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL)
    {
        printf("\nMemory allocation failed.");
        return h;
    }
    p->data = d;
    p->next = NULL;
    p->prev = NULL;

    if (h == NULL)
    {   // DLL is empty
        h = p;
    }
    else
    {
        tmp = h;
        while (tmp != NULL && tmp->data != key)
            tmp = tmp->next;
        if (tmp != NULL)
        {
            p->next = tmp->next;
            p->prev = tmp;
            if (tmp->next != NULL)
                tmp->next->prev = p;
            tmp->next = p;
        }
        else
            printf("\nGiven node %d not found in the list.", key);
    }
    return h;
}

// Function to remove the last node
struct node *removelast(struct node *h)
{
    struct node *tmp;
    if (h == NULL)
    {
        printf("\nList is empty.");
        return h;
    }
    tmp = h;
    while (tmp->next != NULL)
        tmp = tmp->next;

    printf("\nDeleted node: %d", tmp->data);
    if (tmp->prev == NULL)
    {   // Only one node in list
        free(tmp);
        h = NULL;
    }
    else
    {
        tmp->prev->next = NULL;
        free(tmp);
    }
    return h;
}

// Function to remove the node present after the given key
struct node *removeAfter(struct node *h, int key)
{
    struct node *tmp, *p;
    if (h == NULL)
    {
        printf("\nList is empty.");
        return h;
    }

    tmp = h;
    while (tmp != NULL && tmp->data != key)
        tmp = tmp->next;

    if (tmp == NULL)
    {
        printf("\nKey %d not found in list.", key);
    }
    else if (tmp->next == NULL)
    {
        printf("\nNo node exists after the key %d.", key);
    }
    else
    {
        p = tmp->next;
        printf("\nDeleted node: %d", p->data);
        tmp->next = p->next;
        if (p->next != NULL)
            p->next->prev = tmp;
        free(p);
    }
    return h;
}

// Function to display the given DLL
void display(struct node *h)
{
    struct node *tmp;
    if (h == NULL)
    {
        printf("\nDLL is empty.");
        return;
    }
    printf("\n\nDoubly Linked List (Forward Order):\n");
    tmp = h;
    while (tmp != NULL)
    {
        printf("<-%d-> ", tmp->data);
        tmp = tmp->next;
    }
}

// Function to display given DLL in reverse order
void displayRev(struct node *h)
{
    struct node *tmp;
    if (h == NULL)
    {
        printf("\nDLL is empty.");
        return;
    }
    tmp = h;
    while (tmp->next != NULL)
        tmp = tmp->next;

    printf("\n\nDoubly Linked List (Reverse Order):\n");
    while (tmp != NULL)
    {
        printf("<-%d-> ", tmp->data);
        tmp = tmp->prev;
    }
}

// Main function
int main()
{
    struct node *head = NULL;
    int ch, d, k;

    while (1)
    {
        printf("\n\n\t\tMENU");
        printf("\n1. Insert at End");
        printf("\n2. Insert at Start");
        printf("\n3. Insert After");
        printf("\n4. Remove Last");
        printf("\n5. Remove After");
        printf("\n6. Display (Forward)");
        printf("\n7. Display (Reverse)");
        printf("\n8. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("\nEnter data to insert at end: ");
                scanf("%d", &d);
                head = insertAtEnd(head, d);
                break;

            case 2:
                printf("\nEnter data to insert at start: ");
                scanf("%d", &d);
                head = insertAtStart(head, d);
                break;

            case 3:
                printf("\nEnter key after which to insert: ");
                scanf("%d", &k);
                printf("Enter data to insert: ");
                scanf("%d", &d);
                head = insertAfter(head, k, d);
                break;

            case 4:
                head = removelast(head);
                break;

            case 5:
                printf("\nEnter key after which node should be removed: ");
                scanf("%d", &k);
                head = removeAfter(head, k);
                break;

            case 6:
                display(head);
                break;

            case 7:
                displayRev(head);
                break;

            case 8:
                printf("\nExiting...");
                exit(0);

            default:
                printf("\nInvalid choice! Please try again.");
        }
    }
    return 0;
}

/*
Conclusion:
From this experiment, we learned:
1) How to implement and manipulate a Doubly Linked List in C.
2) How each node maintains links to both its previous and next nodes.
3) How insertion and deletion operations are simplified using ‘prev’ pointers.
4) How to traverse a list in both forward and reverse directions.
This experiment provided a deeper understanding of dynamic memory allocation and pointer manipulation.
Doubly Linked Lists are useful in applications like undo-redo systems, text editors, and navigation history management.
*/
