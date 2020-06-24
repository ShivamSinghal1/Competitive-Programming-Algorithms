int powm(int n,int p,int m = i(mod)){
    int res=1;
    n%=m;
    while(p){
        if(p&1)
            res = (res*n)%m;
        p=p>>1;
        n = (n*n)%m;
    }
    return res;
}
