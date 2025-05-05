class Solution {
public:
    const int MOD = 1e9 + 7;
    int numTilings(int n) {
        if (n == 0 || n == 1) return 1;
        if (n == 2) return 2;
        
        vector<int> d(n + 1);
        d[0] = 1;
        d[1] = 1;
        d[2] = 2;
        
        for (int i = 3; i <= n; i++) {
            d[i] = (2LL * d[i - 1] % MOD + d[i - 3]) % MOD;
        }
        
        return d[n];
    }
};
