class Solution {
public:
    
    int solve(string s, vector<int> freq, int max_f, map<string,int> &mp){
        if(s.length() == 0) return 0;
        
        if(mp.find(s) != mp.end()) return mp[s];
        
        int ans = INT_MAX/2;
        for(int i=0;i<s.length();i++){
            int idx = s[i]-'a';
            freq[idx]++;
            
            if(freq[idx] > max_f) max_f = freq[idx];
            
			// check if frequencies of all chars in partition are same or not
            bool possible = true; 
            for(int i=0;i<26;i++){
                if(freq[i]>0 && freq[i] != max_f){
                    possible = false;
                    break;
                }
            }
            
            if(possible){
                vector<int> sub(26, 0);
                ans = min(ans, 1 + solve(s.substr(i+1), sub, -1, mp));
            }
        }
        
        return mp[s]=ans;
    }
    
    int minimumSubstringsInPartition(string s) {
        vector<int> freq(26, 0);
        
        map<string,int> mp;
        
        int ans = solve(s, freq, -1, mp);
        
        return (ans >= INT_MAX/2 ? 0:ans);
    }
};
