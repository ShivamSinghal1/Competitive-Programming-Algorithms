#include<iostream>
#include<list>
#include<queue>
#include<map>
using namespace std;

template<typename t>
class graph{
public:
    
    map<t,list<t> > adjlist;
    
    graph(){
    }
    
    void addedge(t i,t j,bool isbidirectional=true){
        adjlist[i].push_back(j);
        if(isbidirectional){
            adjlist[j].push_back(i);
        }
    }
    
    bool iscyclicdfshelper(int s,map<t,bool> &visited,map<int,bool> &instack){
        
        visited[s]=true;
        instack[s]=true;
        bool ans;
        for(int nbr:adjlist[s]){
            if(visited[nbr]==true && instack[nbr]==true ){
                return true;
            }
            if(!visited[nbr])
                ans=iscyclicdfshelper(nbr, visited, instack);
            
            if(ans==true){
                return true;
            }
        }
        instack[s]=false;
        return ans;
    }
    
    bool iscyclicdfs(){
        map<t,bool> visited;
        map<int,bool> instack;
        
        for(auto node:adjlist){
            if(!visited[node.first]){
            bool ans=iscyclicdfshelper(node.first,visited,instack);
            if(ans)
                return true;
            }
        }
        return false;
    }
};

int main(){
    
    graph<int> g;
    g.addedge(1, 0,false);
    g.addedge(0, 2,false);
    g.addedge(2, 4,false);
    g.addedge(4, 5,false);
    g.addedge(2, 3,false);
    g.addedge(3, 1,false);
    g.addedge(3, 0,false);
    
    if(g.iscyclicdfs()){
        cout<<"cycle is present";
    }
    else{
        cout<<"cycle ain't present";
    }
    
    return 0;
}


