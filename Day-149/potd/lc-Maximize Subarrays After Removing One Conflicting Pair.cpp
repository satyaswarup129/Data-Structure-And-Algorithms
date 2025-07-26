class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        vector<vector<int>> v(n+1);
        for(auto c : conflictingPairs){
            int a = min(c[0],c[1]), b = max(c[0], c[1]);
            v[b].push_back(a);
        }

        long long ans = 0, top1=0, top2=0;
        vector<long long> bonus(n+1, 0);
        for(int i =1; i<=n; i++){
            for(auto a : v[i]){
                if(a>top1){
                    top2 = top1;
                    top1 = a;
                }else if(a>top2){
                    top2 = a;
                }
            }
            ans += (i-top1);
            if(top1){
                bonus[top1] += (top1-top2);
            }

        }
        return ans + *max_element(bonus.begin(), bonus.end());
        
    }
};
