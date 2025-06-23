class Solution {
public:
    void solve (TreeNode* root1, TreeNode* root2, TreeNode* root, int latestdirection){
        if (root1==NULL && root2==NULL){return;}
        TreeNode* connect=NULL;
        if (root1==NULL && root2!=NULL){
            connect=new TreeNode(root2->val);
            if (latestdirection==1){root->left=connect;}
            else if (latestdirection==2){root->right=connect;}
            solve (NULL,root2->left,connect,1);
            solve (NULL,root2->right,connect,2);
            return;
        }
        else if (root1!=NULL && root2==NULL){
            connect=new TreeNode(root1->val);
            if (latestdirection==1){root->left=connect;}
            if (latestdirection==2){root->right=connect;}
            solve (root1->left,NULL,connect,1);
            solve (root1->right,NULL,connect,2);
            return;
        }
        connect=new TreeNode(root1->val+root2->val);
        if (latestdirection==1){root->left=connect;}
        else if (latestdirection==2){root->right=connect;}
        solve (root1->left,root2->left,connect,1);
        solve (root1->right,root2->right,connect,2);
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1==NULL){return root2;}
        if (root2==NULL){return root1;}
        TreeNode* root=new TreeNode(root1->val+root2->val);
        solve(root1->left,root2->left,root,1);
        solve(root1->right,root2->right,root,2);
        return root;
    }
};
