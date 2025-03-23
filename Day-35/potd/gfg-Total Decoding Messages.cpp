class Solution {
  public:
    int solve(int i, int n, string &digits, vector<int>&dp){
        if(i>=n) return 1;
        if(dp[i]!=-1) return dp[i];
        
        if(digits[i]=='0') return 0;
        
        int take2=0;
        int take1=solve(i+1, n, digits, dp);
        if(i+1<n && stoi(digits.substr(i, 2))<=26){
            take2=solve(i+2, n, digits, dp);
        } 
        return dp[i]=take1+take2;
    }
  
    int countWays(string &digits) {
        // Code here
        int n=digits.size();
        vector<int>dp(n, -1);
        return solve(0, n, digits, dp);
    }
};
