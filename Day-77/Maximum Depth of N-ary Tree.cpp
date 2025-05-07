class Solution {
public:
    int maxDepth(Node* root) {
    if (!root) return 0;
    int res = 1;
    for(Node* child : root->children) 
        res = max(res, maxDepth(child) + 1);
    return res;
    }
};
