int gcdExtended(int a,int b,int &x,int &y)
{
	// Base Case
	if (a == 0)
	{
		x = 0, y = 1;
		return b;
	}

	int x1, y1; // To store results of recursive call
	int gcd = gcdExtended(b%a, a, x1, y1);

	// Update x and y using results of recursive
	// call
	x = y1 - (b/a) * x1;
	y = x1;

	return gcd;
}

int modInverse(int a,int m)
{
	int x, y;
	int g = gcdExtended(a, m, x, y);
	if (g != 1)
		cout << "Inverse doesn't exist";
	else
	{
		// m is added to handle negative x
		int res = (x%m + m) % m;
        return res;
	}
}


int nCr(int n,int r) 
{ 
   // Base case 
   if (r==0) 
      return 1; 
  
    // Fill factorial array so that we can find all factorial of r, n and n-r 
    int fac[n+1]; 
    fac[0] = 1; 
    for (int i=1 ; i<=n; i++){ 
        fac[i] = fac[i-1]*(i%mod);
        fac[i] %= mod;
    }
    return (fac[n]*modInverse(fac[r],mod)%mod * modInverse(fac[n-r],mod))%mod; 
} 
