ll powMod(ll n,ll p,ll m){
    ll res=1;
    n%=m;
    while(p){
        if(p&1)
            res = (res*n)%m;
        p=p>>1;
        n = (n*n)%m;
    }
    return res;
}
