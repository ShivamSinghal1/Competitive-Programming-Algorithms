//1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 -1
//Top view

#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    int hd;
    node*left;
    node*right;
    public:
    node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
        hd=INT_MAX;
    }
};
node*buildtree()
{
    int d;
    cin>>d;
    if(d==-1)
    {
        return NULL;
    }
    node*root=new node(d);
    root->left=buildtree();
    root->right=buildtree();
    return root;
}
void topview(node*root)
{
    if(root==NULL)
        return;
    
    queue<node*>q;
    map<int ,int> m;
    int hd=0;
    root->hd=hd;
    q.push(root);
    while(q.size())
    {
        hd=root->hd;
        if(m.count(hd)==0)// count function returns 1 if the container
        // contains an element whose key is equivalent
        // to hd, or returns zero otherwise.
        {
            m[hd]=root->data;
        }
        if(root->left)
        {
            root->left->hd=hd-1;
            q.push(root->left);
        }
         if(root->right)
        {
            root->right->hd=hd+1;
            q.push(root->right);
        }
        q.pop();
        root=q.front();


    }
     for(auto i=m.begin();i!=m.end();i++)
    {
        cout<<i->second<<" ";
    }
}
int main() {
    node*root=buildtree();
	topview(root);

	return 0;
}
