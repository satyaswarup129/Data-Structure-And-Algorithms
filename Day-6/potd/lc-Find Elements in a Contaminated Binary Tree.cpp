class FindElements {
public:
    TreeNode* root;
    unordered_set<int> st;
    FindElements(TreeNode* root) {
        this->root=root;
        if(root) root->val = 0;
        st.insert(0);

        assign(root);
    }

    void assign(TreeNode* root){
        if(!root) return;

        if(root->left){
            root->left->val = 2*root->val+1;
            st.insert(root->left->val);
            assign(root->left);
        }

        if(root->right){
            root->right->val = 2*root->val+2;
            st.insert(root->right->val);
            assign(root->right);
        }
    }
    
    bool find(int target) {
        if(st.find(target)!=st.end()){
            return true;
        }
        return false;
    }
};
