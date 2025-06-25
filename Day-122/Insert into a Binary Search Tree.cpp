class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* nn=new TreeNode(val);
        if(root==NULL)return nn;
        TreeNode*t= root;
        while(1){
            if(t->val >= val){
                if(t->left==NULL){t->left=nn;break;}
                else{t=t->left;}
            }
            else{
                if(t->right==NULL){t->right=nn;break;}
                else{t=t->right;}
            }
        }
        return root;
    }
};
