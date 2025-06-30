class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int>mp;

        int ans=0;

        for(int &i:nums) mp[i]++;

        for(int &num:nums){
            int minNum=num;
            int maxNum=num+1;

            if(mp.count(maxNum)){
                ans=max(ans,mp[minNum]+mp[maxNum]);
            }
        }
        return ans;
    }
};
