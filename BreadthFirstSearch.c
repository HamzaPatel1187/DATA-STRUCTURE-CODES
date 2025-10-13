/*	Implementation of Breadth First Search (BFS)
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 20

// Structure for Queue
struct Queue
{
    int data[MAX];
    int front, rear;
};

// Initialize Queue
void initializeQ(struct Queue *q)
{
    q->front = q->rear = -1;
}

// Insert element into Queue
void insert(struct Queue *q, int d)
{
    if(q->rear == MAX - 1)
        printf("\n\tQueue is Full ->");
    else
    {
        if(q->front == -1)
            q->front = 0;
        q->rear++;
        q->data[q->rear] = d;
    }
}

// Delete element from Queue
int delete(struct Queue *q)
{
    int d;
    if(q->rear == -1)
    {
        printf("\nQueue is empty..");
        return -1;
    }
    else
    {
        d = q->data[q->front];
        q->front++;
        if(q->front > q->rear)
            q->front = q->rear = -1;
        return d;
    }
}

/* Function for Breadth First Search.
   It accepts the adjacency matrix (Graph), number of vertices, and starting vertex.
   It follows the BFS algorithm to visit all reachable vertices from the starting node.
*/
void bfs(int a[][10], int n, int start)
{
    struct Queue q;
    int ready[10];
    int i, j, v;

    initializeQ(&q);

    // Mark all vertices as unvisited
    for(i = 0; i < n; i++)
        ready[i] = 0;

    // Visit start vertex
    insert(&q, start);
    ready[start] = 1;

    printf("\nBFS Traversal: ");

    while(q.front != -1)
    {
        v = delete(&q);
        printf("%d ", v + 1);

        for(i = 0; i < n; i++)
        {
            if(a[v][i] == 1 && ready[i] == 0)
            {
                insert(&q, i);
                ready[i] = 1;
            }
        }
    }
}

// Main function
int main()
{
    int n, i, j, ch, start;
    int a[10][10] = {
        {0,1,0,1,1},
        {1,0,1,0,0},
        {0,1,0,0,0},
        {1,0,0,0,1},
        {1,0,0,1,0},
    };
    n = 5;

    while(1)
    {
        printf("\n\n\t\t\tMENU");
        printf("\n1. Make Graph.");
        printf("\n2. BFS Traversal.");
        printf("\n3. Exit.");
        printf("\n\tEnter Your Choice :: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("\nENTER THE NUMBER OF VERTICES :: ");
                scanf("%d", &n);
                for(i = 0; i < n; i++)
                {
                    for(j = 0; j < n; j++)
                    {
                        printf("Enter 1 if %d has Edge with %d else 0 : ", i + 1, j + 1);
                        scanf("%d", &a[i][j]);
                    }
                }
                printf("\n\nTHE ADJACENCY MATRIX IS:\n");
                for(i = 0; i < n; i++)
                {
                    for(j = 0; j < n; j++)
                        printf("\t%d", a[i][j]);
                    printf("\n");
                }
                break;

            case 2:
                printf("\nEnter the start vertex between 1 to %d: ", n);
                scanf("%d", &start);
                bfs(a, n, start - 1);
                break;

            case 3:
                exit(0);
                break;

            default:
                printf("\nPlease enter correct choice...");
        }
    }
    return 0;
}

/*
Conclusion:
From this experiment, we learned:
1) How to represent a graph using an adjacency matrix.
2) How to traverse a graph using Breadth First Search (BFS).
3) How the Queue data structure (FIFO) helps in BFS traversal.
4) How to visit all reachable vertices from a given starting vertex.
5) The BFS algorithm ensures the shortest path (in terms of edges) is found in unweighted graphs.

This experiment builds a strong understanding of graph traversal techniques,
which are fundamental for network algorithms, AI pathfinding, and real-world applications.
*/
    