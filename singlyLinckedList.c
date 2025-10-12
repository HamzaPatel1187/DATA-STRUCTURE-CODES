/* Implement Singly Linked List.

Linked lists are widely used in dynamic memory allocation, stacks, queues, graphs, and polynomial representation.
*/

#include<stdio.h>
#include<stdlib.h>

// Structure definition for a node
struct node
{
    int data;
    struct node *next;
};

// Function to insert node at the end of given linked list
struct node *insertAtEnd(struct node *h, int d)
{
    struct node *p, *tmp;
    p = (struct node *)malloc(sizeof(struct node)); // creating a new node
    if(p == NULL) // check if memory allocation failed
    {
        printf("\nNot enough memory to allocate.");
        return h;
    }
    p->data = d;
    p->next = NULL;

    if(h == NULL) // if list is empty
    {
        h = p;
    }
    else
    {
        tmp = h;
        while(tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = p;
    }
    return h;
}

// Function to insert node at the beginning
struct node *insertAtStart(struct node *h, int d)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    if(p == NULL)
    {
        printf("\nMemory allocation failed.");
        return h;
    }
    p->data = d;
    p->next = h;
    h = p;
    return h;
}

// Function to insert new node after the given key
struct node *insertAfter(struct node *h, int key, int d)
{
    struct node *p, *tmp;
    if(h == NULL)
    {
        printf("\nList is empty. Inserting as first node...");
        h = insertAtStart(h, d);
        return h;
    }
    tmp = h;
    while(tmp != NULL && tmp->data != key)
        tmp = tmp->next;

    if(tmp == NULL)
        printf("\nKey not found in list.");
    else
    {
        p = (struct node *)malloc(sizeof(struct node));
        p->data = d;
        p->next = tmp->next;
        tmp->next = p;
    }
    return h;
}

// Function to remove the last node of the linked list
struct node *removelast(struct node *h)
{
    struct node *tmp, *prev;
    tmp = h;

    if(h == NULL)
    {
        printf("\nList is empty. Nothing to remove.");
        return h;
    }

    if(h->next == NULL) // only one node
    {
        printf("\nDeleted node: %d", h->data);
        free(h);
        h = NULL;
    }
    else
    {
        while(tmp->next != NULL)
        {
            prev = tmp;
            tmp = tmp->next;
        }
        printf("\nDeleted node: %d", tmp->data);
        prev->next = NULL;
        free(tmp);
    }
    return h;
}

// Function to remove the first node
struct node *removefirst(struct node *h)
{
    struct node *tmp;
    if(h == NULL)
    {
        printf("\nList is empty. Nothing to remove.");
        return h;
    }
    tmp = h;
    h = h->next;
    printf("\nDeleted node: %d", tmp->data);
    free(tmp);
    return h;
}

// Function to remove the node present after the given key
struct node *removeAfter(struct node *h, int key)
{
    struct node *tmp, *p;
    if(h == NULL)
    {
        printf("\nList is empty.");
        return h;
    }

    tmp = h;
    while(tmp != NULL && tmp->data != key)
        tmp = tmp->next;

    if(tmp == NULL)
        printf("\nKey not found in list.");
    else if(tmp->next == NULL)
        printf("\nNo node exists after the given key.");
    else
    {
        p = tmp->next;
        printf("\nDeleted node: %d", p->data);
        tmp->next = p->next;
        free(p);
    }
    return h;
}

// Function to display the given list
void display(struct node *h)
{
    struct node *tmp;
    tmp = h;

    if(h == NULL)
        printf("\nLinked List is Empty.");
    else
    {
        printf("\n\nLinked List Contents:\n");
        while(tmp != NULL)
        {
            printf("Data: %d\tAddress: %p -> %p\n", tmp->data, tmp, tmp->next);
            tmp = tmp->next;
        }
    }
}

// Main function
int main()
{
    struct node *head = NULL;
    int ch, d, k;

    while(1)
    {
        printf("\n\n\t\tMENU");
        printf("\n1. Insert at End\n2. Insert After\n3. Remove Last\n4. Remove After\n5. Display\n6. Insert at Start\n7. Remove First\n8. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("\nEnter data to insert at end: ");
                scanf("%d", &d);
                head = insertAtEnd(head, d);
                break;

            case 2:
                printf("\nEnter key after which to insert: ");
                scanf("%d", &k);
                printf("Enter data to insert: ");
                scanf("%d", &d);
                head = insertAfter(head, k, d);
                break;

            case 3:
                head = removelast(head);
                break;

            case 4:
                printf("\nEnter key after which to remove: ");
                scanf("%d", &k);
                head = removeAfter(head, k);
                break;

            case 5:
                display(head);
                break;

            case 6:
                printf("\nEnter data to insert at start: ");
                scanf("%d", &d);
                head = insertAtStart(head, d);
                break;

            case 7:
                head = removefirst(head);
                break;

            case 8:
                printf("\nExiting...");
                exit(0);
                break;

            default:
                printf("\nInvalid choice! Try again.");
        }
    }
    return 0;
}

/*
Conclusion:
From this experiment, we learned how to:
1) Implement a singly linked list using dynamic memory allocation.
2) Perform insertion and deletion operations efficiently.
3) Understand how nodes are connected using pointers.
4) Handle different cases like empty list, insertion at start or end, and deletion after a given key.
Singly linked lists form the foundation for advanced data structures like stacks, queues, and graphs.
This program helped us clearly understand the concept of dynamic data structures and pointer manipulation in C.
*/
