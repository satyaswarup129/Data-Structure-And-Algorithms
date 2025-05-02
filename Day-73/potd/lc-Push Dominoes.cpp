class Solution {
public:
    static string pushDominoes(string& s) {
        const int n = s.size();
        char* const ch = s.data();
        char p = '.';
        int j = 0;
        for (int i = 0; i < n; ++i) {
            const char ai = s[i];
            if (ai == 'R') {
                if (p == 'R') fill(ch + j, ch + i, 'R');
                p = 'R';
                j = i;
            } else if (ai == 'L') {
                if (p == '.') {
                    fill(ch + j, ch + i + 1, 'L');
                } else {
                    const int h = (i - j + 1) >> 1;
                    fill(ch + j, ch + j + h, 'R');
                    fill(ch + i - h + 1, ch + i + 1, 'L');
                }
                j = i + 1;
                p = '.';
            }
        }
        if (p == 'R') fill(ch + j, ch + n, 'R');
        return s;
    }
};
