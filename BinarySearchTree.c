/*	Implementation of Binary Search Tree
*/

#include<stdio.h>
#include<stdlib.h>

// Structure for Binary Search Tree Node
struct bstree
{
    int data;
    struct bstree *left, *right;
};

// Recursive function to insert a node
struct bstree *insert(struct bstree *root, int d)
{
    if(root == NULL)
    {
        struct bstree *p = (struct bstree *)malloc(sizeof(struct bstree));
        if(p == NULL)
        {
            printf("\nNot enough memory.");
            return root;
        }
        p->data = d;
        p->left = p->right = NULL;
        root = p;
    }
    else
    {
        if(d < root->data)
            root->left = insert(root->left, d);
        else if(d > root->data)
            root->right = insert(root->right, d);
        else
            printf("\nDuplicate value not allowed in BST!");
    }
    return root;
}

// Iterative insertion (optional function)
struct bstree *insertIter(struct bstree *root, int d)
{
    struct bstree *p, *curr, *prev;
    p = (struct bstree *)malloc(sizeof(struct bstree));
    p->data = d;
    p->left = p->right = NULL;

    if(root == NULL)
        return p;

    curr = prev = root;
    while(curr != NULL)
    {
        prev = curr;
        if(d < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }
    if(d < prev->data)
        prev->left = p;
    else
        prev->right = p;

    return root;
}

// Inorder Traversal (Left-Root-Right)
void inorder(struct bstree *r)
{
    if(r != NULL)
    {
        inorder(r->left);
        printf("\t%d", r->data);
        inorder(r->right);
    }
}

// Preorder Traversal (Root-Left-Right)
void preorder(struct bstree *r)
{
    if(r != NULL)
    {
        printf("\t%d", r->data);
        preorder(r->left);
        preorder(r->right);
    }
}

// Postorder Traversal (Left-Right-Root)
void postorder(struct bstree *r)
{
    if(r != NULL)
    {
        postorder(r->left);
        postorder(r->right);
        printf("\t%d", r->data);
    }
}

// Search a node with given key
struct bstree *search(struct bstree *root, int key)
{
    if(root == NULL || root->data == key)
        return root;
    else if(key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Helper function: find minimum node
struct bstree *minValueNode(struct bstree *node)
{
    struct bstree *current = node;
    while(current && current->left != NULL)
        current = current->left;
    return current;
}

// Delete a node with given key
struct bstree *delete(struct bstree *root, int k)
{
    if(root == NULL)
    {
        printf("\nNode with key %d not found.", k);
        return root;
    }

    if(k < root->data)
        root->left = delete(root->left, k);
    else if(k > root->data)
        root->right = delete(root->right, k);
    else
    {
        // Node found
        if(root->left == NULL)
        {
            struct bstree *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            struct bstree *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        struct bstree *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

// Main function
int main()
{
    int ch, d;
    struct bstree *p, *root = NULL;

    while(1)
    {
        printf("\n\n\t\t\tMENU");
        printf("\n1. Insert.");
        printf("\n2. Inorder Traversal.");
        printf("\n3. Preorder Traversal.");
        printf("\n4. Postorder Traversal.");
        printf("\n5. Search.");
        printf("\n6. Delete.");
        printf("\n7. Exit.");
        printf("\nEnter your choice :: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("\nEnter data :: ");
                scanf("%d", &d);
                root = insert(root, d);
                break;

            case 2:
                printf("\n\tInorder Traversal:");
                inorder(root);
                break;

            case 3:
                printf("\n\tPreorder Traversal:");
                preorder(root);
                break;

            case 4:
                printf("\n\tPostorder Traversal:");
                postorder(root);
                break;

            case 5:
                printf("\nEnter key to search :: ");
                scanf("%d", &d);
                p = search(root, d);
                if(p != NULL)
                    printf("\nNode with value %d found in BST.", d);
                else
                    printf("\nNode with value %d not found in BST.", d);
                break;

            case 6:
                printf("\nEnter data to delete :: ");
                scanf("%d", &d);
                root = delete(root, d);
                break;

            case 7:
                exit(0);
                break;

            default:
                printf("\nPlease enter correct choice....");
        }
    }
    return 0;
}

/*
Conclusion:
From this experiment, we learned:
1) How to implement a Binary Search Tree (BST) in C using dynamic memory.
2) How to insert nodes while maintaining BST properties.
3) How to perform tree traversals (Inorder, Preorder, Postorder).
4) How to search and delete nodes using recursion.
5) The difference between Binary Tree and Binary Search Tree.

This experiment helps in understanding hierarchical data structures
and forms the foundation for learning advanced trees such as AVL Tree,
B-Trees, and Red-Black Trees.
*/
    