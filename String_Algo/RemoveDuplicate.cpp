#include <iostream>
#include <cstring>
using namespace std;

void Rduplicate(char a[]){

    int l=strlen(a);
    if(l==1 or l==0){
        return;
    }

    int i=0;
    int j=1;
    for(int j=1;j<l;j++){
    if (a[i] != a[j]){
        i++;
        a[i] =a[j];
        //cout<<a<<endl;
    }
    }
    a[i+1] = '\0';
    return;

    }

int main(){
    char a[1000];
    cin.getline(a,1000);

    Rduplicate(a);

    cout<<a<<endl;
    return 0;

}