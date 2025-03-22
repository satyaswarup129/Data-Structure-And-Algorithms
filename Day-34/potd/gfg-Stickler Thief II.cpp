class Solution {
    int solve(int idx, vector<int>& arr){
        int n = arr.size();
        int prev2 = 0, prev1 = arr[idx];
        
        for(int i = idx+1; i < n; ++i){
            int curr = max(arr[i]+prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
  public:
    int maxValue(vector<int>& arr) {
        // your code here
        int includeLastHouse = solve(1, arr);
        arr.pop_back();
        int includeFirstHouse = solve(0, arr);
        return max(includeFirstHouse, includeLastHouse);
    }
};
