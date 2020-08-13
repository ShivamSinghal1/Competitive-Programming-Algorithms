int powMod(int n,int p,int m){
    int res=1;
    n%=m;
    while(p>0){
        if(p&1)
            res = (res*n)%m;
        p=p>>1;
        n = (n*n)%m;
    }
    return res;
}


const int MAX = 1<<20;
int fact[MAX];
int ifact[MAX];
void preCalcFac(int m){
    fact[0] = 1;
    for(int i = 1; i < MAX; ++i)
        fact[i] = (fact[i - 1] * i) % m;

    ifact[MAX - 1] = powMod(fact[MAX - 1], m - 2, m);
    for(int i = MAX-2; i >= 0 ; --i)
        ifact[i] = (ifact[i + 1] * (i + 1)) % m;
}


int nCr(int n,int r,int m) 
{ 
   // Base case 
   if (r==0) 
      return 1;
    int ans = (fact[n]*ifact[r])%m;
    ans = (ans*ifact[n-r])%m;
    return ans;
}
