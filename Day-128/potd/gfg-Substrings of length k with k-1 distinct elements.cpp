class Solution {
  public:
  int frequency(vector<int>&mp){
      int freq=0;
      for(int i=0;i<26;i++){
          if(mp[i]!=0)freq++;
      }
      return freq;
  }
    int substrCount(string &s, int k) {
        // code here
        int n=s.size();
        vector<int>mp(26,0);
        int count=0;
        int i=0,j=0;
        while(j<n){
            mp[s[j]-'a']++;
            if(j-i+1>k){
                mp[s[i]-'a']--;
                i++;
            }
            if(j-i+1==k && frequency(mp)==k-1)count++;
            j++;
        }
        return count;
    }
}; 
