#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int M=*max_element(nums.begin(), nums.end());
        int n=nums.size(), cnt=0;
        long long ans=0;
        for(int l=0, r=0; r<n; r++){
            cnt+=(nums[r]==M);
            while(cnt>=k){
                cnt-=(nums[l++]==M);
            }
            ans+=l;
        }
        return ans;
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
