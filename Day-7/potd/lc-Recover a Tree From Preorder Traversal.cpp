
class Solution {
private:
    int getDepth(const string &s, int &i) {
        int depth = 0;
        while (i < s.size() && s[i] == '-') {
            depth++;
            i++;
        }
        return depth;
    }

    int getNumber(const string &s, int &i) {
        int num = 0;
        while (i < s.size() && isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
            i++;
        }
        return num;
    }

public:
    TreeNode* recoverFromPreorder(string s) {
        int i = 0;
        stack<pair<TreeNode*, int>> stk;

        while (i < s.size()) {
            int depth = getDepth(s, i);
            int num = getNumber(s, i);
            TreeNode* node = new TreeNode(num);

            while (!stk.empty() && stk.top().second >= depth) {
                stk.pop();
            }

            if (!stk.empty()) {
                if (!stk.top().first->left) {
                    stk.top().first->left = node;
                } else {
                    stk.top().first->right = node;
                }
            }

            stk.push({node, depth});
        }

        while (stk.size() > 1) stk.pop();
        return stk.top().first;
    }
};
