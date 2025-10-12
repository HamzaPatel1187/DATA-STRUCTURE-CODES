/* Implement a menu-driven program for array
operations: creation, display, insertion at a given
position, deletion from a given position, searching
(linear and binary search).
Theory:
An array is a collection of elements of the same data type stored in contiguous memory locations.
It allows easy access to elements using an index number.
In this program, we perform basic operations on arrays using a
menu-driven approach
#Concept Used:
Array indexing
Looping (for loop)
Conditional statements (if-else)
Functions and parameter passing
Menu-driven control using switch-case
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Create array
int createArray(int arr[])
{
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n > MAX)
    {
        printf("Array size exceeds maximum limit!\n");
        return 0;
    }

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Array created successfully!\n");
    return n;
}

// Display array
void displayArray(int arr[], int n)
{
    int i;
    if (n == 0)
    {
        printf("Array is empty!\n");
        return;
    }

    printf("Array elements: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Insert element
int insertAtPosition(int arr[], int n)
{
    int pos, val, i;

    if (n == MAX)
    {
        printf("Array is full!\n");
        return n;
    }

    printf("Enter position (1 to %d): ", n + 1);
    scanf("%d", &pos);

    if (pos < 1 || pos > n + 1)
    {
        printf("Invalid position!\n");
        return n;
    }

    printf("Enter value to insert: ");
    scanf("%d", &val);

    for (i = n; i >= pos; i--)
        arr[i] = arr[i - 1];

    arr[pos - 1] = val;
    n++;

    printf("Element inserted successfully!\n");
    return n;
}

// Delete element
int deleteFromPosition(int arr[], int n)
{
    int pos, i;

    if (n == 0)
    {
        printf("Array is empty!\n");
        return n;
    }

    printf("Enter position to delete (1 to %d): ", n);
    scanf("%d", &pos);

    if (pos < 1 || pos > n)
    {
        printf("Invalid position!\n");
        return n;
    }

    printf("Deleted element: %d\n", arr[pos - 1]);

    for (i = pos - 1; i < n - 1; i++)
        arr[i] = arr[i + 1];

    n--;

    printf("Deletion successful!\n");
    return n;
}

// Linear search
void linearSearch(int arr[], int n)
{
    int key, i, found = 0;

    if (n == 0)
    {
        printf("Array is empty!\n");
        return;
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            printf("Element %d found at position %d.\n", key, i + 1);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Element not found in array.\n");
}

// Binary search
void binarySearch(int arr[], int n)
{
    int key, low = 0, high = n - 1, mid, found = 0;

    if (n == 0)
    {
        printf("Array is empty!\n");
        return;
    }

    printf("Enter element to search (array must be sorted): ");
    scanf("%d", &key);

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == key)
        {
            printf("Element %d found at position %d.\n", key, mid + 1);
            found = 1;
            break;
        }
        else if (key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    if (!found)
        printf("Element not found.\n");
}

// Main program
int main()
{
    int arr[MAX];
    int n = 0, choice;

    while (1)
    {
        printf("\n\n----- MENU -----\n");
        printf("1. Create Array\n");
        printf("2. Display Array\n");
        printf("3. Insert Element at Given Position\n");
        printf("4. Delete Element from Given Position\n");
        printf("5. Linear Search\n");
        printf("6. Binary Search (Array must be sorted)\n");
        printf("7. Exit\n");
        printf("----------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: n = createArray(arr); break;
            case 2: displayArray(arr, n); break;
            case 3: n = insertAtPosition(arr, n); break;
            case 4: n = deleteFromPosition(arr, n); break;
            case 5: linearSearch(arr, n); break;
            case 6: binarySearch(arr, n); break;
            case 7: printf("Exiting program.\n"); exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

/*
conclusion: 
From this program, we learned how to:
Create and manage an array dynamically using user input.
Perform insertion, deletion, and display operations efficiently.
Implement linear search and binary search to find elements in an array.
Use a menu-driven approach to make programs user-friendly and interactive.
This experiment helps understand array manipulation, searching techniques,
 and function-based modular programming in C.
*/