class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;

        int length = 1; 
        ListNode* last = head;
        while (last->next) {
            last = last->next;
            length++;
        }
        k = k % length;
        if (k == 0) return head;

        ListNode* prev = head;
        for (int i = 0; i < length - k - 1; i++) {
            prev = prev->next;
        }
        ListNode* newHead = prev->next;
        prev->next = nullptr; 
        last->next = head;    

        return newHead;
    }
};
