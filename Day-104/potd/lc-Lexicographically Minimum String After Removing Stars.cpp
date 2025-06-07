class Solution {
public:
    struct compare {
        bool operator()(const pair<char, int>& a, const pair<char, int>& b) {
            if (a.first != b.first)
                return a.first > b.first; 
            return a.second < b.second;
        }
    };

    string clearStars(string s) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, compare>
            minHeap;

        int minIndex = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '*') {
                if (!minHeap.empty()) {
                    minIndex = minHeap.top().second;
                    minHeap.pop();
                }
                s[minIndex] = '*';
            } else
                minHeap.push({s[i], i});
        }
        string result = "";
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != '*')
                result += s[i];
        }

        return result;
    }
};
