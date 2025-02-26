class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxi = 0, mini = 0, l = 0, n = nums.size(), cnt = 0;
        for (int r = 0; r < n; r++) {
            cnt += nums[r];
            while (cnt < 0) cnt -= nums[l++];
            maxi = max(maxi, cnt);
        }
        l = cnt = 0;
        for (int r = 0; r < n; r++) {
            cnt -= nums[r];
            while (cnt < 0) cnt += nums[l++];
            mini = max(mini, cnt);
        }
        return max(mini, maxi);
    }
};
