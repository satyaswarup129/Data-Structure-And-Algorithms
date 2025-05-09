class Solution {
public:
    int MOD = 1e9 + 7;
    vector<vector<long long>>combo;
    vector<int> digits;
    unordered_map<string, long long> memo;
    int countBalancedPermutations(string num) {
        int n = num.size();
        digits.resize(10, 0);
        int sum = 0;
        for (auto ch : num) {
            int dig = ch - '0';
            digits[dig]++;      
            sum += dig;
        }
        if (sum & 1) 
            return 0;
        calculate_combo(n / 2 + 2);
        long long res = calc_dp(9, sum / 2, n / 2 + n % 2, n / 2);
        return res;
    }
    void calculate_combo(int n) {
        combo.resize(n + 1, vector<long long>(n + 1, 0));
        combo[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            combo[i][0] = 1;   
            for (int j = 1; j <= i; j++) {
                combo[i][j] = (combo[i-1][j-1] + combo[i-1][j]) % MOD;
            }
        }
    }
    long long calc_dp(int digit, int sumLeft, int even, int odd) {
        
        if (even == 0 && odd == 0 && sumLeft == 0)
            return 1;
        if (digit < 0 || sumLeft < 0 || even < 0 || odd < 0)
            return 0;
        string key = to_string(even) + "_" + to_string(odd) + "_" + to_string(sumLeft) + "_" + to_string(digit);
        if (memo.count(key)) {
            return memo[key];
        }
        long long res = 0;
        for (int eveni = 0; eveni <= digits[digit]; eveni++) {
            int oddj = digits[digit] - eveni;
            if (eveni > even || oddj > odd)
                continue;
            res += ((combo[even][eveni] * combo[odd][oddj]) % MOD 
                    * calc_dp(digit - 1, sumLeft - digit * eveni, even - eveni, odd - oddj) % MOD);
            if (res > MOD) {
                res %= MOD;
            }
        }
        memo[key] = res;
        return res;
    }
};
