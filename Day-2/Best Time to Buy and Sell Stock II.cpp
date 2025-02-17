class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if( prices.size() == 1)
        {
            return 0; 
        }
       
    int ans = 0;
    int startdayprice = prices[0];
    int index = 0;
    while(index < prices.size())
        {
            int profitgot = 0;
            while(index < prices.size() - 1 && prices[index] <= prices[index+1] )
            {
                index++;
            }
            if( index < prices.size()  )
            {
        
            profitgot = prices[index] - startdayprice;
            if( index < prices.size() - 1)
            {
            startdayprice = prices[index + 1];
            }
            index++;
            ans = ans + profitgot;
            }
            
        }
        return ans;
        }
};
