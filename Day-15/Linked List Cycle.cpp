class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> st;
        while(head!=NULL){
            if(st.find(head)!=st.end()){
                return true;
            }
            st.insert(head);
            head=head->next;
        }
        return false;
    }
};
