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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        bool isUsed[31] = {0};
        int premp[31], posmp[31];

        for(int i = 0; i < n; i++) {
            premp[preorder[i]] = i;
            posmp[postorder[i]] = i;
        }

        isUsed[preorder[0]] = 1;
        TreeNode *root = new TreeNode(preorder[0]);
        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            int left_idx = premp[curr->val] + 1, right_idx = posmp[curr->val] - 1;
            if(left_idx < n && right_idx >= 0) {
                int left_val = preorder[left_idx];
                int right_val = postorder[right_idx];
                if(isUsed[left_val] || isUsed[right_val]) continue;
                if(left_val == right_val) {
                    curr->left = new TreeNode(left_val);
                    q.push(curr->left);
                } else {
                    curr->left = new TreeNode(left_val);
                    curr->right = new TreeNode(right_val);
                    q.push(curr->left);
                    q.push(curr->right);
                }
                isUsed[left_val] = isUsed[right_val] = 1;
            }
        }
        return root;
    }
};
