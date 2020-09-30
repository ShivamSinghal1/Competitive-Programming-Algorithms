int prime(int n)
{
    int i,c;
    for(i=2,c=0;i<sqrt(n);i++)
    {
        if(n%i==0)
        {
            c++;
            break;
        }
    }
    if(c==0) return true;
    else return false;
}
int primeproduct(int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        if(prime(i)&&prime(n/i))
        {
            if(i*(n/i)==n) return true;
        }
    }
    return false;
}
