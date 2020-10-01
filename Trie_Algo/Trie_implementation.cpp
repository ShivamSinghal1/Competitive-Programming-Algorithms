#include<iostream>
#include<map>
using namespace std;

class node{
public:
	char data;
	map<char,node*>mp;
	bool isterminal;
	node(char ch){
		data=ch;
		isterminal=false;
	}
};
class trie{
public:
	node *root;
	trie(){
		root=new node('\0');
	}
	void insert(string word){
		node *temp=root;
		for(int i=0;i<word.length();i++){
			if(temp->mp.count(word[i])!=0){
				temp=temp->mp[word[i]];
			}
			else{
				node * nd=new node(word[i]);
				temp->mp[word[i]]=nd;
				temp=nd;
			}
		}
		temp->isterminal=true;
	}
	bool search(string s){
		node *temp=root;
		for(int i=0;i<s.length();i++){
			if(temp->mp.count(s[i])==0){
				return 0;
			}
			temp=temp->mp[s[i]];
		}
		return temp->isterminal;
	}
};
int main(){
	trie t;
	t.insert("harshit");
	t.insert("harsh");
	t.insert("harish");
	t.insert("aman");
	t.insert("amrat");
	cout<<t.search("aman")<<"\n";
	cout<<t.search("har")<<"\n";
	return 0;
}
