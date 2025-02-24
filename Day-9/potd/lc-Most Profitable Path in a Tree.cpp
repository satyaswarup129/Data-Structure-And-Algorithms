class Solution {
public:
    unordered_map<int,int>BobPath;
    vector<int>dp;
    int dfs(int node,int time,vector<int>&amount,vector<int>&vis,vector<int>g[]){
           int cost=0;
           if(BobPath.find(node)!=BobPath.end()){
              if(BobPath[node]==time){
                cost=amount[node]/2;
              }
              else if(BobPath[node]>time){
                  cost=amount[node];
              }
           }
           else{
             cost=amount[node];
           }
           vis[node]=1;
           int maxi=-1e9;
           for(auto newnode:g[node]){
                if(vis[newnode])continue; 
                maxi=max(maxi,dfs(newnode,time+1,amount,vis,g));
           }
        //    cout<<node<<" "<<cost<<" "<<maxi<<endl;
           return dp[node]=cost+(maxi==-1e9?0:maxi);
    }
    void bfs(int node,int par,vector<int>&Bob,vector<int>& amount,vector<int>&vis,vector<int>g[]){
        priority_queue<pair<int,int>>pq;
        pq.push({amount[node],node});
        Bob[node]=par;
        vis[node]=1;
        while(pq.size()){
            auto [cost,node]=pq.top();
            pq.pop();
            if(node==0){
                return ;
            }
            for(auto newnode:g[node]){
               if(newnode==Bob[newnode])continue;
               if(vis[newnode])continue;
               vis[newnode]=1;
               Bob[newnode]=node;
               pq.push({cost+amount[newnode],newnode});
            }
        }
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=edges.size();
        vector<int>g[n+1];
        dp.resize(n+1,-1e9);
        for(auto it:edges){
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        vector<int>Bob(n+1,-1),vis(n+1,0);
        bfs(bob,-1,Bob,amount,vis,g);
        int node=0;
        vector<int>path;
        while(Bob[node]!=-1){
            path.push_back(node);
            node=Bob[node];
        }
        path.push_back(node);
        int time=0;
        for(int i=path.size()-1;i>=0;i--)BobPath[path[i]]=time++;
        time=0;
        for(int i=0;i<=n;i++)vis[i]=0;
        // for(auto it:BobPath)cout<<it.first<<" "<<it.second<<endl;
        // cout<<endl;
        dfs(0,time,amount,vis,g);
        // for(auto it:dp)cout<<it<<" ";
        return dp[0];
    }
};
