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
    void insertatplace(TreeNode* place, TreeNode* &root){
        if (place->val<root->val){
            if (root->left!=NULL){insertatplace(place,root->left);}
            else {root->left=place;}
        }
        else {
            if (root->right!=NULL){insertatplace(place,root->right);}
            else {root->right=place;}
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root=new TreeNode();
        root->val=preorder[0];
        for (int i=1;i<preorder.size();i++){
            TreeNode* pl=new TreeNode();
            pl->val=preorder[i];
            insertatplace(pl,root);
        }
        return root;
    }
};
