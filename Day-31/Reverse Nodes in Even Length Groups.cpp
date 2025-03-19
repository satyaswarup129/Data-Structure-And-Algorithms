class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        vector<ListNode*> arr;
        auto node = head;
        while(node) {
            arr.push_back(node);
            node = node->next;
        }
        int idx = 0;
        int cnt = 1;
        while(idx < arr.size()) {
            int offset = min(idx + cnt, (int)arr.size());
            if((offset - idx) % 2 == 0)
                reverse(arr.begin() + idx, arr.begin() + offset);
            idx += cnt;
            ++cnt;
        }
        for(int i = 1; i < arr.size(); i++) {
            arr[i - 1]->next = arr[i];
        }
        arr.back()->next = NULL;
        return arr[0];
    }
};
