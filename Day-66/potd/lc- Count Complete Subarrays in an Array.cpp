class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        const int n=nums.size();
        bitset<2001> hasX=0;
        int k=0;
        for(int x: nums){
            if (hasX[x]) continue;
            k++;
            hasX[x]=1;
        }
        int freq[2001]={0}, cnt=0, winCnt=0;
        for(int l=0, r=0; r<n; r++){
            const int x=nums[r];
            if (freq[x]++==0) winCnt++;
            while(l<=r && winCnt==k){
                cnt+=n-r;
                if (--freq[nums[l]]==0) winCnt--;
                l++;
            }
        }
        return cnt;
    }
};
