class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& t : times) {
            adj[t[0]].push_back({t[1], t[2]});  // from -> (to, time)
        }

        // Min-heap: (time, node)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();

            for (auto& [nei, wt] : adj[node]) {
                if (dist[nei] > time + wt) {
                    dist[nei] = time + wt;
                    pq.push({dist[nei], nei});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INT_MAX) return -1;  // unreachable node
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
