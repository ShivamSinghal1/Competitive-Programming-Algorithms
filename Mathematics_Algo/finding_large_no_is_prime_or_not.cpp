/*
rishabh0904
*/
#include<iostream>
#include<bitset>
#include<vector>
#define int long long
using namespace std;
const int n = 10000000;

bitset<10000005> b;
vector<int> primes;
void sieve() {
	b.set(); //it will make all the bits 1,1,1,1,...
	//means all are prims right now
	for (int i = 2; i <= n; i++) {
		if (b[i]) {
			primes.push_back(i);
			for (int j = i * i; j <= n; j += i)
				b[j] = 0;
		}
	}
	b[2] = 1;
	b[0] = b[1] = 0;
}
bool is_prime_large(int a) {
	if (a <= n)
		return b[a];
	else {
		//i is not prime but prime[i] is a prime no
		for (int i = 0; primes[i]*primes[i] <= a; i++) {
			if (a % primes[i] == 0)
				return false;
		}
		return true;
	}
}


int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	sieve();
	int n;
	cin >> n;
	if (is_prime_large(n)) {
		cout << " Its a prime" << endl;
	}
	else {
		cout << "Not Prime" << endl;
	}

	return 0;



}