class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }

        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 1; i <= size; i++) {
                TreeNode* top = q.front();
                q.pop();

                if (i == size) {
                    ans.push_back(top->val);
                }

                if (top->left) {
                    q.push(top->left);
                }

                if (top->right) {
                    q.push(top->right);
                }
            }
        }

        return ans;
    }
};
