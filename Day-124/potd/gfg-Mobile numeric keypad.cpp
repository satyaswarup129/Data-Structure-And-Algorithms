class Solution {
  public:
    int fun(int i, int j, int n, char mat[4][3], vector<vector<vector<int>>> &dp){
        if(i<0 || i>3 || j<0 || j>2)
            return 0;
        if(mat[i][j]=='*' || mat[i][j]=='#')
            return 0;
        
        if(n==1)
            return 1;
        
        if(dp[i][j][n]!=-1)
            return dp[i][j][n];
        
        
        return dp[i][j][n] = fun(i, j, n-1, mat, dp) + fun(i-1, j, n-1, mat, dp) + fun(i, j+1, n-1, mat, dp) + fun(i+1, j, n-1, mat, dp) + fun(i, j-1, n-1, mat, dp);
        
        
        
    }
  
  
    int getCount(int n) {
        // code here
        char mat[4][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}, {'*', '0', '#'}};
        int ans = 0;
        
        vector<vector<vector<int>>> dp(4, vector<vector<int>>(3, vector<int>(n+1, -1)));
        
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                if(mat[i][j]!='*' && mat[i][j]!='#')
                    ans += fun(i, j, n, mat, dp);
            }
        }
        
        return ans;
    }
};
