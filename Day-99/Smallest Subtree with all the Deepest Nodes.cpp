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
    TreeNode* res = nullptr;
    int deepestLevel = 0;

    int dfs(TreeNode* root, int height) {
        if (!root) return height;
        int leftHeight = dfs(root->left, height + 1);
        int rightHeight = dfs(root->right, height + 1);
        int currLevel= max(leftHeight, rightHeight);
        if(currLevel>=deepestLevel){
            deepestLevel=currLevel;
            if(leftHeight==deepestLevel && rightHeight==deepestLevel){
                res=root;
            }
            
        }
        
        return max(leftHeight, rightHeight);
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        dfs(root, 0);
        return res;
    }
};
