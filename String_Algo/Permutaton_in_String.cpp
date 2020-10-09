#include<iostream>
#include<map>
#include<set>
#include<vector>
using namespace std;

/*
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       vector<int> s1hash(26,0);
       vector<int> s2hash(26,0);
       int s1len = s1.length();
       int s2len = s2.length();

       if(s1len > s2len) return false;

       int left=0, right =0;
       while(right < s1len){
         s1hash[s1[right] - 'a'] += 1;
         s2hash[s2[right] - 'a'] += 1;
         right +=1;
       }
       right -= 1;

       while(right < s2len){
           if(s1hash == s2hash ) return true;
           right += 1;

           if(right != s2len){
            s2hash[s2[right] - 'a'] += 1; 
           }
           s2hash[s2[left] - 'a'] -= 1; 
           left+=1;
       }
       return false;

    }
};
int main(){

    Solution S;
    string s,t;
    getline(cin,s);
    getline(cin,t);
    
    if(S.checkInclusion(s,t)) cout<<"True";
    else cout<<"False";
    
    return 0;
}