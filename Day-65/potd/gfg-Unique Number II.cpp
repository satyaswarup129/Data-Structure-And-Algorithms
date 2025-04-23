class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) 
    {
        int xxory = 0;
        vector<int> ans;
        
        for(int i = 0; i < arr.size(); i++)
        {
            xxory ^= arr[i];
        }
        
        int rsb = xxory & -xxory;
        
        int ans_x = 0, ans_y = 0;
        
        for(auto &it : arr)
        {
            if( (it & rsb) != 0 )
            {
                ans_x ^= it;
            }
            else
            {
                ans_y ^= it;
            }
        }
        
        if(ans_x > ans_y)
        {
            ans.push_back(ans_y); 
            ans.push_back(ans_x);
        }
        else
        {
            ans.push_back(ans_x); 
            ans.push_back(ans_y);
        }
        return ans;
        // Code here.
    }
};
