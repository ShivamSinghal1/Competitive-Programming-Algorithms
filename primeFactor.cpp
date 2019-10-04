vector<ll> sieve(ll n,ll int*a)
{
    vector<ll int>v;
    fill(a,a+n,0);
    ll i;
    rep(i,2,n+1)
    {
        if(a[i]>0)
            continue;
        a[i] = 1;
        ll j=i*i;
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

vector<ll> primeFactor(ll n,ll int*a){
    vector<ll> pFactor;
    while(a[n]!=1){
        pFactor.push_back(a[n]);
        n /= a[n];
    }
    pFactor.push_back(n);
    return pFactor;
}

/* How to Use
ll int* arr = new ll int[100];
  vector<ll int> v = sieve(100,arr);
  vector<ll int> p = primeFactor(65,arr);
  for(auto i:p){
    cout<<i<<" ";
  }
 */ 
