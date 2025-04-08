
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>s;
        int i;
        for(i=n-1;i>=0;i--){
            if(s.find(nums[i])!=s.end()) break;
            s.insert(nums[i]);
        }
        if((i+1)%3==0) return (i+1)/3;
        return (i+1)/3 +1;
    }
};   
