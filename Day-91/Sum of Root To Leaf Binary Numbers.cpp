class Solution {
public:
    int sumRootToLeaf(TreeNode* root, int val = 0) {
        if (!root) return 0;
        val = (val * 2 + root->val); 
        return (root->left == root->right ? val : sumRootToLeaf(root->left, val) + sumRootToLeaf(root->right, val));//dfs call
    }
};
