class Solution {
public:
    vector<int>ans;
    vector<int> preorder(Node* root) {
        if(root == NULL){
            return ans;
        }
        ans.push_back(root->val);
        for(int i=0 ; i<root->children.size() ; i++){
            preorder(root->children[i]);
        }

        return ans;


    }
};
