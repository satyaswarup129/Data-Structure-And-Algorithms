class Solution {
  public:
    int findDuplicate(vector<int>& arr) {
        unordered_map<int,bool> mp;
        for(int num:arr){
            if(mp[num]) return num;
            mp[num]=true;
        }
        return -1;
    }
};
