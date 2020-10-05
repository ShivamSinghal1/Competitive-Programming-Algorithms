
//  Quick sort using the 3 way partition technique(Dutch national flag algorithm)
// Author : Rajvir Singh 

// This is generally used to sort array containing lots of redundant data 
// Time complaxity : O(n) 
// Space complexity : O(1)

// The program focusses  on the dutch national flag method to make three partitions : 
// We need to select a pivot element 
// The values less than pivot will be before the pivot element and make the first partition
// The values equal to the pivot element will be the second partition
// The values greater than the pivot will be the third parititon 
// overtime and in many cases there may be chances that one of these partition may not exist
// we will decide the pivot element accordingly
// An improvement in this algorithm can be done by randomising the pivot selection too, 
// also the two recursions can also be avoided  by only one call using the tail recursion elimination
// but I have not included it in the code in order to not make it messed up 
// Note : this program will also run for standard input given by user 
 


#include <bits/stdc++.h>
using namespace std;
void func(int a[], int l, int r, int& i, int& j){
	i = l - 1, j = r;
	int x = l - 1, y = r;
	int v = a[r];                   // our pivot element selected 
	while (1){
		while (a[++i] < v);         // we find the  first element greater than pivot 
                                    // the loop will terminate after some time as v is the last element  
		
		while (v < a[--j])          // find the first element from the right smaller than the pivot 
			if (j == l)             // come out of the loop if the index is  equal to first element 
				break;

		
		if (i >= j)                 // make sure the pointers never cross 
			break;
		swap(a[i], a[j]);           // swapping the smaller and bigger element to keep them in correct position

		if (a[i] == v) {            // all the left equal occurence of the pivot is moved to the start of the array and the counter used is x 
			x++;
			swap(a[x], a[i]);
		}

		if (a[j] == v) {            // all the right equal occurence of the pivot is moved to the end of the array and the counter used is  y 
			y--;
			swap(a[j], a[y]);
		}
	}

	swap(a[i], a[r]);               // pivot element at its correct position

	j = i - 1;                      // move all the left equal occurence to adjacent position of a[i] 
	for (int k = l; k < x; k++, j--)
		swap(a[k], a[j]);

	i = i + 1;                      // move all the right equal occurence to adjacent position of a[i]
	for (int k = r - 1; k > y; k--, i++)
		swap(a[i], a[k]);

    // parition created and now the usual quick sort implementation can be carried on         
}


void quickSort(int a[], int l, int r){           // 3-way partition based quick sort
	if(r<=l)
	    return;

	int i, j;
	func(a, l, r, i, j);                        // this is the partition function and the variables i and j are passed as reference

	quickSort(a, l, j);                         // recursion calls to quicksort for the two partitions
	quickSort(a, i, r);                         // can be improved using tail recursion elimination 
}

int main(){
    int n;
    cout<<"enter the size of the array : "<<endl; 
    cin>>n;                                     // size of the array 
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }  
	quickSort(a, 0,n-1);            // quicksort function to sort the array
	
    cout<<"the sorted array : "<<endl; 
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

	return 0;
}


// See code : https://rextester.com/DHLM35529