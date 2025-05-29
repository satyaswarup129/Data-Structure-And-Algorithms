class Solution {
public:
    void solve(TreeNode* root, unordered_map<TreeNode*,int>& mp){
        if (root==NULL){return;}
        solve(root->left,mp);
        solve(root->right,mp);
        if (root->left==NULL && root->right==NULL){mp[root]=root->val;}
        else if (root->left==NULL && root->right!=NULL){mp[root]=root->val+mp[root->right];}
        else if (root->left!=NULL && root->right==NULL){mp[root]=root->val+mp[root->left];}
        else {mp[root]=root->val+mp[root->left]+mp[root->right];}
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<TreeNode*,int>mp;
        unordered_map<int,int>m;
        solve(root,mp);
        vector<int>ans,k;
        for (auto &it:mp){m[it.second]++;}
        int ma=INT_MIN;
        for (auto &it:m){
            if (it.second>ma){ma=it.second;k.clear();}
            if (it.second==ma){k.push_back(it.first);}
        }
        return k;
    }
};
