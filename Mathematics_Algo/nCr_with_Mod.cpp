long long powMod(long long n,long long p,long long m){
    long long res=1;
    n%=m;
    while(p>0){
        if(p&1)
            res = (res*n)%m;
        p=p>>1;
        n = (n*n)%m;
    }
    return res;
}


const long long MAX = 1<<20;
long long fact[MAX];
long long ifact[MAX];
void preCalcFac(long long m){
    fact[0] = 1;
    for(long long i = 1; i < MAX; ++i)
        fact[i] = (fact[i - 1] * i) % m;

    ifact[MAX - 1] = powMod(fact[MAX - 1], m - 2, m);
    for(long long i = MAX-2; i >= 0 ; --i)
        ifact[i] = (ifact[i + 1] * (i + 1)) % m;
}


long long nCr(long long n,long long r,long long m) 
{ 
   // Base case 
   if (r==0) 
      return 1;
    long long ans = (fact[n]*ifact[r])%m;
    ans = (ans*ifact[n-r])%m;
    return ans;
}
