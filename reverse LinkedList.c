/*	Implementation of Singly Linked List with Reverse and Remove Operations

Singly linked lists are widely used in dynamic memory management, stacks, queues, and other data structures where flexible memory allocation is required.
*/

#include<stdio.h>
#include<stdlib.h>

// Node structure
struct ListNode {
    int val;
    struct ListNode *next;
};

// Reverse list
struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode *prev=NULL, *curr=head, *next=NULL;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
    return head;
}

// Insert node at end
struct ListNode *insertAtEnd(struct ListNode *h,int d)
{
    struct ListNode *p,*tmp;
    p=(struct ListNode *)malloc(sizeof(struct ListNode));
    if(p==NULL)
    {
        printf("\nNot enough memory to allocate.");
        return h;
    }
    p->val=d;
    p->next=NULL;

    if(h==NULL)
        h=p;
    else
    {
        tmp=h;
        while(tmp->next!=NULL)
            tmp=tmp->next;
        tmp->next=p;
    }
    return h;
}

// Remove last node
struct ListNode *removeLast(struct ListNode *h)
{
    if(h==NULL)
    {
        printf("\nList is empty.");
        return h;
    }
    if(h->next==NULL)
    {
        free(h);
        return NULL;
    }
    struct ListNode *tmp=h;
    while(tmp->next->next!=NULL)
        tmp=tmp->next;
    free(tmp->next);
    tmp->next=NULL;
    return h;
}

// Remove first node
struct ListNode *removeFirst(struct ListNode *h)
{
    if(h==NULL)
    {
        printf("\nList is empty.");
        return h;
    }
    struct ListNode *tmp=h;
    h=h->next;
    free(tmp);
    return h;
}

// Remove node after given key
struct ListNode *removeAfter(struct ListNode *h,int key)
{
    if(h==NULL)
    {
        printf("\nList is empty.");
        return h;
    }
    struct ListNode *tmp=h;
    while(tmp!=NULL && tmp->val!=key)
        tmp=tmp->next;
    if(tmp==NULL)
    {
        printf("\nKey %d not found.", key);
        return h;
    }
    if(tmp->next==NULL)
    {
        printf("\nNo node exists after key %d.", key);
        return h;
    }
    struct ListNode *del=tmp->next;
    tmp->next=del->next;
    free(del);
    return h;
}


// Display list
void display(struct ListNode *h)
{
    struct ListNode *tmp=h;
    if(h!=NULL)
    {
        int n=0;
        printf("\n\n\tLinked List Contents with head pointing to %p..\n",h);
        while(tmp!=NULL)
        {
            printf("\t%p\t%d | %p\n",tmp,tmp->val,tmp->next);
            tmp=tmp->next;
            n++;
        }
        printf("\n\tSize of List: %d bytes.\n",n*sizeof(struct ListNode));
    }
    else
    {
        printf("\nLL is empty.");
    }
}

// Main function
int main()
{
    struct ListNode *head=NULL;
    int ch,d;

    while(1)
    {
        printf("\n\n\n\t\t\tMENU");
        printf("\n1. Insert at End.\n2. Reverse List.\n3. Remove First.\n4. Remove Last.\n5. Remove After Key.\n6. Display.\n7. Exit.");
        printf("\n\tEnter Your Choice :: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("\n\tEnter Data : ");
                scanf("%d",&d);
                head=insertAtEnd(head,d);
                break;

            case 2:
                head=reverseList(head);
                printf("\n\tList reversed successfully.");
                break;

            case 3:
                head=removeFirst(head);
                printf("\n\tFirst node removed successfully.");
                break;

            case 4:
                head=removeLast(head);
                printf("\n\tLast node removed successfully.");
                break;

            case 5:
                printf("\n\tEnter Key : ");
                scanf("%d",&d);
                head=removeAfter(head,d);
                break;

            case 6:
                display(head);
                break;

            case 7:
                return 0;

            default:
                printf("\n\t\tPlease enter correct choice....");
        }
    }
    return 0;
}

/*
Conclusion:
From this program, we learned:
1) How to implement a singly linked list in C using dynamic memory allocation.
2) How to insert nodes at the end of the list.
3) How to remove nodes from the beginning, end, or after a given key.
4) How to reverse the list using pointer manipulation.
5) How to traverse and display the list along with memory addresses.

This experiment provides hands-on understanding of linked list operations, dynamic memory management, and pointer handling.  
Singly linked lists are widely used in implementing dynamic data structures such as stacks, queues, and adjacency lists in graphs.
*/
