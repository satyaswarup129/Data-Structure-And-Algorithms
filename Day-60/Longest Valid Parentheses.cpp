class Solution {
public:
    int longestValidParentheses(string s) {
        
        vector<int>dp(s.length()+1,0);

        for(int i=0;i<s.length();i++)
        {
            if(s[i]==')')
            {
                if(i-1>=0 && s[i-1]=='(')
                {
                    if(i-2>=0)
                    dp[i]=dp[i-2]+2;
                    else
                    dp[i]=2;
                }
                else if(i-1>=0)
                {
                    int open=i-dp[i-1]-1;
                    if(open>=0 && s[open]=='(')
                    {
                        if(open-1>=0)
                        dp[i]=dp[i-1]+2+dp[open-1];
                        else
                        dp[i]=dp[i-1]+2;
                    }
                }
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<dp.size();i++)
        {
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};
