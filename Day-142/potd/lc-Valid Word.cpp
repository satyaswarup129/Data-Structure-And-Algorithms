class Solution {
public:
    bool isValid(string s) {
        if (s.length()<3) return false;
        int vow=0, con=0;

        for (int i=0; i<s.length(); ++i) {
            if (isupper(s[i]) || islower(s[i])) {
                if (string("AEIOUaeiou").find(s[i]) != string::npos) ++vow;
                else ++con;
            }
            else if (s[i]-'0' >= 0 && s[i]-'0' <= 9) continue;
            else return false;
        }
        if (vow>0 && con>0) return true;
        return false;
    }
};
