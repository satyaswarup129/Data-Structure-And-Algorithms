class Solution {
  public:
    int countValid(int n, vector<int>& arr) {
        // code here
        int k=0;
        for(int i:arr) k+=(i!=0);
        return 9*pow(10,n-1)-(9-k)*pow(10-arr.size(),n-1);
    }
};
