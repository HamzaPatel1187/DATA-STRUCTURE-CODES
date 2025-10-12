/* Implement Circular Queue using array.
 Theory:
A Circular Queue is an advanced form of a simple Queue that connects the end 
of the queue back to the front, forming a circle.
It follows the FIFO (First In First Out) principle but efficiently uses memory 
by reusing the empty space created when elements are dequeued.

This type of queue is efficient because it avoids memory wastage of a simple queue.
Circular queues are commonly used in buffering, CPU scheduling, and traffic management.
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 5        // defining the size of circular queue

struct cqueue        // structure for circular queue
{
    int data[MAX];
    int front, rear;
};

// function to initialize the circular queue
void initialize(struct cqueue *q)
{
    q->front = -1;
    q->rear = -1;
}

// function to check whether the circular queue is empty
int isEmpty(struct cqueue *q)
{
    return (q->front == -1);
}

// function to check whether the circular queue is full
int isFull(struct cqueue *q)
{
    return ((q->rear + 1) % MAX == q->front);
}

// function to insert element into circular queue
int enqueue(struct cqueue *q, int d)
{
    if(isFull(q))
        return 0;        // queue is full
    else
    {
        if(q->front == -1)
            q->front = 0;    // first insertion
        q->rear = (q->rear + 1) % MAX;
        q->data[q->rear] = d;
        return 1;        // successful insertion
    }
}

// function to delete element from circular queue
void dequeue(struct cqueue *q)
{
    if(isEmpty(q))
        printf("\n\tQueue Underflows->");
    else
    {
        printf("\nDequeued element is : %d", q->data[q->front]);
        if(q->front == q->rear)
        {
            q->front = -1;
            q->rear = -1;    // queue becomes empty
        }
        else
            q->front = (q->front + 1) % MAX;
    }
}

// function to display circular queue
void display(struct cqueue *q)
{
    int i;
    if(isEmpty(q))
        printf("\n\tQueue is Empty->");
    else
    {
        printf("\nCircular Queue Contents ->->\n");
        i = q->front;
        while(1)
        {
            printf("%d\n", q->data[i]);
            if(i == q->rear)
                break;
            i = (i + 1) % MAX;
        }
    }
}

// the main function
int main()
{
    int ch, d;
    struct cqueue q;        // circular queue variable
    initialize(&q);        // initialize the circular queue

    while(1)        // indefinite loop to show options
    {
        printf("\n\t\t\tMENU\n1. Enqueue.\n2. Dequeue.\n3. Display.\n4. Exit.");
        printf("\n\tEnter your choice :: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("\nEnter Data to be Enqueued : ");
                scanf("%d", &d);
                if(enqueue(&q, d))
                    printf("\nEnqueued successfully");
                else
                    printf("\nCannot Enqueue.. Queue is Full!");
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                exit(0);
            default:
                printf("\n\tPlease enter correct choice->->->->");
        }
    }
}

/*
Conclusion:
From this program, we learned how to:
Implement a Circular Queue using arrays and structures in C.
Perform basic operations such as Enqueue, Dequeue, and Display.
Handle overflow and underflow conditions safely.
Understand the working principle of circular connection in a queue.
This experiment helps in understanding how Circular Queues efficiently utilize memory
and are used in applications such as buffering, round-robin scheduling, and resource management.
*/
