class Solution {
    int find(TreeNode* root,int& maxi){
        if(root==NULL) return 0;
        int right=max(0,find(root->right,maxi));
        int left=max(0,find(root->left,maxi));
        maxi=max(maxi,left+right+(root->val));
        return max(left,right)+(root->val);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        find(root,maxi);
        return maxi;
    }
};
