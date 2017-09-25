    ListNode* removeNthFromEnd(ListNode* head, int n) {

        vector<ListNode*> vec;

        auto copy_head = head;

        while(copy_head)

        {

            vec.push_back(copy_head);

            copy_head = copy_head->next;

        }

        if(vec.size() == 1 && n == 1)

            return NULL;

        if(vec.size() == n)

            return vec[1];

        if(n == 1)

        {

            vec[vec.size()-2]->next = NULL;

            return head;

        }

        int i = n;

        int vec_dele = vec.size() - 1;

        while(i > 1)

        {

            vec_dele--;

            i--;

        }

         vec[vec_dele-1]->next = vec[vec_dele+1];

         return head;

      

        

    }
