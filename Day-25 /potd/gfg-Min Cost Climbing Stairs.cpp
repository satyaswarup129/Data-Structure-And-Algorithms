class Solution {
  public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> mincost(n+1);
        mincost[0]=0, mincost[1]=0;
        for(int i=2;i<=n;i++){
            mincost[i]=min(mincost[i-1]+cost[i-1],mincost[i-2]+cost[i-2]);
        }
        return mincost[n];
    }
};
