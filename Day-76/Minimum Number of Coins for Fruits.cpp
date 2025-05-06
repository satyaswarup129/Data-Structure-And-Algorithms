class Solution {
public:
    int dp[1001][1001];
    int solve(int s,vector<int>&v,int pow)
    {   
        int n=v.size();
        if(s>=n)
            return 0;
        if(dp[s][pow]!=-1)
            return dp[s][pow];
        if(pow==0)
        {
            return v[s]+solve(s+1,v,s+1);
        }
        int ans=solve(s+pow,v,0);
        for(int i=s;i<=min(n-1,s+pow-1);i++)
        {
            ans=min(ans,v[i]+solve(i+1,v,i+1));
        }
        return dp[s][pow]=ans;
    }
    int minimumCoins(vector<int>& v) {
        int n=v.size();
        memset(dp,-1,sizeof(dp));
        int ans=solve(0,v,0);
        return ans;
    }
};
