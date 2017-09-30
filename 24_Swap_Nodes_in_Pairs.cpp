 ListNode* swapPairs(ListNode* head) {

        if(head == NULL)

        return NULL;

        auto q = new ListNode(-1);

        auto first = head;

        auto second = head->next;

        auto result = head;

        if(second == NULL)

        return result;

        else

        result = second;

        

        q->next = second;

        while(second != NULL)

        {

            q->next = second;

            first->next = second->next;

            second->next = first;

            

            q = q->next;

            q = q->next;

    

            if(first->next == NULL)

            break;

            else

            first = first->next;

           

            second = first->next;

            

        }

        return result;

        

    }

//一次只处理两个节点。
