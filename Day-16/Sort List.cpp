class Solution {
public:
    ListNode* advanceNode(ListNode* node, int pos) /* advance by pos forward */
        {
            while (node && node->next && pos)
            {
                pos--;
                node = node->next;
            }

            return node;
        }

    /* Just an iterative approach of merging 2 lists. Should be NULL terminated (last->next = NULL) */ 
    std::pair<ListNode*, ListNode*> merge2halves(ListNode* list1, ListNode* list2) {
        ListNode  dummy = ListNode(0);
        ListNode* ans = &dummy;

        while (list1 && list2)
        {
            if (list1->val < list2->val) {
                ans->next = list1;
                list1 = list1->next;
            } else {
                ans->next = list2;
                list2 = list2->next;
            }

            ans = ans->next;
        }

        ans->next = list1 ? list1 : list2;

        while (ans->next)
            ans = ans->next;

        return {dummy.next, ans};
    }

    ListNode* sortList(ListNode* head) {
        /* perform the very first iteration */
        ListNode* cur = head;

        /* just count */
        int cnt = 0;
        while (cur)  // ~ O(N)
        {
            cur = cur->next;
            cnt++;
        }

        cur = head;

        ListNode *lhs  = head;
        ListNode *rhs  = head;
        ListNode *next = head;
        ListNode *prev = head;
        ListNode *prev2 = head;

        int lvl = 1; /* our "window". * 2 on every iteration*/

        while (lvl < cnt)   // ~ O(2 * N * logN) ~ O(NlogN)
        {
            int cnt_half = cnt / (2 * lvl); /* # of merge iterations in the while loop */
            int cnt_rest = cnt % (2 * lvl); /* that we will merge after the main while loop */

            lhs = head;
            rhs = head;
            ListNode* l_end = advanceNode(lhs, lvl - 1);
            rhs = l_end->next;

            ListNode* r_end = advanceNode(rhs, lvl - 1);
            if (cnt_half > 0)
            {
                next = r_end->next;
                r_end->next = NULL;
                l_end->next = NULL;
            }

            int tmp_cnt = 0;
            std::pair<ListNode*, ListNode*> p1;

            while (tmp_cnt < cnt_half) /* merge everything for our lvl */
            {
                if (tmp_cnt)
                {
                    /* update the lhs and rhs pointers */
                    lhs = p1.second->next; /* last of the interval */

                    l_end = advanceNode(lhs, lvl - 1);
                    if (l_end)
                        rhs = l_end->next;

                    r_end = advanceNode(rhs, lvl - 1);
                    if (r_end)
                    {
                        next = r_end->next;
                        r_end->next = NULL;
                    }

                    if (l_end)
                        l_end->next = NULL;
                }

                p1 = merge2halves(lhs, rhs);
                
                /* Update new head and/or reference from previous Node */
                cur = p1.first;

                if (tmp_cnt > 0)
                    prev->next = p1.first;
                else
                    head = cur;

                prev2 = prev;

                prev = p1.second;
                p1.second->next = next;

                tmp_cnt++;
            }

            /* advance lhs and rhs pointers and merge rest of the halves */
            if (cnt_rest > 0 && cnt_half > 0)
            {
                if (cnt_rest <= lvl)
                {
                    cur = head;
                    /* rhs should be just first element after last of prev interval */
                    rhs = p1.second->next;
                    /* NULL left interval */
                    p1.second->next = NULL;
                    lhs = p1.first;
                } else {
                    cur = head;

                    lhs = p1.first;
                    rhs = p1.second->next;
                    p1.second->next = NULL;
                }

                p1 = merge2halves(lhs, rhs);

                if (p1.first != head)
                {
                    if (tmp_cnt == 1) /* there was just 1 merge before. Maybe we should update the head? */
                        cur = p1.first;
                    else
                        prev2->next = p1.first;
                }

                head = cur;
            }

            lvl *= 2;
        }

        return cur;
    }
};
