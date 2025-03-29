class Solution {
public:
    bool isAnagram(const string& s1, const string& s2) {
        if (s1.length() != s2.length()) {
            return false;
        }

        unordered_map<char, int> count1, count2;

        for (char c : s1) {
            count1[c]++;
        }

        for (char c : s2) {
            count2[c]++;
        }

        return count1 == count2;
    }
    
    bool allNonOverlappingSubstringsAreAnagrams(const string& s, int K) {
        string first_sub = s.substr(0, K);

        for (int i = 0; i < s.length(); i += K) {
            string current_sub = s.substr(i, K);
            if (!isAnagram(first_sub, current_sub)) {
                return false;
            }
        }

        return true;
    }
    
    int minAnagramLength(string s) {
        int n = s.size();
        int mini = n; 
        for(int i = 1; i * i <= n; i++) {
            if(n % i == 0) {
                if(n % i == i) {
                    if(allNonOverlappingSubstringsAreAnagrams(s, i))
                        mini = min(mini, i);
                } else {
                    if(allNonOverlappingSubstringsAreAnagrams(s, i))
                        mini = min(mini, i);
                    if(allNonOverlappingSubstringsAreAnagrams(s, n / i))
                        mini = min(mini, n / i);
                }
            }
        }
        return mini;
    }
};
