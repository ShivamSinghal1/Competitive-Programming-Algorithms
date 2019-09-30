long long int powmod(long long int n,long long int p,long long int m){
    long long int res=1;
    n%=m;
    while(p){
        if(p&1)
            res = (res*n)%m;
        p=p>>1;
        n = (n*n)%m;
    }
    return res;
}
