class Solution {
public:
    int ans = 0;
    int longestUnivaluePath(TreeNode* root) {
        findPath(root,INT_MIN);
        return ans;
    }
    
    int findPath(TreeNode* root, int par){
        if(!root)
            return 0;
        
        int l = findPath(root->left, root->val);
        int r = findPath(root->right, root->val);
        ans = max(ans,r + l);
        
        if(par == root->val)
            return max(r,l) + 1;
        return 0;
    }
};
