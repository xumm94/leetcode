    ListNode* partition(ListNode* head, int x) {

        if(head == NULL || head->next == NULL)

        return head;

     

        auto ptr_1 = head;

        queue<int> small;

        queue<int> big;

        while(ptr_1)

        {

            ptr_1->val < x? small.push(ptr_1->val) : big.push(ptr_1->val);

            ptr_1 = ptr_1->next;

        }

        

        

        auto p = head;

        

        while(!small.empty())

        {

            p->val = small.front();

            small.pop();

            p = p->next;

        }

        

        while(!big.empty())

        {

            p->val = big.front();

            big.pop();

            p = p->next;

        }

        return head;

    }
