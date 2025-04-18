class Solution {
public:
    string findMaxNum(vector<int>& nums1, vector<int>& nums2, int k, int x, int y, vector<vector<string>>& dp) {
        if (k == 0) return "";
        if (!dp[x][y].empty()) return dp[x][y];
        string res = "";
        int idx1 = x, idx2 = y, upperBound1 = nums2.size() + nums1.size() - y - k, upperBound2 = nums2.size() + nums1.size() - x - k;
        if (upperBound1 > nums1.size() - 1) upperBound1 = nums1.size() - 1;
        if (upperBound2 > nums2.size() - 1) upperBound2 = nums2.size() - 1;
        for (int i = x; i <= upperBound1; ++ i) if (nums1[i] > nums1[idx1]) idx1 = i;
        for (int i = y; i <= upperBound2; ++ i) if (nums2[i] > nums2[idx2]) idx2 = i;
        if (idx1 < nums1.size() && idx2 < nums2.size()) {
            if (nums1[idx1] >= nums2[idx2]) res = to_string(nums1[idx1]) + findMaxNum(nums1, nums2, k - 1, idx1 + 1, y, dp);
            if (nums1[idx1] <= nums2[idx2]) res = max(res, to_string(nums2[idx2]) + findMaxNum(nums1, nums2, k - 1, x, idx2 + 1, dp));
        } 
        else if (idx1 < nums1.size()) res = to_string(nums1[idx1]) + findMaxNum(nums1, nums2, k - 1, idx1 + 1, y, dp);
        else if (idx2 < nums2.size()) res = to_string(nums2[idx2]) + findMaxNum(nums1, nums2, k - 1, x, idx2 + 1, dp);
        dp[x][y] = res;
        return res;

    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<string>> dp(nums1.size() + 1, vector<string>(nums2.size() + 1));
        string maxNum = findMaxNum(nums1, nums2, k, 0, 0, dp);
        vector<int> res;
        for (char c : maxNum) res.push_back(c - '0');
        return res;
    }
};
