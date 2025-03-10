class Solution {
  public:
    int dp[1005][1005];
    int fn(string& s1, string& s2, int i , int j){
        if(j==s2.size())return s1.size()-i;
        if(i==s1.size())return s2.size()-j;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=1e5;
        if(s1[i]==s2[j])ans=min(ans,fn(s1,s2,i+1,j+1));
        ans=min(ans,fn(s1,s2,i+1,j)+1);
        ans=min(ans,fn(s1,s2,i,j+1)+1);
        ans=min(ans,fn(s1,s2,i+1,j+1)+1);
        return dp[i][j]=ans;
    }
    int editDistance(string& s1, string& s2) {
        memset(dp,-1,sizeof(dp));
       return fn(s1,s2,0,0);
    }
};
