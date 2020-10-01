
#include<iostream>
#include<ctime>
using namespace std;


void shuffle(int arr[],int s,int e){
    
    //srand() is the random seed generator
    
    srand(time(NULL));
    
    //rand() function produces a random no between 0 and MAX_RANGE(read documentation)
    //rand()%x produces a random no between 0 and x-1(inclusive) 
    
    for(int i=e;i>=s;i--){
        int random_index =rand()%(i+1);
        swap(arr[i],arr[random_index]);
    }

}


int main(){
    
    int arr[]={1,2,3,4,5}
    shuffle(arr,0,4);
    
    for(int i=0;i<5;i++){
    cout<<arr[i]<<" ";
    }

    return 0;
}
