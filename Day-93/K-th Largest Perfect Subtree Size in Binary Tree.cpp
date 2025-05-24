/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
        int kthLargestPerfectSubtree(TreeNode* root, int k) {
        vector<int> res;

        function<int(TreeNode*)> dfs = [&](TreeNode* root) -> int {
            if (!root) return 0;
            int l = dfs(root->left), r = dfs(root->right);
            if (l == r && l >= 0) {
                res.push_back(l + 1);
                return l + 1;
            }
            return -1;
        };

        dfs(root);
        nth_element(res.begin(), res.end() - k, res.end());
        if (k <= res.size()) {
            return (1 << res[res.size() - k]) - 1;
        }
        return -1;
    }
};
