#include<iostream>
#include<utility>
#include<unordered_map>
using namespace std;

class Union_Find{
    unordered_map<char,char> parent;
    unordered_map<char,int> rank;
    public:
        void myMakeSet(char ch){
            parent[ch] = ch;
            rank[ch] = 0;
        }
        char myFind(char ch){
            char x = ch;
            if(parent[ch] != ch)
                x = myFind(parent[x]);
            parent[ch] = x;//path compression
            return x;
        }
        bool myUnion(char ch1,char ch2){
            char pch1 = myFind(ch1);
            char pch2 = myFind(ch2);
            if(pch1 == pch2) return true;
            if(rank[pch1] > rank[pch2])
                parent[pch2] = pch1;
            else if(rank[pch1] < rank[pch2])
                parent[pch1] = pch2;
            else{
                rank[pch1]++;
                parent[pch2] = pch1;
            }
            return false;
        }
};

int main(){
    Union_Find obj;
    cout<<"Enter the number of vertices in the graph: ";
    int n;
    cin>>n;
    cout<<"Enter the names of the vertices(character names):\n";
    char ch,ch2;
    while(n--){
        cin>>ch;
        obj.myMakeSet(ch);
    }
    cout<<"Enter the number of egdes: ";
    cin>>n;
    cout<<"Enter the names of edges(character edges):\n";
    while(n > 0){
        cin>>ch>>ch2;
        if(obj.myUnion(ch,ch2)) break;
        n--;
    }
    if(n == 0)
        cout<<"No cycle(or self loop) detected.\n";
    else
        cout<<"Cycle(or self loop) detected.\n";
    return 0;
}