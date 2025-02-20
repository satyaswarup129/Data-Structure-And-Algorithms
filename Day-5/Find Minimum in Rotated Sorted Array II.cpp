class Solution {
public:
    int findMin(vector<int>& nums) {

    int minVal = nums[0];
        for (int num : nums) {
            if (num < minVal) {
                minVal = num;
            }
        }
        return minVal;


    }
};
