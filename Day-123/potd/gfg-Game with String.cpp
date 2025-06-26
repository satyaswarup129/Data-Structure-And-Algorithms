class Solution {
  public:
     int minValue(string &s, int k) {
        // code here
        unordered_map<char,int> mp;
        
        for(auto i:s) mp[i]++;
        
        vector<int> arr;
        
        for(auto i:mp) arr.push_back(i.second);
        
        while(k--){
            sort(arr.begin(),arr.end());
            arr[arr.size()-1]--;
        }
        int sum=0;
        for(auto i:arr){
            sum+= i*i;
        }
        return sum;
    }
};
