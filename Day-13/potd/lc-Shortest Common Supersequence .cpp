#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if (str1[i] == str2[j])
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }

        string result;
        int x = 0, y = 0;
        for (char c : reconstructLCS(dp, str1, str2)) {
            while (x < n && str1[x] != c) result += str1[x++];
            while (y < m && str2[y] != c) result += str2[y++];
            result += c;
            x++;
            y++;
        }
        result += str1.substr(x) + str2.substr(y);
        return result;
    }

private:
    string reconstructLCS(vector<vector<int>>& dp, string& str1, string& str2) {
        string lcs;
        int x = 0, y = 0;
        while (x < str1.size() && y < str2.size()) {
            if (str1[x] == str2[y]) {
                lcs += str1[x++];
                y++;
            } else if (dp[x + 1][y] >= dp[x][y + 1]) x++;
            else y++;
        }
        return lcs;
    }
};
