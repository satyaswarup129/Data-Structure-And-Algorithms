class Solution {
  public:
    int countSubstring(string &s) {
        // code here
        unordered_map<char,int>mp;
        int n = s.length();
        int cnt = 0;
        for(int i = 0; i<n ; i++){
            char ch = s[i];
            mp[ch]++;
            cnt+=mp[ch];
        }
        return cnt;
    }
};
