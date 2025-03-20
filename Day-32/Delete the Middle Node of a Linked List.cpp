class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* current = head;
        int a=0;
        int sol=0;
        if(!current->next){
            return nullptr;
        }
        while(current){
            current=current->next;
            a++;
        }current = head;
        while(current && sol<(a/2-1)){
             current=current->next;
             sol++;
        }
        current->next=current->next->next;
             
        return head;
    }
};
