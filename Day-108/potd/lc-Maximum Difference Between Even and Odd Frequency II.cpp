class Solution {
public:
    int maxDifference(string s, int k) {
        int n = s.size(), ans = INT_MIN;
        auto getStatus = [](int ca, int cb) {
            return ((ca & 1) << 1) | (cb & 1);
        };

        for (char a = '0'; a <= '4'; ++a) {
            for (char b = '0'; b <= '4'; ++b) {
                if (a == b) continue;
                int best[4] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX};
                int cnt_a = 0, cnt_b = 0, prev_a = 0, prev_b = 0;
                int left = -1;
                for (int right = 0; right < n; ++right) {
                    cnt_a += (s[right] == a);
                    cnt_b += (s[right] == b);

                    while (right - left >= k && cnt_b - prev_b >= 2) {
                        int st = getStatus(prev_a, prev_b);
                        best[st] = min(best[st], prev_a - prev_b);
                        ++left;
                        prev_a += (s[left] == a);
                        prev_b += (s[left] == b);
                    }
                    int st_now = getStatus(cnt_a, cnt_b);
                    if (best[st_now ^ 2] != INT_MAX) {
                        ans = max(ans, cnt_a - cnt_b - best[st_now ^ 2]);
                    }
                }
            }
        }
        return ans == INT_MIN ? -1 : ans;
    }
};
