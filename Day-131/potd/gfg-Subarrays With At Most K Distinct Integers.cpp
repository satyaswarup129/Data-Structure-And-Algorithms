class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        map<int, int> mp;
        int st=0;
        int end=0;
        int total=0;
        while(end< arr.size()){
            mp[arr[end]]++;
            while(mp.size()>k){
                mp[arr[st]]--;
                if(mp[arr[st]]==0){
                    mp.erase(arr[st]);
                }
                st++;
            }
            total= total+ (end-st+1);
            end++;
        }
        return total;
    }
};
