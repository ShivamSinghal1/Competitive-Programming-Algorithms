#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
#include <climits>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newnode(int data)
{
    struct node *p = new (struct node);
    //struct node* p = (struct node*)malloc(sizeof(struct node));

    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}

//Inorder (Left, Root, Right)
//Preorder (Root, Left, Right)
//Postorder (Left, Right, Root)
//Levelorder
int height(node *root)
{
    // Write your code here.
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 0;
    }
    return std::max(height(root->left) + 1, height(root->right) + 1);
}

int printlevel(struct node *root, int level)
{
    if (root == NULL)
        return 0;
    if (level == 0)
        cout << root->data << " ";
    else
    {
        printlevel(root->left, level - 1);
        printlevel(root->right, level - 1);
    }
}

void levelOrder(struct node *root)

{
    int h = height(root);
    for (int i = 0; i <= h; i++)
    {
        printlevel(root, i);
    }
}

int preorder(struct node *root)
{
    if (root == NULL)
        return 0;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int inorder(struct node *root)
{
    if (root == NULL)
        return 0;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int postorder(struct node *root)
{
    if (root == NULL)
        return 0;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    struct node *root = newnode(3);
    root->left = newnode(7);
    root->right = newnode(5);
    root->right->right = newnode(11);
    root->left->left = newnode(9);

    printf("\nTree traversed in preorder=\n");
    preorder(root);
    printf("\nTree traversed in inorder=\n");
    inorder(root);
    printf("\nTree traversed in postorder=\n");
    postorder(root);
    printf("\nTree traversed in levelorder=\n");
    levelOrder(root);

    return 0;
}
