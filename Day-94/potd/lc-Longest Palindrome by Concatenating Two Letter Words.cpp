class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> freq;
        int res = 0;

        for (string &word : words) {
            string rev = string() + word[1] + word[0];
            if (freq[rev] > 0) {
                res += 4;
                freq[rev]--;
            } else {
                freq[word]++;
            }
        }

        for (auto &[word, count] : freq) {
            if (word[0] == word[1] && count > 0) {
                res += 2;
                break;
            }
        }

        return res;
    }   
};
