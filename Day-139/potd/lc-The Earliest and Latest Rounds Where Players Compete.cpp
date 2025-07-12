class Solution {
public:
    vector<int> earliestAndLatest(int n, int fp, int sp) {
        vector<int>v(n); 
        iota(v.begin(), v.end(), 1); 
        int f = fp - 1, s = sp - 1, nn = n-1; 
        int memo[30][30][30]; 
        memset(memo, -1, sizeof memo); 
        int mn = INT_MAX, mx = INT_MIN; 
        function<void(int,int,int,int,int,int,int)> dp = [&](int msk, int round, int i, int j, int l, int m, int r) -> void{
            if(i >= j){
                dp(msk, round + 1, 0, nn, l, m, r);
            }else if((msk & (1 << i)) == 0){
                dp(msk, round, i + 1, j, l, m, r); 
            }else if((msk & (1<<j)) == 0){
                dp(msk, round, i, j - 1, l, m, r); 
            }else if(i == f and j == s){
                mn = min(mn, round); 
                mx = max(mx, round); 
            }else if(memo[l][m][r] == -1){
                memo[l][m][r] = 1; 
                if(i != f and i != s){
                    dp(msk ^ (1 << i), round, i + 1, j - 1, l -(i<f), m - (i > f and i < s), r - (i > s)); 
                }
                if(j != f and j != s){
                    dp(msk ^ (1 << j), round, i + 1, j - 1, l -(j<f), m - (j > f and j < s), r - (j > s)); 
                }
            }

        };


        dp((1<<n) -1, 1, 0, n - 1, f, s - f -1, nn - s); 
        return {mn, mx}; 
    }
};
