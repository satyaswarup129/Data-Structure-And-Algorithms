class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int val=nums[0];
       int total=0;

       for(int n:nums){
        if(total<0){
            total=0;
        }

        total+=n;
        val=max(val, total);
       } 
       return val;
    }
};
