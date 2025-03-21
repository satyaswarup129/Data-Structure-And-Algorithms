class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;

        Node* original = head;
        Node* cloned = nullptr; 
        Node* temp = nullptr; 
        while(original) {
            temp = new Node(original->val);
            temp->next = original->next;
            original->next=temp;
            original = temp->next;
        }

        original = head;
        Node* newHead = head->next;
        while(original) {
            if(original->random) {
                original->next->random = original->random->next;
            } else {
                original->next->random = nullptr;
            }
            original = original->next->next; 
        }
        
        original = head;
        while(original) {
            temp = original->next; 
            original->next = temp->next; 
            original = original->next;

            if(original) {
                temp->next = original->next;
            } else {
                temp->next = nullptr;
            }
        }

    return newHead;
    }
};
