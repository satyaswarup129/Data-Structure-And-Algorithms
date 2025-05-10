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
    
    int solve(TreeNode* node, bool &isBalancedTree){
        if(node == NULL || isBalancedTree == false)
            return 0;
        int lh = solve(node->left, isBalancedTree);
        int rh = solve(node->right, isBalancedTree);
        if(abs(lh - rh) > 1){
            isBalancedTree = false;
        }
        return 1 + max(lh, rh);
    }
    
    
    bool isBalanced(TreeNode* root) {
        bool isBalancedTree = true;
        solve(root, isBalancedTree);
        return isBalancedTree;
    }
};
