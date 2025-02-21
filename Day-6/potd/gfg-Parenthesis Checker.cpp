class Solution {
  public:
    bool isBalanced(string s)
    {
        stack <char> S;
        int n = s.length();
        for(int i = 0; i < n; i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') S.push(s[i]);
            else {
                if(S.empty()) return false;
                if ((s[i] == ')' && S.top() != '(') ||
                (s[i] == '}' && S.top() != '{') ||
                (s[i] == ']' && S.top() != '[')) {
                return false;
            }
            S.pop();
            }
        }
        if(S.empty()) return true;
        return false;
    }
};
