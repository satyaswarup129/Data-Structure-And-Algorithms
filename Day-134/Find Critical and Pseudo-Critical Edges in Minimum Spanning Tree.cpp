class Solution {
public:
    struct DSU {
        int N, c;
        vector<int> f, sz;
        DSU (int n) : N(n), c(n) {
            f.resize(n);
            sz.assign(n, 1);
            iota(begin(f), end(f), 0);
        }
        void clear() {
            c = N;
            fill(begin(sz), end(sz), 1);
            iota(begin(f), end(f), 0);
        }
        int find(int x) {
            while (x != f[x])
                x = f[x] = f[f[x]];
            return x;
        }
        bool merge(int x, int y) {
            x = find(x);
            y = find(y);
            if (x == y) return false;
            if (sz[x] > sz[y]) swap(x, y);
            f[x] = y;
            sz[y] += sz[x];
            c--;
            return true;
        }
        int count() {
            return c;
        }
    };

    struct Tree {
        int n, N, timer;
        vector<vector<pair<int, int>>> adj;
        vector<vector<int>> up, mx;
        vector<int> tin, tout;

        Tree(int _n) : n(_n) {
            N = 32 - __builtin_clz(n);
            timer = 0;
            adj.resize(n);
            up.assign(n, vector<int>(N, -1));
            mx.assign(n, vector<int>(N, INT_MIN));
            tin.assign(n, 0);
            tout.assign(n, 0);
        }
        Tree(vector<vector<int>> &edges) : Tree(edges.size() + 1) {
            for (int i = 0; i < n - 1; i++) {
                int u = edges[i][0], v = edges[i][1], w = edges[i][2];
                adj[u].push_back({w, v});
                adj[v].push_back({w, u});
            }
            up[0][0] = 0;
            mx[0][0] = 0;
            dfs(0);
        }
        void dfs (int u) {
            tin[u] = ++timer;
            for (int i = 1; i < N; i++) {
                up[u][i] = up[up[u][i - 1]][i - 1];
                mx[u][i] = max(mx[u][i - 1], mx[up[u][i - 1]][i - 1]);
            }
            for (auto [w, v] : adj[u]) if (!tin[v]) {
                up[v][0] = u;
                mx[v][0] = w;
                dfs(v);
            }
            tout[u] = ++timer;
        }
        bool is_ancestor(int u, int v) {
            return tin[u] <= tin[v] && tout[v] <= tout[u];
        }
        int max_path_edge_to_ancestor(int u, int v) {
            int mxe = 0;
            for (int i = N - 1; i >= 0; i--) {
                if (is_ancestor(v, up[u][i])) {
                    mxe = max(mxe, mx[u][i]);
                    u = up[u][i];
                }
            }
            return mxe;
        }
        int max_path_edge(int u, int v) {
            if (is_ancestor(u, v))
                return max_path_edge_to_ancestor(v, u);
            if (is_ancestor(v, u))
                return max_path_edge_to_ancestor(u, v);
            int l = u;
            for (int i = N - 1; i >= 0; i--) {
                if (!is_ancestor(up[l][i], v)) {
                    l = up[l][i];
                }
            }
            l = up[l][0];
            return max(max_path_edge_to_ancestor(u, l), max_path_edge_to_ancestor(v, l));
        }
        int lca(int u, int v) {
            if (is_ancestor(u, v))
                return u;
            if (is_ancestor(v, u))
                return v;
            for (int i = N - 1; i >= 0; i--) {
                if (!is_ancestor(up[u][i], v)) {
                    u = up[u][i];
                }
            }
            return up[u][0];
        }
    };

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        DSU dsu = DSU(n);
        vector<vector<int>> edge_idx(m);
        for (int i = 0; i < m; i++) {
            edge_idx[i] = {edges[i][0], edges[i][1], edges[i][2], i};
        }
        sort(begin(edge_idx), end(edge_idx), [] (auto &a, auto &b) -> bool {
            return a[2] < b[2];
        });
        vector<int> idx(m);
        for (int i = 0; i < m; i++) {
            edges[i] = {edge_idx[i][0], edge_idx[i][1], edge_idx[i][2]};
            idx[i] = edge_idx[i][3];
        }
        vector<vector<int>> mst;
        vector<int> mst_edge;
        vector<bool> in_mst(m);
        vector<vector<int>> crit(2);
        int cost = 0;
        for (int i = 0; i < m; i++) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            if (dsu.merge(u, v)) {
                mst.push_back(edges[i]);
                mst_edge.push_back(i);
                in_mst[i] = true;
                cost += w;
            }
        }
        Tree st = Tree(mst);
        for (int i = 0; i < m; i++) {
            if (in_mst[i]) continue;
            if (edges[i][2] == st.max_path_edge(edges[i][0], edges[i][1])) {
                crit[1].push_back(idx[i]);
            }
        }
        for (int i = 0; i < n - 1; i++) {
            dsu.clear();
            int new_cost = 0;
            for (int j = 0; j < m; j++) {
                if (j == mst_edge[i]) continue;
                if (dsu.merge(edges[j][0], edges[j][1])) {
                    new_cost += edges[j][2];
                }
            }
            if (dsu.count() != 1 || new_cost > cost) {
                crit[0].push_back(idx[mst_edge[i]]);
            } else {
                crit[1].push_back(idx[mst_edge[i]]);
            }
        }
        return crit;
    }
};
