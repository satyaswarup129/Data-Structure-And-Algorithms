class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int zeroes1=0, zeroes2 = 0;
        long long currSum1 = 0, currSum2 = 0;
        for(int &num : nums1) {
            currSum1 += num;
            if(num == 0) zeroes1++;
        }
        for(int &num : nums2) {
            currSum2 += num;
            if(num == 0) zeroes2++;
        }
        /*There can be a few cases:
        1. If there are no zeroes in either array:
            then if sum is equal then return or return -1.
        2. If one array has zeroes, other doesn't: say arr1 has 0s
            if sum of arr1 + num of zeroes in it is <= sum of arr2, then possible
        3. If both arrays have zeroes then it is always possible and then find sum
        */
        if(zeroes1 == 0 && zeroes2 == 0) {
            return currSum1 == currSum2? currSum1 : -1;
        }
        if(zeroes2 == 0) {
            //arr1 has 0s
            return currSum1 + zeroes1 <= currSum2? currSum2 : -1; 
        }
        else if(zeroes1 == 0) {
            //arr2 has 0s
            return currSum2 + zeroes2 <= currSum1? currSum1 : -1;
        }
        else {
            //both arrays has 0s
            return max(currSum1 + zeroes1, currSum2 + zeroes2);
        }
    }
};
