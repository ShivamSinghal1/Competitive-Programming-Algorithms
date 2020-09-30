long long gcd(long long a,long long b,long long &x,long long &y)
{
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

long long modInverse(long long a,long long m)
{
    long long x, y;
    long long g = gcd(a, m, x, y);
    if (g != 1)
        return -1;
    else
        return (x%m + m) % m;
}
