ll int nCr(ll int n,ll int r){
    ll int result = n;
    ll int i;
    rep(i,2,r+1){
        result*=(n-i+1);
        result/=i;
    }
    return result;
}
