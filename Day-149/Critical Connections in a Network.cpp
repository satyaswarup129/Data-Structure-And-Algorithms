class Solution {
public:
    void DFS(int node, int parent, vector<vector<int>>& adjList, vector<int>& disc,
    vector<int>& low, vector<bool>& vis, int& cnt, vector<vector<int>>& bridges){
        disc[node] = low[node] = cnt++;
        vis[node] = 1;
        for(int x : adjList[node]){
            if(x == parent) continue;
            else if(vis[x]) low[node] = min(low[node], low[x]);
            else {
                DFS(x, node, adjList, disc, low, vis, cnt, bridges);
                low[node] = min(low[node], low[x]);
                if(disc[node] < low[x]) bridges.push_back({node, x});
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> bridges;
        vector<vector<int>> adjList(n);
        for(auto e : connections){
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }
        vector<int> disc(n);
        vector<int> low(n);
        vector<bool> vis(n, 0);
        int cnt = 0;
        DFS(0, -1, adjList, disc, low, vis, cnt, bridges);
        return bridges;
    }
};
