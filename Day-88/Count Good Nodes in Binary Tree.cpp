class Solution {
public:
        int goodNodes(TreeNode* r, int ma = -10000) {
        return r ? goodNodes(r->left, max(ma, r->val)) + goodNodes(r->right, max(ma, r->val)) + (r->val >= ma) : 0;
    }
};
