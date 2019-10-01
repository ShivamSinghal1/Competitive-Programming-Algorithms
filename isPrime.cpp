bool isPrime(ll int n){
    if(n<=1)
        return false;
    if(n==2)
        return true;
    if(n&1==0)
        return false;
        
    ll int rt = sqrt(n);
    for(ll int i=3;i<=rt;i+=2){
        if(n%i==0)
            return false;
    }
    return true;
}
