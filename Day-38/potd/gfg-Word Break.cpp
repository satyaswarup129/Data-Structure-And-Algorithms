class Solution {
  public:
    bool helper(int i,string s,set<string>st,vector<int> &dp){
        if(i == s.length()){
            return true;
        }
        if(dp[i] != -1)
            return dp[i];
            
        string temp ="";
        for(int j=i; j<s.length(); j++){
            temp += s[j];
            if(st.find(temp) != st.end()){
                if(helper(j+1,s,st,dp)){
                    return dp[i] = true;
                }
            }
        }
        return dp[i] = false;
    }

    int wordBreak(string s, vector<string> &dictionary) {
        vector<int> dp(s.size(),-1);
        set<string>st(dictionary.begin(),dictionary.end());
        
        return helper(0,s,st,dp);
    }
};
