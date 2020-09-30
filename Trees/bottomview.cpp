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
map<int,pair<int,int>>mp;
 void topview(Node * root,int dist,int level){
    if(root==NULL){
        return ;
    }
    if(mp.find(dist)!=mp.end()){
        if(level>mp[dist].second){
            mp[dist].first=root->data;
            mp[dist].second=level;
        }
    }
    else{
        mp.insert(make_pair(dist,make_pair(root->data,level)));
    }
    topview(root->left,dist-1,level+1);
    topview(root->right,dist+1,level+1);
 } 

 void topviewhelper(Node *root){
    topview(root,0,0);
    cout<<"top view\n";
    for(auto x:mp){
        cout<<x.second.first<<" ";
    }
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
    //printlevelorder(root);
    topviewhelper(root)
    return 0;
}
