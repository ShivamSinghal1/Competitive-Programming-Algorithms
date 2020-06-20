int pw(int b, int p) { int r = 1; while (p > 0) { if (p & 1) r = r * b; 
        p = p >> 1; b = b * b; } return r; }
