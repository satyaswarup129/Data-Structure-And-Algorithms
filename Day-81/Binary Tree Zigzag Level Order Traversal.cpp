class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        if(root==NULL){
            return ans;
        }
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int>ans2;
            for(int i=0;i<n;i++){
            TreeNode* v=q.front();
            ans2.push_back(v->val);
            q.pop();
            if(v->left!=NULL){
                q.push(v->left);
            }
            if(v->right!=NULL){
                q.push(v->right);
            }
            }
            if(ans.size()&1){
                reverse(ans2.begin(),ans2.end());
            }
            ans.push_back(ans2);
        }
        return ans;
    }
};
