vector<ll> sieve(ll n,ll int*a)
{
    vector<ll int>v;
    fill(a,a+n,1);
    a[0]=a[1]=0;
    ll i;
    rep(i,2,n+1)
    {
        if(a[i]==0)
            continue;
        ll j=i*i;
        while(j<=n)
        {
            a[j]=0;
            j+=i;
        }
        v.pb(i); 
    }
    return v;
}
