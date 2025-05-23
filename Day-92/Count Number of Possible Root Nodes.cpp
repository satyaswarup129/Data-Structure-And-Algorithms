
int dfs(int root, vector<vector<int>> &adj,  map<int,map<int,int>> &guess, vector<int> &dp, int parent) {
        int correctlyGuessed = 0;
        vis[root]=1;
        for(auto &ch: adj[root]){
            if(ch == parent) continue;
            if(guess[root][ch]) correctlyGuessed++;
            correctlyGuessed += dfs(ch, adj, guess, dp, root);
        }
        return dp[root] = correctlyGuessed;
    }
    
int dp2(int root,  vector<vector<int>> &adj, map<int,map<int,int>> &guess, int k, vector<int> &dp, int parent) {
    int possibleRoots = 0;
    int correctlyGuessed = 0; //answer considering the current node as root
    if(parent != -1) {
        correctlyGuessed = dp[parent]
                    - guess[parent][root] //subtract previous edge guess
                    + guess[root][parent]; //add current edge guess
    } else {
        correctlyGuessed = dp[root];
    }
    dp[root] = correctlyGuessed; //update dp
    if(correct>=k) possibleRoots++; //possible root
    for(auto &ch: adj[root]){ //update children
        if(ch == parent) continue;
        possibleRoots += dp2(ch, adj, guess, k, dp, root);
    }
    return possibleRoots;
}

int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
    const int n = edges.size()+1;
    vector<int> dp(n);
    map<int,map<int,int>> guess;
    for(auto &x:guesses) {
        guess[x[0]][x[1]] = 1;
    }
    vector<vector<int>> adj(n);
    for(auto &x:edges){
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }
    dfs(0, adj, guess, k, dp, -1);
    return dp2(0, adj, guess, k, dp, -1);
}
