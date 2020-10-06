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

int Tree_Height(node * root)
{
        if (root == NULL)
        {
            return 0;
        }
        int Lst = Tree_Height(root->left);
        //cout<<Lst<<endl;
        int Rst = Tree_Height(root->right);
        cout<<Rst<<endl;
        return max(Lst, Rst) + 1;
}

int main(){
    //8 10 1 - 1 - 1 6 9 - 1 - 1 7 - 1 - 1 3 - 1 14 13 - 1 - 1 - 1
    node *root = buildTree();
    cout<<Tree_Height(root);

    return 0;
}