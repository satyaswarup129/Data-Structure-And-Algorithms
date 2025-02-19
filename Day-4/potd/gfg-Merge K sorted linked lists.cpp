class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        map<int,vector<Node*>> mp;
        int n =arr.size();
        for(int i =0;i< n;i++){
            Node* t = arr[i];
            while(t != nullptr){
                mp[t->data].push_back(t);
                t= t->next;
            }
        }
        auto x = mp.begin();
        Node* first = x->second[0];
        for(auto it = mp.begin(); it != mp.end(); it++) {
            vector<Node*>& curr_nodes = it->second;
            int n2 = curr_nodes.size();
            // Connect nodes with same value
            for(int i = 0; i < n2-1; i++) {
                curr_nodes[i]->next = curr_nodes[i+1];
            }
            // Connect to next value's nodes
            auto next_it = next(it);
            if(next_it != mp.end()) {
                curr_nodes[n2-1]->next = next_it->second[0];
            } else {
                curr_nodes[n2-1]->next = nullptr;
            }
        }
        return first;
    }
};
