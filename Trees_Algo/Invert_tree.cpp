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

void BFS_2(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);


    while (!q.empty())
    {

        node *f = q.front();

        if(f == NULL){

           cout<<endl;
           q.pop();
           if(!q.empty()){
              q.push(NULL);

           }

        }
        else{
            cout << f->data << " ";
            q.pop();

            if (f->left)
            {
                q.push(f->left);
            }
            if (f->right)
            {
                q.push(f->right);
            }
        }
        
    }
    return;
}
 node *InvertTree(node *root){
         if(root == NULL) return root;

         node *left = InvertTree(root->left);
         node *right = InvertTree(root->right);

         //Swap
         root->right = left;
         root->left = right;

         return root;
     }

int main()
{
    
    node *root = buildTree(); //4 2 1 -1 -1 3 -1 -1 7 6 -1 -1 9 -1 -1
    BFS_2(root);
    cout<<endl;

   InvertTree(root);
   BFS_2(root);

    

    return 0;
}