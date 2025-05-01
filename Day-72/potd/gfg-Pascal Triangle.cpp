class Solution {
  public:
     vector<int> nthRowOfPascalTriangle(int n) {
        // code here
        vector<int>prev={1};
        if(n==1)
        return prev;
        
        for(int i=2;i<=n;i++)
        {
            vector<int>ans;
            ans.resize(i);
            ans[0]=1,ans[i-1]=1;
            for(int j=1;j<i-1;j++)
            {
                ans[j]=prev[j-1]+prev[j];
            }
            prev=ans;
        }
        return prev;
    }
};
