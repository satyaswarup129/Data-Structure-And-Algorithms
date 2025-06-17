class Solution {
public:
    int dfs(vector<int> adj[], vector<bool> &hasApple, int node, int parent) {
        int distance = 0; //total time to collect all apples from the root.
        for(auto i:adj[node]) {
            if(i!=parent) {
                int temp=dfs(adj, hasApple, i, node); //store whether root's child has an apple or not.
                if(hasApple[i]) { //if root's child has an apple, then we will add 2 to the time, as you have to come back.
                    distance+=(2+temp);
                    hasApple[node]=true; //hasApple[node] has been changed to true because its child has an apple, so for sure you will be returning back.
                }
            } 
        }
        return distance;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        return dfs(adj, hasApple, 0, 0);
    }
};
