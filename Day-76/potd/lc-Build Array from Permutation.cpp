class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> v;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            v.push_back(nums[nums[i]]);
        }
        return v;
    }
};
