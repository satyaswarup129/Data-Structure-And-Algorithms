class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        int size = nums.size();

        // Prefix: smallest n elements from the first 2n elements
        priority_queue<int> maxHeap;
        vector<long long> prefixSum(size, 0);
        long long sum = 0;

        for (int i = 0; i < size; ++i) {
            maxHeap.push(nums[i]);
            sum += nums[i];
            if (maxHeap.size() > n) {
                sum -= maxHeap.top();
                maxHeap.pop();
            }
            if (i >= n - 1)
                prefixSum[i] = sum;
        }

        // Suffix: largest n elements from the last 2n elements
        priority_queue<int, vector<int>, greater<int>> minHeap;
        vector<long long> suffixSum(size, 0);
        sum = 0;

        for (int i = size - 1; i >= 0; --i) {
            minHeap.push(nums[i]);
            sum += nums[i];
            if (minHeap.size() > n) {
                sum -= minHeap.top();
                minHeap.pop();
            }
            if (i <= size - n)
                suffixSum[i] = sum;
        }

        long long result = LLONG_MAX;
        // Compare prefix of first 2n and suffix of last 2n
        for (int i = n - 1; i < 2 * n; ++i) {
            result = min(result, prefixSum[i] - suffixSum[i + 1]);
        }

        return result;
    }
};
