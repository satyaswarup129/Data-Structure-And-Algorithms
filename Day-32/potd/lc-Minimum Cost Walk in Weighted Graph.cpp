class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int> rank(n, 0), parent(n), ans, val(n, INT_MAX);
        iota(parent.begin(), parent.end(), 0);
        function<int(int)> find = [&](int node) {
            if (parent[node] != node) {
                parent[node] = find(parent[node]);
            }
            return parent[node];
        };
        auto unite =[&](int u, int v, int cost) {
            int rootU = find(u);
            int rootV = find(v);

            if (rootU != rootV) {
                if (rank[rootU] > rank[rootV]) {
                    parent[rootV] = rootU;
                } else if (rank[rootU] < rank[rootV]) {
                    parent[rootU] = rootV;
                } else {
                    parent[rootV] = rootU;
                    rank[rootU]++;
                }
            }
        };
        for (auto& edge : edges) {
            unite(edge[0], edge[1], edge[2]);
        }
        for (auto& edge : edges) {
            int root = find(edge[0]);
            val[root] &= edge[2];
        }
        for (auto& q : query) {
            int u = q[0], v = q[1];
            if (find(u) == find(v)) {
                ans.push_back(val[find(u)]);
            } else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
