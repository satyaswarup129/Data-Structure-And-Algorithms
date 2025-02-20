int a[100000];

int init = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ofstream out("user.out");
    for (string s; getline(cin, s); out << '\n') {
        if (s.length() == 2) {
            out << 0;
            continue;
        }
        int n = 0;
        for (int _i = 1, _n = s.length(); _i < _n; ++_i) {
            bool _neg = false;
            if (s[_i] == '-') ++_i, _neg = true;
            int v = s[_i++] & 15;
            while ((s[_i] & 15) < 10) v = v * 10 + (s[_i++] & 15);
            if (_neg) v = -v;
            a[n++] = v;
        }
        sort(a, a + n);
        int ans = 0;
        for (int i = 0; i < n;) {
            int i0 = i;
            for (++i; i < n && a[i - 1] + 1 >= a[i]; ++i);
            ans = max(ans, a[i - 1] - a[i0] + 1);
        }
        out << ans;
    }
    out.flush();
    exit(0);
    return 0;
}();

class Solution {
public:
    int longestConsecutive(vector<int>) { return 999; }
};
