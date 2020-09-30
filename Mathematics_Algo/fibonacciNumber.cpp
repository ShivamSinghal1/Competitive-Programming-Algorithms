// Used pw(n, m) from /Mathematics_Algo/power_without_Mod.cpp
unsigned long long pw(int n, int m)
{
	unsigned long long r = 1;
	while (m > 0)
	{
		if (m & 1)
			r = r * n;
		m = m >> 1;
		n = n * n;
	}
	return r;
}

// O(1)
unsigned long long fibonacciNumber(int n)
{
	return (pw((1 + sqrt(5)), n) - pw((1 - sqrt(5)), n)) / (pw(2, n) * sqrt(5));
}