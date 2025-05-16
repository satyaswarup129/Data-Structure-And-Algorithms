class Solution {
public:
    bool checkHamming(string &s1,string &s2){
        if(s1.length()!=s2.length()) return false;
        bool flag=true;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i] && !flag) return false;
            if(s1[i]!=s2[i]) flag=false;
        }
        return true;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n=words.size();
        vector<int>dp(n,1);
        vector<int>parent(n,-1);
        int longestSubSq=1;
        int longestSubSqIdx=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(groups[i]!=groups[j] && checkHamming(words[i],words[j])){
                    if(dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;
                        parent[i]=j;
                        if(longestSubSq<dp[i]){
                            longestSubSq=dp[i];
                            longestSubSqIdx=i;
                        }
                    }
                }
            }
        }
        vector<string>ans;
        while(longestSubSqIdx!=-1){
            ans.push_back(words[longestSubSqIdx]);
            longestSubSqIdx=parent[longestSubSqIdx];
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};
