/* Implement Queue using array.
Theory:
A Queue is a linear data structure that follows the FIFO (First In First Out) principle.
This means the element inserted first will be the first one to be removed.

In C, a queue can be implemented using:
-Arrays
-Structures
-or Linked Lists
## Queue Operations:
Initialize:
isEmpty():
isFull():
Enqueue():
Dequeue():
Display():
These operations help in efficiently managing data using the FIFO rule.
Queues are widely used in process scheduling, buffering, and resource management.
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 5		// defining the size of queue

struct queue		// structure for queue
{
	int data[MAX];
	int front, rear;
};

// function to initialize the queue
void initialize(struct queue *q)
{
	q->front = -1;
	q->rear = -1;
}

// function to check whether the queue is empty
int isEmpty(struct queue *q)
{
	if(q->front == -1 || q->front > q->rear)
		return 1;
	else
		return 0;
}

// function to check whether the queue is full
int isFull(struct queue *q)
{
	return (q->rear == MAX - 1) ? 1 : 0;
}

// function to insert element into queue
int enqueue(struct queue *q, int d)
{
	if(isFull(q))
		return 0;		// Queue is full
	else
	{
		if(q->front == -1)
			q->front = 0;	// First insertion
		q->rear++;
		q->data[q->rear] = d;
		return 1;		// Successfully inserted
	}
}

// function to delete element from queue
void dequeue(struct queue *q)
{
	if(isEmpty(q))
		printf("\n\tQueue Underflows ->");
	else
	{
		printf("\nDequeued element is : %d", q->data[q->front]);
		q->front++;
	}
}

// function to display the queue
void display(struct queue *q)
{
	int i;
	if(isEmpty(q))
		printf("\n\tQueue is Empty ->");
	else
	{
		printf("\nQueue Contents ->->\n");
		for(i = q->front; i <= q->rear; i++)
		{
			printf("%d\n", q->data[i]);
		}
	}
}

// the main function
int main()
{
	int ch, d;
	struct queue q;		// queue variable
	initialize(&q);		// initializing queue

	while(1)
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
				printf("\n\tPlease enter correct choice ->->->->");
		}
	}
}

/*
Conclusion:
From this program, we learned how to:
Implement a Queue using arrays and structures in C.
Perform basic Queue operations such as Enqueue, Dequeue, and Display.
Handle overflow and underflow conditions safely.
Understand the working principle of FIFO (First In First Out) order.
This experiment helps in understanding how Queues manage data dynamically and how they are used in various applications 
like process scheduling, printer management, buffering, and inter-process communication.
*/
