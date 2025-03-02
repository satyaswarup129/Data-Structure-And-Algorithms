/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr)
     return nullptr;
        ListNode *slow = head;
        ListNode * fast = head;
        while(fast->next!=nullptr && fast->next->next!= nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow)
            {
                ListNode * slow1=head;
                ListNode * slow2 = slow;
                while(slow1->next!=nullptr)
                {

                     if(slow1 == slow2)
                    return slow1;
                    slow2=slow2->next;
                    slow1= slow1->next;
                   
                }
            }
        }
        return nullptr;
    }
};
