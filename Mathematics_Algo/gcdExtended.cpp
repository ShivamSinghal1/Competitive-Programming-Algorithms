long long gcdExtended(long long a,long long b,long long &x,long long &y)
{
	// Base Case
	if (a == 0)
	{
		x = 0, y = 1;
		return b;
	}

	long long x1, y1; // To store results of recursive call
	long long gcd = gcdExtended(b%a, a, x1, y1);

	// Update x and y using results of recursive
	// call
	x = y1 - (b/a) * x1;
	y = x1;

	return gcd;
}
