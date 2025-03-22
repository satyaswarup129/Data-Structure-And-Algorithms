class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        // code here
        int n=arr.size();
        if(n==1) return arr[0];
        arr[1] = max(arr[0], arr[1]);
        for(int i = 1; i<n; i++)
           arr[i] = max(arr[i-1], arr[i]+arr[i-2]);
        
        return arr[n-1];
        
    }
};
