#include <bits/stdc++.h>
using namespace std;
unsigned int count_set_bits(int n)
{
    unsigned int count = 0;
    while (n > 0)
    {
        n &= (n - 1);
        count++;
    }
    return count;
}

int main()
{
    int z;
    cin >> z;
    cout << count_set_bits(z);
    return 0;
}