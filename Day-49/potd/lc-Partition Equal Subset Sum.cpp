class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int t=accumulate(nums.begin(), nums.end(), 0);
        if (t%2!=0) return false;
        int target=t/2;
        vector<vector<int>> memo(nums.size(), vector<int>(target+1, -1));
        return fn(0,0,target,nums,memo);
    }
    bool fn(int i,int curr, int tg,vector<int>& nums,vector<vector<int>>& memo){
        if(curr==tg) return true;
        if(i==nums.size() || curr>tg) return false;
        if (memo[i][curr] != -1) return memo[i][curr];
        memo[i][curr]=fn(i+1,curr+nums[i],tg,nums,memo) || fn(i+1,curr,tg,nums,memo);
        return memo[i][curr];
    }
};
