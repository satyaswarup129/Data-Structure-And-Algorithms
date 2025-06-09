class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
    
    if(!root) return root;
    
    root->left = pruneTree(root->left);      
    root->right = pruneTree(root->right);
    
    if(root->val == 0 && !root->left && !root->right){    
        return NULL;                                      
    }                                                     
    return root;
}
};
