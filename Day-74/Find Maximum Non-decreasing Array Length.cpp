class Solution {
public:
    int findMaximumLength(vector<int>& nums) {
        int n=nums.size();
        
       vector<long long> pre(n+1);
        for(int i=1;i<=n;i++)
            pre[i]=pre[i-1]+nums[i-1];
        
        vector< pair<int,long long> > dp(n+1);
        for(int i=0;i<=n;i++)
            dp[i]={0,1e18};
        
        dp[0]={0,0};
        for(int i=1;i<=n;i++)
        {
            long long prevSum=dp[i-1].second;
            long long needed=pre[i-1]+prevSum;
            
            int low=i;
            int high=n;
            int where=-1;
            while(low<=high)
            {
                int mid=(low+high)/2;
                
                if(pre[mid]>=needed)
                {
                    where=mid;
                    high=mid-1;
                }
                else
                    low=mid+1;
            }
            if(where!=-1)
            {
                pair<int,long long> p={dp[i-1].first+1,pre[where]-pre[i-1]};
                
                if(dp[where].first < dp[i-1].first+1 )
                    dp[where]=p;
                else if(dp[where].first==dp[i-1].first+1)
                    dp[where].second=std::min(dp[where].second,pre[where]-pre[i-1]);
            }
            
            if(dp[i].first < dp[i-1].first )
                    dp[i]={dp[i-1].first,dp[i-1].second+pre[i]-pre[i-1]};
            else if(dp[i].first==dp[i-1].first)
                 dp[i].second=std::min(dp[i].second,pre[i]-pre[i-1]+dp[i-1].second);
        }

        int ans=0;
        for(auto &[len,su] : dp)
            ans=std::max(ans,len);
        
        return ans;
    }
};
