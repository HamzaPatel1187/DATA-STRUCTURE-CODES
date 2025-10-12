/*	Implementation of Binary Tree
Traversals:
1) Inorder (Left-Root-Right): Produces nodes in ascending order for BST.
2) Preorder (Root-Left-Right): Useful for creating a copy of the tree.
3) Postorder (Left-Right-Root): Useful for deleting or freeing nodes.
*/

#include<stdio.h>
#include<stdlib.h>

struct btree
{
    int data;
    struct btree *left,*right;
};

// Function to insert a node in binary tree (simple binary tree, not BST)
struct btree *insert(struct btree *root,int d)
{
    struct btree *p;
    if(root==NULL)
    {
        p=(struct btree *)malloc(sizeof(struct btree));
        if(p==NULL)
        {
            printf("\nNot enough memory.");
            return root;
        }
        p->data=d;
        p->left=p->right=NULL;
        root=p;
    }
    else
    {
        if(root->left==NULL)
            root->left=insert(root->left,d);
        else
            root->right=insert(root->right,d);
    }
    return root;
}

// Inorder traversal (Left-Root-Right)
void inorder(struct btree *r)
{
    if(r!=NULL)
    {
        inorder(r->left);
        printf("\t%d",r->data);
        inorder(r->right);
    }
}

// Preorder traversal (Root-Left-Right)
void preorder(struct btree *r)
{
    if(r!=NULL)
    {
        printf("\t%d",r->data);
        preorder(r->left);
        preorder(r->right);
    }
}

// Postorder traversal (Left-Right-Root)
void postorder(struct btree *r)
{
    if(r!=NULL)
    {
        postorder(r->left);
        postorder(r->right);
        printf("\t%d",r->data);
    }
}

// Search a node with given key
struct btree *search(struct btree *root,int key)
{
    if(root==NULL)
        return NULL;
    if(root->data==key)
        return root;
    struct btree *p;
    p=search(root->left,key);
    if(p!=NULL)
        return p;
    return search(root->right,key);
}

// Helper function to find the inorder successor for deletion
struct btree* minValueNode(struct btree* node)
{
    struct btree* current = node;
    while(current && current->left != NULL)
        current = current->left;
    return current;
}

// Delete a node with given key in BST-like structure
struct btree *delete(struct btree *root, int key)
{
    if(root==NULL)
    {
        printf("\nNode with key %d not found.", key);
        return root;
    }

    if(key < root->data)
        root->left = delete(root->left,key);
    else if(key > root->data)
        root->right = delete(root->right,key);
    else
    {
        // Node with only one child or no child
        if(root->left==NULL)
        {
            struct btree* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            struct btree* temp=root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get inorder successor
        struct btree* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = delete(root->right,temp->data);
    }
    return root;
}

// Main function
int main()
{
    int ch,d;
    struct btree *root=NULL;
    struct btree *p;

    while(1)
    {
        printf("\n\n\t\t\tMENU");
        printf("\n1. Insert.\n2. Inorder.\n3. Preorder.\n4. Postorder.\n5. Search.\n6. Delete.\n7. Exit.");
        printf("\n\tEnter your choice :: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("\nEnter data :: ");
                scanf("%d",&d);
                root=insert(root,d);
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
                printf("\nEnter data to search :: ");
                scanf("%d",&d);
                p=search(root,d);
                if(p!=NULL)
                    printf("\nNode with value %d exists.", d);
                else
                    printf("\nNode with value %d does not exist.", d);
                break;

            case 6:
                printf("\nEnter data to delete :: ");
                scanf("%d",&d);
                root=delete(root,d);
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
From this program, we learned:
1) How to implement a binary tree in C using dynamic memory allocation.
2) How to insert nodes and perform traversals (Inorder, Preorder, Postorder).
3) How to search for a node with a given key.
4) How to delete a node from the binary tree while maintaining tree structure.
5) How recursive functions simplify tree operations.

This experiment helps in understanding hierarchical data structures and is foundational for learning
Binary Search Trees (BSTs), Heaps, and advanced tree-based algorithms.
*/
