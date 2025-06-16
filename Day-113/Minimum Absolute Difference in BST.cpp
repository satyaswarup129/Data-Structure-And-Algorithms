class Solution {
public:
void solve(TreeNode* root,int& s,int & mn){
    if(!root) return;
    solve(root->left,s,mn);
    if(s!=-1){
        mn=min(mn,abs(root->val-s)); 
    }
    s=root->val;
    solve(root->right,s,mn);
}
    int getMinimumDifference(TreeNode* root) {
        int mn=INT_MAX;
        int s=-1;
        solve(root,s,mn);
        return mn;
    }
};
