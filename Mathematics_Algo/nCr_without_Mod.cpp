long long nCr(long long n,long long r){
    long long result = n;
    long long i;
    rep(i,2,r+1){
        result*=(n-i+1);
        result/=i;
    }
    return result;
}
