class Solution {
public:
    int maxProfit(int n, vector<vector<int>>& edges, vector<int>& score) {
        vector<int> req(n), memo(1 << n, -1);
        for(auto& edge : edges)
            req[edge[1]] |= (1 << edge[0]);
        return [&](this auto go, int mask) -> int {
            if(memo[mask] != -1) return memo[mask];
            for(int nxt = memo[mask] = 0; nxt < n; nxt++)
                if((mask >> nxt & 1) == 0 && (req[nxt] & mask) == req[nxt])
                    memo[mask] = max(memo[mask], (__builtin_popcount(mask) + 1) * score[nxt] + go(mask | (1 << nxt)));
            return memo[mask];
        }(0);
    }
};
