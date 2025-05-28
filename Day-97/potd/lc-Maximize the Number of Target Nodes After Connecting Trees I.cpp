class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int m=edges2.size();
        vector<vector<int>>adj(m+1);

        for(auto it : edges2){
            int u=it[0];
            int v=it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int maxi=0;
        for(int i=0;i<=m;i++){
            int cnt=0;
            queue<pair<int,int>>q;
            q.push({i,0});
            vector<bool>vis(m+1,false);

            while(!q.empty()){
                auto it=q.front();
                q.pop();
                int node=it.first;
                int step=it.second;
                vis[node]=true;

                if(step < k)
                cnt++;

                for(auto it : adj[node]){
                    if(!vis[it] && step+1 < k)
                    q.push({it,step+1});
                }
            }
            maxi=max(maxi,cnt);
        }
        int n=edges1.size();
        vector<vector<int>>adj1(n+1);

        for(auto it : edges1){
            int u=it[0];
            int v=it[1];

            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }
        vector<int>ans(n+1);
        for(int i=0;i<=n;i++){
            int cnt=0;
            queue<pair<int,int>>q;
            q.push({i,0});
            vector<bool>vis(n+1,false);

            while(!q.empty()){
                auto it=q.front();
                q.pop();
                int node=it.first;
                int step=it.second;
                vis[node]=true;

                if(step <= k)
                cnt++;

                for(auto it : adj1[node]){
                    if(!vis[it] && step+1 <= k)
                    q.push({it,step+1});
                }
            }
            ans[i]=cnt+maxi;
        }
        return ans;
    }
};
