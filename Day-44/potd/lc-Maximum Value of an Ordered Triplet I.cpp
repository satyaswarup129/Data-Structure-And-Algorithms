class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
       long long maxprefix =nums[0];
       long long diff =LLONG_MIN;
      long long maxtriplets =0;
      for(int i =1; i<n-1; i++){
        maxprefix  = max(maxprefix, (long long)nums[i-1]);
        diff  = max(diff,maxprefix-nums[i]);
        maxtriplets = max(maxtriplets,diff*nums[i+1]);

      }
      return maxtriplets;
    }
};
