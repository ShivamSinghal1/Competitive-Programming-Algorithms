const int mx = 1e6 + 1;
int prime[mx];

vector<int> sieve()
{
    vector<int>v;
    int i;
    for(i=2 ; i < mx ; ++i)
    {
        if(prime[i]>0)
            continue;
        prime[i] = 1;
        int j=i*i;
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
