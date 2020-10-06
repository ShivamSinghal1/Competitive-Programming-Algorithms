#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        right = NULL;
        left = NULL;
    }
};

node *buildTree()
{
    int d;
    cin >> d;

    if (d == -1)
    {
        return NULL;
    }

    node *root = new node(d);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

int Tree_Height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int Lst = Tree_Height(root->left);
    int Rst = Tree_Height(root->right);
    return max(Lst, Rst) + 1;
}

int diameter(node *root)
{ //O(n*n)
    if (root == NULL)
    {
        return 0;
    }
    int h1 = Tree_Height(root->left);
    int h2 = Tree_Height(root->right);
    int op1 = h1 + h2;
    int op2 = diameter(root->left);
    int op3 = diameter(root->right);

    return max(op1, max(op2, op3));
}
int main()
{

    node *root = buildTree();
    cout<<diameter(root);

    return 0;
}