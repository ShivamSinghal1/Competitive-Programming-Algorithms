struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree (int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    int sum(int idx) {
        int ret = 0;
        for ( ; idx > 0; idx -= idx & -idx)
            ret += bit[idx]; 
        return ret;
    }

    void add(int idx, int delta) {
        for ( ; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }
};
