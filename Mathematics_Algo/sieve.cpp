const long long mx = 1e6 + 1;
long long prime[mx];

vector<long long> sieve()
{
    vector<long long>v;
    long long i;
    for(i=2 ; i < mx ; ++i)
    {
        if(prime[i]>0)
            continue;
        prime[i] = 1;
        long long j=i*i;
        while(j< mx)
        {
            if(prime[j]==0)
                prime[j]=i;
            j+=i;
        }
        v.pb(i); 
    }
    // Return a vector consisting of all prime numbers
    return v;
    // prime[i] represents the smallest prime number which divides 
    // the number i
}
