class Solution {
public:
    std::vector<int> countBits(int n) {
        std::vector<int> result(n+1);
        int i=0;
        while ( i <= n) {
            result[i] = __builtin_popcount(i);
            i++;
        }
        return result;
    }
};
