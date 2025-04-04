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
    int Deepest(TreeNode* root){
        if(root== NULL){
            return 0;
        }

        int leftt = Deepest(root->left);
        int rightt= Deepest(root->right);
        return max(leftt, rightt) +1; 
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        // first we need to find lowest nodes and then we neeed to find the common ancestors
        //  ek baari left subttree ke deepest ek baari right ke 
        int leftDepth = Deepest(root->left);
        int rightDepth = Deepest(root->right);
        if(rightDepth == leftDepth)return root;
        if(rightDepth >leftDepth){
            return lcaDeepestLeaves(root->right);
        }else{
            return lcaDeepestLeaves(root->left);
        }
        
        
        
    }
};
