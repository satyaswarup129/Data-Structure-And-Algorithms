class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int dif = -1;
        int val = nums[nums.size()-1];
        for(int i = nums.size()-2;i>=0;i--){
            if(nums[i] >= val) val = nums[i];
            else{
                dif = max(dif, val - nums[i]);
            } 
        }
        return dif;
    }
};
