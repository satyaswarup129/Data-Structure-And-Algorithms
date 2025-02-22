#pragma GCC optimize("O3")
class Solution {
public:
    const long long mod=1e9+7;
    int rev(int x){
        int y=0;
        #pragma unroll
        while(x>0){
            int r=x%10;
            y=10*y+r;
            x/=10;
        }
        return y;
    }
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        #pragma unroll
        for(int x:nums){
            int z=x-rev(x);
            if (mp.count(z)==0) mp[z]=1;
            else mp[z]++;
        }
        long long ans=0;
        #pragma unroll
        for(auto& [x, f]: mp){
            if (f>1) ans=(ans+(long long)(f-1)*f/2)%mod;
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
