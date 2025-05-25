
class Solution {
public:
    int n, K;
    vector<vector<int>> tree;
    vector<int> nums;
    vector<vector<array<long long,2>>> dp;

    void dfs(int u, int p) 
    {
        for (int v : tree[u]) 
        {
            if (v != p) 
            dfs(v, u);
        }

        for (int d = 1; d <= K; ++d) 
        {
            for (int s = 0; s < 2; ++s) 
            {
                long long no_invert = (s == 0 ? nums[u] : -nums[u]);
                for (int v : tree[u]) 
                {
                    if (v != p)
                        no_invert += dp[v][min(d + 1, K)][s]; 
                }

                long long res = no_invert;

                if (d == K) 
                {
                    long long invert = (s == 0 ? -nums[u] : nums[u]);
                    for (int v : tree[u]) {
                        if (v != p) 
                            invert += dp[v][1][1 - s];
                    }
                    res = max(res, invert);
                }

                dp[u][d][s] = res;
            }
        }
    }

    long long subtreeInversionSum(vector<vector<int>>& edges,vector<int>& nums_,int k_) 
    {
        nums = nums_;
        K = k_;
        n = nums.size();

        tree.assign(n, {});
        for (auto e : edges) 
        {
            int u = e[0], v = e[1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        dp.assign(n, vector<array<long long, 2>>(K + 1));
        dfs(0, -1);
        return dp[0][K][0]; 
    }
};
