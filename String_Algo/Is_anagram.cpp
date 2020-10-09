#include<bits/stdc++.h>
using namespace std;


bool is_anagram(string input1, string input2) //T(n) = O(n) .... S(n) = O(1)
{   
    if(input1.length() != input2.length()) return false;

    int buffer[26] = {0};
    
    for(int i=0; i < input1.length(); i++)
    {
        buffer[input1.at(i) - 'a']++;
        //cout<<buffer[i]<<endl;
        buffer[input2.at(i) - 'a']--;
        //cout<<buffer[i]<<endl;
    }
    // for(int i=0;i<26;i++){
    //     cout<<buffer[i]<<" ";
    // }
    cout<<endl;
    for(int j=0; j < 26; j++)
    {
        if(buffer[j] != 0) return false;
    }
    return true;
    
}


int main(){
    string a,b;
    getline(cin,a);
    getline(cin,b);

    if(is_anagram(a,b)) cout<<"True";
    else cout<<"False";
    return 0;
}