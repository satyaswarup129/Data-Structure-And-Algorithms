
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
       queue<TreeNode*> q{{root}};
        bool ans = false;
        while(!q.empty()){
            TreeNode* node = q.front(); q.pop();
            if(!node) ans=true;
            else{
                if(ans) return false;
                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;
    }
};
