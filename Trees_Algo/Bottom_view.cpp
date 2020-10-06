#include<iostream>
#include<queue>
using namespace std;
int max1=0,min1=0;
class node{
public:
    int data;
    node *left;
    node*right;

    node(int d)
    {
        data = d;
        right = NULL;
        left = NULL;
    }
};
void traverse(node* root,node* pos[],node* neg[],int k)
{
  if(root==NULL)
    return;
  
  if(max1<k)
    max1=k;
  if(min1>k)
    min1=k;
    //Value at each level is overwritten if a new value comes at that level
     if(k>=0)
  {
    pos[k]=root;
  }
  else
  {
    neg[k*(-1)] = root;
  }
  traverse(root->left,pos,neg,k-1);
  traverse(root->right,pos,neg,k+1);
 
}
int main() {
    int d;
    node* pos[10000];
    node* neg[10000];
    cin>>d;
    node*root = new node(d);
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        node*f = q.front();
        q.pop();
        int c1,c2;
        cin>>c1>>c2;
        if(c1!=-1)
        {
            f->left = new node(c1);
            q.push(f->left);
        }
        if(c2!=-1)
        {
            f->right = new node(c2);
            q.push(f->right);
        }
    }
    traverse(root,pos,neg,0);
    for(int i=(min1*(-1));i>=1;i--)
      cout<<neg[i]->data<<" ";
    for(int i=0;i<=max1;i++)
      cout<<pos[i]->data<<" ";
	return 0;
}