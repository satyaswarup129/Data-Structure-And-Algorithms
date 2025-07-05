class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
        int n = arr.size();
        int ans = -1;
        for (int i = 1; i < n; i++) {
            int temp = arr[i] + arr[i - 1];
            ans = fmax(ans, temp);
        }
        return ans;
    }
};
