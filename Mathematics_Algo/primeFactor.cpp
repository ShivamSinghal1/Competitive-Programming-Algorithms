vector<long long> sieve(long long n,long long *a)
{
    vector<long long>v;
    fill(a,a+n+1,0);
    long long i;
    rep(i,2,n+1)
    {
        if(a[i]>0)
            continue;
        a[i] = 1;
        long long j=i*i;
        while(j<=n)
        {
            if(a[j]==0)
                a[j]=i;
            j+=i;
        }
        v.pb(i); 
    }
    return v;
}

vector<long long> primeFactor(long long n,vi v){
    vector<long long> pFactor;
    for(auto prime:v)
    {
        if(n%prime == 0)
        {
            while(n%prime==0)
            {
                n/=prime;
            }
            pFactor.pb(prime);
        }
    }
    if(n!=1){
        pFactor.push_back(n);
    }
    return pFactor;
}

/*How to USE
    int MAX = 100000;
    int* arr = new int[MAX+1];
    vi v = sieve(MAX,arr);
    vi p = primeFactor(n,v);  n = prime factor to be calculated
*/
