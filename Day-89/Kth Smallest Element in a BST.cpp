class Solution {
public:
    int count = 0;
    int ans = -1;
    void dfs (TreeNode* root, int &k){
        if(!root) return;
        
        if(root->left) dfs(root->left,k);
        count++;
        if(count == k){
            ans = root->val;
            return;
        }
        if(root->right) dfs(root->right, k);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return ans;
    }
};
