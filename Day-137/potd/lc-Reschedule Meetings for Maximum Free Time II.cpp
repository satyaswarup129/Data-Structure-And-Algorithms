class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        int preMax = 0, suffMax = 0, ans = 0;

        for(int i = 0; i < n; i++) {
            int last = (i == 0) ? startTime[i] : startTime[i] - endTime[i-1];
            int next = (i == n-1) ? eventTime - endTime[i] : startTime[i+1] - endTime[i];
            int currGap = last + next, block = endTime[i] - startTime[i];

            if(preMax >= block) currGap += block;
            ans = max(ans, currGap);
            preMax = max(preMax, last);
        }

        for(int i = n-1; i >= 0; i--) {
            int last = (i == 0) ? startTime[i] : startTime[i] - endTime[i-1];
            int next = (i == n-1) ? eventTime - endTime[i] : startTime[i+1] - endTime[i];
            int currGap = last + next, block = endTime[i] - startTime[i];

            if(suffMax >= block) currGap += block;
            ans = max(ans, currGap);
            suffMax = max(suffMax, next);
        }
        return ans;
    }
};
