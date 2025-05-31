class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& b) {
        int n=b.size();
        bool f=1;
        vector<int> vals;
        vector<int> vis(n*n,0);
        for(int i=n-1;i>=0;i--){
            if(f){
                for(int j=0;j<n;j++){
                    vals.push_back(b[i][j]);
                }
            }
            else{
               for(int j=n-1;j>=0;j--){
                    vals.push_back(b[i][j]);
                }
            }
            f=!f;
        }
        queue<pair<int,int>>q;//posn,dice
        q.push({0,0});
        ///int ans=-1;
        vis[0]=1;
        while(!q.empty()){
            auto t=q.front();q.pop();
            int pos=t.first;int d=t.second;
            //vis[pos]=1;
            if (pos == n * n - 1) return d;
            for(int i=1;i<7;i++){
                int v=pos+i;
                if(v>=n*n)continue;
                int final=(vals[v]==-1)?v:vals[v]-1;
                if (!vis[final]) {
                    vis[final] = true;
                    q.push({final, d + 1});
                }
            }
        }
        return -1;

    }
};
static const int ktkdvshrm = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
