//Sum of longest non-decreasing subarray
#include<iostream>
using namespace std;

int main(){
    cout<<"Enter the number of : ";
    int n;
    cin>>n;
    cout<<"Enter "<<n<<" elements:\n";
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int max = arr[0],curr = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i] >= arr[i-1]) curr += arr[i];
        else curr = arr[i];
        if(curr > max) max = curr;
    }
    cout<<"Sum of longest non-decreasing subarray: "<<max<<endl;
    return 0;
}