#include<bits/stdc++.h>
using namespace std;

int main(){
	int product[100][100];
	int n, m;
	cin >> n >> m;
	int a[n][m];

	for(int i=0; i<n; i++){
	for(int j=0; j<m; j++)
	 cin >> a[i][j];
	}

	for (int j = 0; j <m; ++j)
	{
		if(j%2==0){
			for (int i = 0; i <n; ++i)
			   cout << a[i][j]  << endl;
		} else{
			for (int i =n-1; i >=0; i--)
			     cout << a[i][j]<< endl;
		}
	}


	return 0;
}
