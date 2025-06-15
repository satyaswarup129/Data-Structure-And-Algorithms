class Solution {
public:
    int modify(int num, int from, int to) {
        int res = 0, place = 1;
        while (num > 0) {
            int d = num % 10;
            if (d == from) d = to;
            res += d * place;
            place *= 10;
            num /= 10;
        }
        return res;
    }

    int maxDiff(int num) {
        string s = to_string(num);
        int a = num, b = num;

        for (char c : s) {
            if (c != '9') {
                a = modify(num, c - '0', 9);
                break;
            }
        }

        if (s[0] != '1') {
            b = modify(num, s[0] - '0', 1);
        } else {
            for (int i = 1; i < s.size(); ++i) {
                if (s[i] != '0' && s[i] != '1') {
                    b = modify(num, s[i] - '0', 0);
                    break;
                }
            }
        }

        return abs(a - b);
    }
};
