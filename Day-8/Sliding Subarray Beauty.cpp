class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n=nums.size();
        map<int,int>mp;
        for(int i=0;i<k;++i){
            mp[nums[i]]++;
        } 
        
        vector<int>ans;
        int j=0;
        for(int i=k;i<=n;++i){
            int cnt=0;
            for(auto m:mp){
                if(m.first<=0){
                    if(m.second>0) cnt+=m.second;
                    if(cnt>=x){
                        ans.push_back(m.first);
                        break;
                    }
                }
            }
            if(cnt<x) ans.push_back(0);
            if(i==n) break;
            mp[nums[i]]++;
            mp[nums[j]]--;
            j++;
        }
        return ans;
    }
};
