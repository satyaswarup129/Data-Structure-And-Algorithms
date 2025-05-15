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

 int searchINOrderTraversal(vector<int>& inorder , int root_value){
    for(int i=0; i<inorder.size(); i++){
        if(inorder[i] == root_value){
            return i;
        }
    }
return -1;
}

TreeNode*  recursiveHelperFunction(vector<int>& preorder, vector<int>& inorder, int size , int& preIndex , int inOrder_startInd, int inOrder_endInd){
        //Base case
        if(preIndex >= size || inOrder_startInd > inOrder_endInd){
            return NULL;
        }

        //Position of root Node
        int root_value = preorder[preIndex];
        TreeNode* root = new TreeNode(root_value);
        preIndex++;

        //Find root Node in InOrder
        int  position = searchINOrderTraversal(inorder , root_value);

        //Construct left subTree
        root->left = recursiveHelperFunction(preorder , inorder , size , preIndex , inOrder_startInd , position-1);
        root->right = recursiveHelperFunction(preorder , inorder , size , preIndex , position+1 , inOrder_endInd);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0;
        int inOrder_startInd = 0;
        int inOrder_endInd = inorder.size() -1 ;
        int size = preorder.size();

        TreeNode* rootNode = recursiveHelperFunction(preorder , inorder , size , preIndex , inOrder_startInd , inOrder_endInd );

        return rootNode;
    }
};
