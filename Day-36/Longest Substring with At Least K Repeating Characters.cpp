class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        unordered_map <char, int> freq;

        //count the frequency of each char in the string 's'
        for (char c : s) {
            freq[c]++;
        }

        // find the first char with freq < k
        int i = 0;
        while (i < n && freq[s[i]] >= k) {
            i++;
        }

        // base case - whole string has valid frequencies
        if (i == n) return n;

        // recursively search for valid substrings in between invalid characters
        int left = longestSubstring(s.substr(0, i), k);

        while (i < n && freq[s[i]] < k) {
            i++;
        }

        int right = (i < n) ? longestSubstring(s.substr(i), k) : 0;

        return max(left, right);
    }
};
