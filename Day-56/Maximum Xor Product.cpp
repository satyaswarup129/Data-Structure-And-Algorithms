class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {        
        int mod = 1000000007;

        int bits = max(a > 0 ? floor(log2(a)) : -1, b > 0 ? floor(log2(b)) : -1) + 1;

        int msb = max(bits, n);
      
        long long xorA = 0;
        long long xorB = 0;

        int moda = 0;
        int modb = 0;
            
        for (int i = msb - 1; i >= 0; i--) {
            long long aBit = a & (1LL << i);
            long long bBit = b & (1LL << i);

            if (i > n - 1) {
                if (aBit) {
                    xorA += (1LL << i);
                }
                if (bBit) {
                    xorB += (1LL << i);
                }
            } else {
                if (aBit == bBit) {
                    xorA += (1LL << i);
                    xorB += (1LL << i);
                } else {
                    if (xorA > xorB) {
                        xorB += (1LL << i);
                    } else {
                        xorA += (1LL << i);
                    }
                }
            }
        }
                
        return ((xorA % mod) * (xorB % mod)) % mod;
    }
};
