class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>arr(n+1,0);
        for(auto it:queries){
            arr[it[0]] = arr[it[0]] -1;
            arr[it[1]+1] = arr[it[1]+1] + 1;
        }

        vector<int>arr1(n+1,0);
        arr1[0] = arr[0];
        for(int i =1;i<arr.size();i++){
            arr1[i] = arr1[i-1] + arr[i];
        }

        for(int i =0;i<nums.size();i++){
            if(nums[i]+arr1[i]>0){
                return false;
            }
        }

return true;
    }
};
