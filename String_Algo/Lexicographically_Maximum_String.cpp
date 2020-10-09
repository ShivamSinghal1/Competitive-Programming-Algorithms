// CPP program to find the lexicographically 
// maximum substring. 
#include <bits/stdc++.h> 
using namespace std; 

string LexicographicalMaxString(string str) 
{ 
	// loop to find the max leicographic 
	// substring in the substring array 
	string mx = ""; 
	for (int i = 0; i < str.length(); ++i) 
		mx = max(mx, str.substr(i)); 

	return mx; 
} 

// Driver code 
int main() 
{ 
	string str = "ababaa"; 
	cout << LexicographicalMaxString(str); 
	return 0; 
} 
