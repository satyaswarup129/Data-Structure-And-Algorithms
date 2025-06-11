class Solution {
public:

    int ans = 0;
    int max = 0;

    void perorder (TreeNode * root, int curr) {
        if (root == nullptr) {
            return ;
        }
        if (root -> left == nullptr && root -> right == nullptr) {
            if (curr == max ) {
                ans += root -> val;
            }
            if (curr > max) {
                ans = 0;
                max = curr;
                ans += root -> val;
            }
        }
        perorder (root -> left,curr + 1);
        perorder (root -> right, curr + 1);

    }
    int deepestLeavesSum(TreeNode* root) {

        perorder (root, 1);
        return ans;
    }
};
