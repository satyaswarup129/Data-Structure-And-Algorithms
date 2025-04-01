class Solution {
public:
    int getAns(int i, int n, string s, int k, vector<vector<int>>& palin,
               vector<vector<int>>& dp) {
        if (i >= n || k == 0)
            return 0;
        if (dp[i][k] != -1)
            return dp[i][k];
        int minLen = 1, maxLen = n - i - (k - 1), ans = INT_MAX;
        if (k == 1)
            minLen = maxLen;
        for (int len = minLen; len <= maxLen; len++)
            ans = min(ans, palin[i][i + len - 1] +
                               getAns(i + len, n, s, k - 1, palin, dp));
        return dp[i][k] = ans;
    }
    int palindromePartition(string s, int k) {
        int n = s.size();
        vector<vector<int>> palin(n, vector<int>(n, 0)),
            dp(n, vector<int>(k + 1, -1));
        for (int i = 0; i < n - 1; i++)
            palin[i][i + 1] = (s[i] != s[i + 1]);
        for (int len = 3; len <= n; len++)
            for (int i = 0; i < n; i++)
                if (i + len - 1 < n)
                    palin[i][i + len - 1] = (s[i] != s[i + len - 1]) +
                                            palin[i + 1][i + len - 1 - 1];
        return getAns(0, n, s, k, palin, dp);
    }
};
