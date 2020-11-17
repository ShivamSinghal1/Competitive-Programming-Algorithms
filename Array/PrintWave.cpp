// Given a 2D array. Print the elements of the array in a wave form row-wise and columnwise.

// For example if the array is given as:
//     1   2   3   4                  
//     5   6   7   8     
//     9   10  11  12
//     13  14  15  16                     

//   Row-wise O/P:     1,2,3,4,8,7,6,5,9,10,11,12,16,15,14,13
//   Column-wise O/P:  1,5,9,13,14,10,6,2,3,7,11,15,16,12,8,4

#include<bits/stdc++.h>
using namespace std;

void row_wise(int a[][100], int n, int m){
    for(int i=0;i<n;i++){
        if(i%2 == 0){
            //left to right
            for(int j=0; j<m; j++){
                cout<<a[i][j]<<" ";
            }
        }
        else{
            //right to left
            for(int j=m-1; j>=0; j--){
                cout<<a[i][j]<<" ";
            }
        }
    }
}
void column_wise(int a[][100], int n, int m){
    for(int j=0;j<m;j++){
        if(j%2==0){
            //up to bottom
            for(int i=0; i<n; i++){
                cout<<a[i][j]<<" ";
            }
        }
        else{
            //bottom to up
            for(int i=n-1; i>=0 ;i--){
                cout<<a[i][j]<<" ";
            }
        }
    }
}
int main(){
    
    //Dimensions of 2D array
    int n,m;
    cin>>n>>m;
    int a[100][100] = {0};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    
    row_wise(a,n,m);
    cout<<endl;
    column_wise(a,n,m);
    cout<<endl;
    
    return 0;
}
