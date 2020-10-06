#include<iostream>
#include<vector>
using namespace std;
class Trie{
    Trie* children[26];
    bool isEnd;
    public:
    Trie(){
         for(int i=0;i<26;i++){
            children[i]=NULL;
            isEnd=false;
        }
    }
    void insert(string s){
        Trie* curr = this;
        for(char c:s){
            if(!curr->children[c-'a'])
                curr->children[c-'a']= new Trie();
            curr=curr->children[c-'a'];
        }
        curr->isEnd=true;
    }
    void search(string s){
        Trie* curr = this;
        for(char c:s){
            if(!curr->children[c-'a']){
                curr->isEnd = true;
                break;
            }
            curr=curr->children[c-'a'];
        }
        curr->isEnd = true;
    }
    string prefix(string s){
        Trie* curr = this;
        string res = "";
        for(char c:s){
            if(!curr->isEnd){
                res+=c;
            }else{
                break;
            }
            curr=curr->children[c-'a'];
        }
        return res;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        int n = s.size();
        if(n==0)
            return "";
        if(n==1)
            return s[0];
        Trie* t = new Trie();
        t->insert(s[0]);
        for(int i=0;i<n;i++)
            t->search(s[i]);
        
        return t->prefix(s[0]);
    }
};

int main(){
    vector<string> s;
    int n;cin>>n;
    string str;

    for(int i=0;i<n;i++){
        cin>>str;
        s.push_back(str);
    }

    Solution sol;
    cout<<sol.longestCommonPrefix(s);


}