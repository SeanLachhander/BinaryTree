#include "header.h"

void inOrderTraversal(struct node *root) // function will perform the inOrderTraversal traversal of the BST
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d \n", root->key);
        inOrderTraversal(root->right);
    }
}
