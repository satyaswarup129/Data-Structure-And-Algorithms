class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int integer=0;
        while(head){
            integer=integer*2+head->val;
            head=head->next;
        }
        return integer;
    }
};
