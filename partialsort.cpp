//Sorting Algorithm using STL 
//Partial Sort Method 

#include <bits/stdc++. h>
using namespace std; 

int main()
{
    int a[] = {9,8,7,6,5,4,3,2,1};
    
    partial_sort(a, a+4, a+9); 
    /* now a is 1,2,3,4,9,8,7,6,5  */ 
    
    int b[] = {1,5,6,2,4,8,9,3,7};
    
    /* sorts b such that first 4 elements are the greatest elements
    in the array and are in descending order */
    partial_sort(b, b+4, b+9);  
    /* now b is  9,8,7,6,1,2,4,3,5 */
}
