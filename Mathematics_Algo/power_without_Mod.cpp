long long pw(long long b, long long p) { long long r = 1; while (p > 0) { if (p & 1) r = r * b; 
        p = p >> 1; b = b * b; } return r; }
