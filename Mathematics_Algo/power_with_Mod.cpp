long long powm(long long n,long long p,long long m = i(mod)){
    long long res=1;
    n%=m;
    while(p){
        if(p&1)
            res = (res*n)%m;
        p=p>>1;
        n = (n*n)%m;
    }
    return res;
}
