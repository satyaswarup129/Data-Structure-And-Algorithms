class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* lista = headA;
        ListNode* listb = headB;

        while (lista != listb) {
            lista = (lista != nullptr) ? lista->next : headB;
            listb = (listb != nullptr) ? listb->next : headA;
        }

        return lista;        
    }
};
