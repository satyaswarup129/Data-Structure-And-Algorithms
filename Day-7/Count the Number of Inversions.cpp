class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        int MOD=1e9+7,ans=0;
        unordered_map<int,int>mp;
        for(auto iter:requirements)
            mp[1+iter[0]]=iter[1];
        vector<vector<int>>table(n+1,vector<int>(401,0));
        table[0][0]=1;
        for(int i=1;i<= n;++i)
        {
            for (int j=0;j<=400;++j) 
            {
                for (int k=0;k<i;++k) 
                {
                    if (j>=k)
                        table[i][j]=(table[i][j]+table[i-1][j-k])%MOD;
                }
            }
            if (mp.count(i)>0) 
            {
                int temp=mp[i];
                for (int j=0;j<=400;++j) 
                {
                    if (j!=temp)
                        table[i][j]=0;
                }
            }
        }
        for(int i=0;i<=400;++i)
            ans=(ans+table[n][i])%MOD;
        return ans;
    }
};
