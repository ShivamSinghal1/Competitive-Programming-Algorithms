#include<iostream>
#include<map>
#include<set>
using namespace std;

/*

Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. 
No two characters may map to the same character but a character may map to itself.

Input: s = "egg", t = "add"
Output: true

Input: s = "foo", t = "bar"
Output: false

Input: s = "paper", t = "title"
Output: true

*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;
        
        map<char,char> map;
        set<char> set;
        
        for(int i=0;i<s.length();i++){
            char c1= s.at(i); char c2 = t.at(i);
            
            if(map.find(c1) != map.end() ){
                if(map[c1] != c2) return false;
            }
            
            else{
                if(set.find(c2) != set.end() ) return false;
                
                map[c1] = c2;
                set.insert(c2);
            } 
        }
      
        return true;     
    }
};
int main(){

    Solution S;
    string s,t;
    getline(cin,s);
    getline(cin,t);
    
    if(S.isIsomorphic(s,t)) cout<<"True";
    else cout<<"False";
    
    return 0;
}