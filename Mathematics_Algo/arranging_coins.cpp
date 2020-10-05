class Solution {
public:
    int arrangeCoins(int n) {
        int i=1;
        long s=0;
        while(s<=n)
        {
            s=s+i;
            i++;
        }
        i--;
        return i-1;
    }
};
