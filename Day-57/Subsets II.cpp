class Solution {
public:
    void solve(vector<int>& nums, int i, vector<int>o, vector<vector<int>>& ans){
        if (i>=nums.size()){ans.push_back(o);return;}
        solve(nums,i+1,o,ans);
        o.push_back(nums[i]);
        solve(nums,i+1,o,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>o;
        solve(nums,0,o,ans);
        for (int i=0;i<ans.size();i++){
            sort(ans[i].begin(),ans[i].end());
        }
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans; 
    }
};
