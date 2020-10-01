#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;
    node(){
        left=right=NULL;
    }
};
node* levelorderinput(){
    node *root=new node;
    int d;cin>>d;
    root->data=d;
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        node* f=q.front();
        q.pop();
        int c1,c2;
        cin>>c1>>c2;
        if(c1!=-1){
            f->left=new node;
            f->left->data=c1;
            q.push(f->left);
        }
        if(c2!=-1){
            f->right=new node;
            f->right->data=c2;
            q.push(f->right);
        }
    }
    return root;
}
void printlevelorder(node *root){
    if(root==NULL){
        cout<<"\n";
        return;
    }
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* f=q.front();
        q.pop();
        if(f!=NULL){
            cout<<f->data<<" ";
            if(f->left)
            q.push(f->left);
            if(f->right)
            q.push(f->right);
        }
        else{
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
    }
}
class custom{
public:
    bool haskey1;
    bool haskey2;
    node* lca;
    custom(){
        haskey1=haskey2=false;
        lca=NULL;
    }
};
custom* helper(node* root,int p,int q){
    if(root==NULL){
        return NULL;
    }
    custom* leftans=helper(root->left,p,q);
    if(leftans!=NULL and leftans->lca!=NULL){
        return leftans;
    }
    custom* rightans=helper(root->right,p,q);
    if(rightans!=NULL and rightans->lca!=NULL){
        return rightans;
    }
    custom* result=new custom;
    if(leftans!=NULL and rightans!=NULL){
        result->haskey1=true;
        result->haskey2=true;
        result->lca=root;
        return result;
    }
    else if(root->data==p){
        result->haskey1=true;
        result->haskey2=(leftans?leftans->haskey2:false or rightans?rightans->haskey2:false);
        if(result->haskey2){
            result->lca=root;
        }
        return result;
    }
    else if(root->data==q){
        result->haskey2=true;
        result->haskey1=(leftans?leftans->haskey1:false or rightans?rightans->haskey1:false);
        if(result->haskey1){
            result->lca=root;
        }
        return result;
    }
    else if(leftans){
        return leftans;
    }
    else if(rightans){
        return rightans;
    }
    return NULL;
}
node* LCA(node* root,int p,int q){
    custom* ans=helper(root,p,q);
    return ((ans!=NULL and ans->lca!=NULL)?ans->lca:NULL);
}
void c_p_c(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
int main(){
    c_p_c();
    node *root=levelorderinput();
    printlevelorder(root);
    
    //it is assumed that all nodes have unique value . if nodes have
    //similar values then instead of p,q as integers take p and q as node*
    //for input
    cout<<LCA(root,6,7)->data<<endl;
}
