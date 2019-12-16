ll gcdExtended(ll a,ll b,ll &x,ll &y)
{
	// Base Case
	if (a == 0)
	{
		x = 0, y = 1;
		return b;
	}

	ll x1, y1; // To store results of recursive call
	ll gcd = gcdExtended(b%a, a, x1, y1);

	// Update x and y using results of recursive
	// call
	x = y1 - (b/a) * x1;
	y = x1;

	return gcd;
}

ll modInverse(ll a,ll m)
{
	ll x, y;
	ll g = gcdExtended(a, m, x, y);
	if (g != 1)
		cout << "Inverse doesn't exist";
	else
	{
		// m is added to handle negative x
		ll res = (x%m + m) % m;
        return res;
	}
}

const int MAX = 1 << 20;
ll fact[MAX];
ll ifact[MAX];
void preCalcFac(){
    fact[0] = 1;
    for(int i = 1; i < MAX; ++i)
        fact[i] = fact[i - 1] * i % mod;

    ifact[MAX - 1] = powMod(fact[MAX - 1], mod - 2, mod);
    for(int i = MAX-2; i >= 0 ; ++i)
    {
        ifact[i] = ifact[i + 1] * (i + 1) % mod;
    } 
}


ll nCr(ll n,ll r) 
{ 
   // Base case 
   if (r==0) 
      return 1; 
    return (fac[n]*modInverse(fac[r],mod)%mod * modInverse(fac[n-r],mod))%mod; 
} 
