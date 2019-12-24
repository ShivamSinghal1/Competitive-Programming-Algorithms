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
