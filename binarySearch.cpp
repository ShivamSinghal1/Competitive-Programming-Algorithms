int binarySearch(int*a,int s,int e,int k)
{
    int mid;
    while(e>=s){
        mid = s + (e-s)/2;
        if(a[mid]==k){
            return mid;
        }
        else if(a[mid]>k){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return -1;
}
