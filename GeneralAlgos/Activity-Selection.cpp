//Unweighted Activity Selection
//Also called as unweighted interval Selection/ interval selection
#include<iostream>
#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
#define strt(i) vec[i].second
#define fin(i) vec[i].first
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    vector<pair<int,int>> vec;
    cout<<"Enter the number of tasks: ";
    int n,s,e;
    cin>>n;
    cout<<"Enter the start and end time of each task:\n";
    for(int i=0;i<n;i++){
        cin>>s>>e;
        vec.push_back(make_pair(e,s));
    }
    sort(vec.begin(),vec.end());
    int total = 1;
    int j = 0;
    for(int i=1;i<n;i++){
        if(strt(i) >= fin(j)){
            total++;
            j = i;
        }
    }
    cout<<"Maximum tasks those can be done are: "<<total<<endl;
    return 0;
}