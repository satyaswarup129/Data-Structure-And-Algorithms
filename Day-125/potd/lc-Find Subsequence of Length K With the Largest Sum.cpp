class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>> pq;

        for(int i = 0; i < n ; i++) pq.emplace(nums[i], i);
        
        vector<pair<int,int>> v;
        while(k--)
        {
            auto [num, idx] = pq.top();
            pq.pop();
            v.emplace_back(idx, num);
        }

        sort(v.begin(), v.end());

        vector<int> res;
        for(auto [idx, num] : v) res.push_back(num);
        
        return res;
    }
};
