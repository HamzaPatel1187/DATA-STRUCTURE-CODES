/*	Implementation of Depth First Search (DFS)
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 20

// Stack structure
struct stack
{
    int data[MAX];
    int top;
};

// Push function
void push(struct stack *s, int d)
{
    if(s->top == MAX - 1)
        printf("\n\tStack Overflow ->");
    else
    {
        s->top++;
        s->data[s->top] = d;
    }
}

// Pop function
int pop(struct stack *s)
{
    int d;
    if(s->top == -1)
    {
        printf("\n\tStack Underflow ->");
        return -1;
    }
    else
    {
        d = s->data[s->top];
        s->top--;
        return d;
    }
}

// Initialize stack
void initialize(struct stack *s)
{
    s->top = -1;
}

/* Function for Depth First Search (DFS)
   It accepts the adjacency matrix (Graph), number of vertices, and starting vertex.
   It follows the DFS algorithm using a stack.
*/
void dfs(int a[][10], int n, int start)
{
    struct stack s;
    int ready[10];
    int i, j, visited;

    initialize(&s); // initialize stack

    // Mark all vertices as unvisited (1 = ready)
    for(i = 0; i < n; i++)
        ready[i] = 1;

    // Push start vertex
    push(&s, start - 1);
    printf("\n\tDFS sequence with starting vertex as %d:\n", start);

    while(s.top != -1)
    {
        visited = pop(&s);        // pop vertex
        printf("\t%d", visited + 1);  // print vertex
        ready[visited] = 0;       // mark visited

        // Push all adjacent unvisited vertices
        for(j = n - 1; j >= 0; j--)   // reverse order for correct sequence
        {
            if(a[visited][j] == 1 && ready[j] == 1)
            {
                push(&s, j);
                ready[j] = 0;
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
        printf("\n2. DFS Traversal.");
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
                dfs(a, n, start);
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
2) How to traverse a graph using Depth First Search (DFS).
3) How a stack (LIFO) data structure helps in DFS traversal.
4) How DFS explores paths deeply before backtracking.
5) How to visit all reachable vertices from a given starting point.

This experiment provides a clear understanding of DFS, which forms the foundation for 
advanced algorithms like backtracking, topological sorting, and connected component detection.
*/
