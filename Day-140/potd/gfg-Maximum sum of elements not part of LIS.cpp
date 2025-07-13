class Solution {
  public:
    int nonLisMaxSum(vector<int>& arr) {
        int n=arr.size();
        vector<int>LIS;
        int sum=0;
        vector<int>liSum(n+1,0);
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            int idx=lower_bound(LIS.begin(),LIS.end(),arr[i])-LIS.begin();
            if(idx==LIS.size())
            LIS.push_back(arr[i]);
            else
            LIS[idx]=arr[i];
            liSum[idx+1]=liSum[idx]+arr[i];
        }
        return sum-liSum[LIS.size()];
    }
};
