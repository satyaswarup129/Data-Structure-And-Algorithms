class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int count=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                count++;
                i++;
            }
        }
        if(count*2==nums.size())
           return true;
        return false;
    }
};
