class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi=0;
        int mini=INT_MAX;

        for(auto x : prices){
            mini=min(mini,x);
            maxi=max(x-mini,maxi);
        }

        return maxi;
    }
};
