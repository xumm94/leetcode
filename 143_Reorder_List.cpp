    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return ;
        ListNode *fast = head, *slow = head, *p = head, *q = head;
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        fast = slow->next;
        slow->next = NULL;
        p = fast;
        q = fast->next;
        p->next = NULL;
        while(q)
        {
            ListNode *tmp1 = p, *tmp2 = q;
            p = q;
            q = q->next;
            tmp2->next = tmp1;
        }
        
        auto head_copy = head;
        while(p)
        {
            auto tmp1 = head_copy, tmp2 = p;
            head_copy = head_copy->next;
            tmp1->next = p;
            p = p->next;
            tmp2->next = head_copy;
        }
        return ;
        
    }




/*首先利用快慢指针（二倍速）找到链表的中点，将链表中点以后的节点倒置，然将两个链表归并即可*/
