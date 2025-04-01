class Solution {
public:
    // Recursive DFS function
    void solve(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& ans) {
        vis[node] = 1;       // Mark the current node as visited
        ans.push_back(node); // Add the node to the traversal list
        
        // Explore all adjacent nodes (left to right)
        for (auto &it : adj[node]) {
            if (!vis[it]) {  // If the adjacent node is unvisited
                solve(it, adj, vis, ans); // Recursively visit it
            }
        }
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size(); // Number of vertices
        vector<int> vis(n, 0); // Visited array initialized to 0 (unvisited)
        vector<int> ans; // To store DFS traversal order
        
        int start = 0; // Start DFS from node 0
        solve(start, adj, vis, ans); // Initiate DFS
        
        return ans; // Return the traversal order
    }
};
