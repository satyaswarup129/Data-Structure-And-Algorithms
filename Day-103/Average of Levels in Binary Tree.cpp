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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*>q;
        vector<double>v;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            double sum=0;
            int cnt=0;
            for(int i=1;i<=sz;i++){
                sum+=q.front()->val;
                cnt++;
                TreeNode *tem=q.front();
                q.pop();
                if(tem->left){
                    q.push(tem->left);
                }
                if(tem->right){
                    q.push(tem->right);
                }
            }
            v.push_back(sum/cnt);
        }
        return v;
    }
};
