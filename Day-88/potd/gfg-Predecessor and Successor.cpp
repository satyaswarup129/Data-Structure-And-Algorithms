class Solution {
  public:
    
    void pre(Node* root , int&key , vector<Node*>&ans){
        if(root == NULL) return ;
        if(root -> data < key){
            if(ans[0] -> data < root -> data) ans[0] = root ; ;
        }
        if(root -> data >= key) pre(root -> left , key , ans) ;
        else pre(root -> right , key , ans) ;
    }
    
    void succ(Node* root , int&key , vector<Node*>&ans){
        if(root == NULL) return ;
        if(root -> data > key){
            if(ans[1] -> data > root -> data) ans[1] = root ; ;
        }
        if(root -> data > key) succ(root -> left , key , ans) ;
        else succ(root -> right , key , ans) ;
    }
    
    vector<Node*> findPreSuc(Node* root, int key) {
        Node*temp = new Node(-1) ;
        vector<Node*>ans = {new Node(-1) , new Node(INT_MAX)} ;
        bool res = 0 ;
        pre(root , key , ans) ;
        succ(root , key , ans) ;
        if(ans[1] -> data == INT_MAX) ans[1] = new Node(-1) ;
        return ans ;
    }
};
