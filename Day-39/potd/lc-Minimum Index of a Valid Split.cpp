class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int dom = nums[0], freq = 1;
        for(int i=1; i<n; i++){
            if(nums[i] == dom) freq++;
            else {
                if(--freq == 0){
                    dom = nums[i];
                    freq = 1;
                }
            }
        }
        
        int lf = 0;
        for(auto it: nums){
            lf += (it == dom);
        }

        int sf = 0;
        for(int i=0; i<n-1; i++){
            if(nums[i] == dom){
                sf++;
                lf--;
            }
            if(sf > (i+1)/2 && lf > (n-i-1)/2) return i;
        }

        return -1;
    }
};
