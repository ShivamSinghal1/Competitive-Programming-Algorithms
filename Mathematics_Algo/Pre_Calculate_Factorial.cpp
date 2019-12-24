ll powMod(ll n,ll p,ll m){
    ll res=1;
    n%=m;
    while(p>0){
        if(p&1)
            res = (res*n)%m;
        p=p>>1;
        n = (n*n)%m;
    }
    return res;
}


const ll MAX = 1<<20;
ll fact[MAX];
ll ifact[MAX];
void preCalcFac(ll m){
    fact[0] = 1;
    for(ll i = 1; i < MAX; ++i)
        fact[i] = (fact[i - 1] * i) % m;

    ifact[MAX - 1] = powMod(fact[MAX - 1], m - 2, m);
    for(ll i = MAX-2; i >= 0 ; --i)
        ifact[i] = (ifact[i + 1] * (i + 1)) % m;
}
