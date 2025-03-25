class Solution {
public:

    int costToMakeSame(char &c, char &d) {
        int diff = abs(c - d);
        int cost = min(diff, 26 - diff);
        return cost;
    }

    int solve(int i, int j, string &s, int k, vector<vector<vector<int>>>&dp) {
        if (i > j) {
            return 0;
        }
        if (i == j) {
            return 1;
        }
        if (dp[i][j][k] != -1) {
            return dp[i][j][k];
        }

        int ans = 0;

        // Try to make both s[i] & s[j] same
        int cost = costToMakeSame(s[i], s[j]);
        if (cost <= k) {
            ans = max(ans, 2 + solve(i + 1, j - 1, s, k - cost, dp));
        }
        // skip either s[i] or s[j]
        ans = max(ans, solve(i + 1, j, s, k, dp));
        ans = max(ans, solve(i, j - 1, s, k, dp));

        return dp[i][j][k] = ans;
    }

    int longestPalindromicSubsequence(string s, int k) {
        int n = s.size();
        vector<vector<vector<int>>>dp(n + 1, vector<vector<int>>(n + 1, vector<int>(k + 1, -1)));
        return solve(0, n - 1, s, k, dp);
    }
};
