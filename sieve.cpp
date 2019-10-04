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
