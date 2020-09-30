#include <bits/stdc++.h>
using namespace std;
typedef __int128 in;

in inp()
{
    in t=0;
    string s;
    cin>>s;
    for(char c:s)
    {
        t*=10;
        t+=(c-'0');
    }
    return t;
}

void out(in n)
{
    stack<char>s;
    while(n)
    {
        s.push((n%10 +'0'));
        n/=10;
    }
    while(!s.empty())
    {
        printf("%c",s.top());
        s.pop();
    }
}

in mul(in a, in b, in M)
{
    return (a*a+b)%M+1;
}

in pollard(in n, in comp) //pollard rho algorithm
{
    if(n==1) return 1;
    if(n%2==0) return 2;

    srand(time(0));
    in y=rand()%n+1,c=rand()%n+1,x,gcd=1,sq=sqrt(n)+100;
    x=y;
    int count=0;
    while(gcd==1)
    {
        if(count>=sq) return n;
        count++;
        x=mul(x,c,n);
        y=mul(mul(y,c,n),c,n);
        if(x==y) gcd=n;
        else gcd=__gcd(abs(x-y),n);
        if(gcd!=1)
        {
            if(gcd==n || gcd==comp)
            {
                y=rand()%n+1;
                x=y;
                gcd=1;
            }
            else break;
        }
    }
    return gcd;
}

in modexp(in a, in b, in M=1000000007)
{
    in res=1;
    while(b)
    {
        if(b&1) res=(res*a)%M;
        b>>=1;
        a=(a*a)%M;
    }
    return res;
}


bool miller_rabin(in n, in k)
{
    in s=0,d=n-1,t;
    while(!(d&1)) d>>=1,s++;

    bool flag=true; int i;
    t=modexp(k,d,n);
    if(t==1 || t==n-1) return 1;
    for(i=0;i<s;i++)
    {
        t=(t*t)%n;
        if(t==1) return 0;
        if(t==n-1) return 1;
    }
    return 0;
}

bool prime(in n)
{
    vector<int>A {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};
    for(auto x:A) if(x==n) return 1;
    if(!(n&1)) return 0;

    bool flag=true;
    for(auto x:A) flag&=miller_rabin(n,x);
    return flag;
}

int main()
{
    while(1)
    {
        in n=inp();
        if(n==0) break;
        vector<pair<in,int>> f;

        while(n!=1)
        {
            in x=pollard(n,0);
            int c=1;
            while(!prime(x)) x=pollard(x,x);
            n/=x;
            while(n%x==0)
            {
                n/=x;
                c++;
            }
            f.push_back({x,c});
        }
        sort(f.begin(),f.end());
        for(auto o:f)
        {
            out(o.first);
            printf("^%d ",o.second);
        }
        printf("\n");
    }
    return 0;
}
