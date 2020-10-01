long long sumOfGP(long long r,long long n,long long m)
{
    // n = number of terms - 1
    // first term is assumed 1
    // multiply with first term if it is not a
    // r = common ratio
    if(n<0)
        return 0;
    if(n==0)
        return 1;
    if(n==1)
        return (1+r)%m;
    long long ans;
    if(n%2)
        ans=1ll*(1+r)*sumOfGP((1ll*r*r)%m,(n-1)/2,m);
    else
        ans=1+((1ll*r*(1+r))%m)*sumOfGP((1ll*r*r)%m,n/2-1,m);
    return ans%m;
}
