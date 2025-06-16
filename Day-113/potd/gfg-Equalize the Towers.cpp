class Solution {
  public:
    long long getcost(vector<int>&heights,vector<int>&cost,int mid)
    {
        long long totalcost=0;
        for(int i=0;i<heights.size();i++)
        {
            totalcost+=abs(heights[i]-mid)*cost[i];
        }
        return totalcost;
    }
    int minCost(vector<int>& heights, vector<int>& cost) {
        // code here
        int low=*min_element(heights.begin(),heights.end());
        int high=*max_element(heights.begin(),heights.end());
        while(low<high)
        {
            int mid=(low+high)/2;
            long long cost1=getcost(heights,cost,mid);
            long long cost2=getcost(heights,cost,mid+1);
            
            if(cost1>cost2)
            {
                low=mid+1;
            }
            else
            {
                high=mid;
            }
        }
        return getcost(heights,cost,low);
    }
};
