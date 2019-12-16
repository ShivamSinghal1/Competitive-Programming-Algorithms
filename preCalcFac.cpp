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
