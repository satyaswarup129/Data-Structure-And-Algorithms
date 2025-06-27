class Solution {
public:
    bool check(const string& sub, const string& s, int k){
        int count = 0, i = 0;
        for (char c : s){
            if (i < sub.size() && c == sub[i]){
                i++;
                if (i == sub.size()){
                    i = 0;
                    count++;
                    if (count == k)
                        return true;
                }
            }
        }
        return false;
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        unordered_map<char, int> freq;
        for (char c : s) 
            freq[c]++;
        vector<char> valid_chars;
        for (char c = 'z'; c >= 'a'; c--)
            if (freq[c] >= k)
                valid_chars.push_back(c);

        int max_len = s.size() / k;
        string res = "";
        queue<string> q;
        q.push("");

        while (!q.empty()) {
            string curr = q.front(); q.pop();
            for (char c : valid_chars) {
                string next = curr + c;
                if (next.length() > max_len) 
                    continue;
                if (check(next, s, k)) {
                    if (next.length() > res.length() || (next.length() == res.length() && next > res))
                        res = next;
                    q.push(next);
                }
            }
        }
        return res;
    }
};
