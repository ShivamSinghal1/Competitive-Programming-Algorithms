#include <iostream>

//Computes the last digit of  Fibonacci series square sum- F0^2 + F1^2 + · · · + Fn^2 in constant time.
long long fibonacci_fast(int n)
{

    long long f[n];
    f[0] = 0;
    f[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        f[i] = (f[i - 1] + f[i - 2]) % 10;
    }

    return f[n];
}
long long fib_square(long long n)
{
    if (n < 1)
        return 0;
    long long x = fibonacci_fast(n % 60);
    long long y = fibonacci_fast((n + 1) % 60);
    long long z = (x * y) % 10;
    return z;
}
int main()
{
    long long n = 0;
    std::cin >> n;
    std::cout << fib_square(n);
}
