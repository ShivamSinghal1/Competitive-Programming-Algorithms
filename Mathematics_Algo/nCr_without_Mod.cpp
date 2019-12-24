ll nCr(ll n,ll r){
    ll result = n;
    ll i;
    rep(i,2,r+1){
        result*=(n-i+1);
        result/=i;
    }
    return result;
}
