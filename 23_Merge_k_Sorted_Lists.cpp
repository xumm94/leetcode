    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return NULL;
        int count = 0;
        ListNode* head = new ListNode(-1);
        auto ptr = head;
        
        while(count < lists.size())
        {
            count = 0;
            int small = INT_MAX;
            int index = -1;
            bool flag = 0;
            for(int i = 0; i < lists.size(); i++)
            {
                if(lists[i] == NULL)
                {
                    count++;
                    continue;
                }
                if(lists[i]->val < small)
                {
                    small = lists[i]->val;
                    index = i;
                    flag = 1;
                }
            }
            if(flag)
            {
                ptr->next = new ListNode(small);
                lists[index] = lists[index]->next;
                ptr = ptr->next;
            }
            
        }
        return head->next;
        
    }
