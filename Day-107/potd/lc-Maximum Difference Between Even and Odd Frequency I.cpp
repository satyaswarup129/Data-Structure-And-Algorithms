class Solution {
public:
    int maxDifference(string s) {
        int n = s.size();
        vector<int> hash(26, 0);
        for (char& ch : s) {
            hash[ch - 'a']++;
        }
        int odd = 0;
        int even = INT_MAX;
        for (int i = 0; i < hash.size(); i++) {
            if (hash[i] % 2 == 0 && hash[i] != 0) {
                even = min(even, hash[i]);
            } else {
                odd = max(odd, hash[i]);
            }
        }

        return (odd - even);
    }
};
