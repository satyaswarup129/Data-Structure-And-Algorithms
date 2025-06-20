class Solution {
public:
    int height(TreeNode* root){
        if(root ==NULL) return 0;
        int leftAns =height(root->left);
        int rightAns = height(root->right);

        return 1+max(leftAns , rightAns);
    }
    
    vector<vector<string>> printTree(TreeNode* root) {
        int heightTree = height(root)-1;
        vector<vector<string>>ans(heightTree+1,vector<string>(pow(2,heightTree+1) - 1 , ""));
        unordered_map<TreeNode*,pair<int,int>>mp;
        int k = pow(2,heightTree+1) - 1;
        queue<TreeNode*>q;
        q.push(root);
        string rs =to_string(root->val);
        ans[0][(k-1)/2] = rs;
        mp[root] = {0,(k-1)/2};
        while(!q.empty()){
            int size = q.size();
            for(int i=0 ;i<size;i++){
                TreeNode* curr= q.front();
                int row= mp[curr].first;
                int col =mp[curr].second;
                q.pop();
                if(curr->left){
                    q.push(curr->left);
                    string rl = to_string(curr->left->val);
                    if(row+1 >= 0 && row+1 < heightTree+1 && col - pow(2,heightTree-row-1)>=0 && col - pow(2,heightTree-row-1)<pow(2,heightTree+1) - 1){
                        ans[row+1][col - pow(2,heightTree-row-1)]= rl;
                    mp[curr->left] = {row+1 , col - pow(2,heightTree-row-1)};
                    }
                    
                }
                if(curr->right){
                    q.push(curr->right);
                    string rr = to_string(curr->right->val);
                    if(row+1 >= 0 && row+1 < heightTree+1 && col + pow(2,heightTree-row-1)>=0 && col + pow(2,heightTree-row-1)<pow(2,heightTree+1) - 1){
                        ans[row+1][col + pow(2,heightTree-row-1)]= rr;
                    mp[curr->right] = {row+1 , col + pow(2,heightTree-row-1)};
                    }
                    
                }
            }
        }
        return ans;
    }
};
