class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<long long> gaps(n + 1);
        gaps[0] = startTime[0];
        gaps[n] = eventTime - endTime[n - 1];

        for(int i = 1; i < n; ++i){
            gaps[i] = startTime[i] - endTime[i - 1];
        }

        vector<long long> pref(n + 2, 0);
        for(int i = 1; i <= n + 1; ++i){
            pref[i] = pref[i - 1] + gaps[i - 1];
        }

        long long maxFreeTime = 0;
        for(int i = k + 1; i <= n + 1; ++i){
            maxFreeTime = max(maxFreeTime, pref[i] - pref[i - (k + 1)]);
        }

        return int(maxFreeTime);
    }
};
