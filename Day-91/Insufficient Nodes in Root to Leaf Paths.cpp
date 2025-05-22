class Solution {
    
public:
    
    TreeNode* getAns(TreeNode* root, int limit, int sum) {
        if(!root) {
            return root;
        }
        
        if(!root->left  &&  !root->right) {
            if(sum + root->val < limit) {
                return NULL;
            }
            else {
                return root;
            }
        }
        
        TreeNode* leftAns = getAns(root->left, limit, sum + root->val);
        TreeNode* rightAns = getAns(root->right, limit, sum + root->val);
        
        if(leftAns == NULL) {
            root->left = NULL;
        }
        
        if(rightAns == NULL) {
            root->right = NULL;
        }
    
        if(rightAns == NULL && leftAns == NULL) {
            return NULL;
        }
        return root;  
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return getAns(root, limit, 0);
        
    }
};
