class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        int n = nums.size();
        vector<int> ans;

        for(int i = 0; i < k; i++) {
            pq.push({nums[i], i});
        }

        ans.push_back(pq.top().first);

        for(int i = k; i < n; i++) {
            pq.push({nums[i], i});

            while(pq.top().second < i+1-k) {
                pq.pop();
            }

            ans.push_back(pq.top().first);
        }

        return ans;
    }
};
