class Solution {
public:
    bool chk(map<int,int> &mp){
        if(mp.size()==0) return true;
        
        auto firstElement = mp.begin();
        int freq = firstElement->second;
        
        for(auto &[ele, f]: mp){
            if(f != freq) return false;
        }
        return true;
    }
    
    int dp[1001];
    int f(int i, string &s){
        int n = s.size();
        if(i==n) return 0;
        
        if(dp[i]!= -1) return dp[i];
        int ans = n;
        
        map<int,int> mp;
        for(int j=i; j<n; j++){
            mp[s[j]]++;
            
            if(chk(mp)){
                ans = min(ans, 1+ f(j+1, s));
            }
        }
        
        return dp[i] = ans;
    }
    
    int minimumSubstringsInPartition(string s) {
        memset(dp, -1, sizeof(dp));
        return f(0, s);
    }
};
