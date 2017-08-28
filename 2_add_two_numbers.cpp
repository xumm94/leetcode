

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        queue<int> num_l1;

        queue<int> num_l2;

        queue<int> sum;



        auto p = l1;

        while(p != NULL)

        {

            num_l1.push(p->val);

            p = p->next;

        }

        p = l2;

        while(p != NULL)

        {

            num_l2.push(p->val);

            p = p->next;

        }

        

        if(num_l1.size() >= num_l2.size())

        {

            int jinwei = 0;

            int temp = 0;

            int result = 0;

            while(!num_l2.empty())

            {

                temp = jinwei + num_l1.front() + num_l2.front();

                result = temp % 10;

                jinwei = ((temp - result) == 0 ? 0 : 1);

                sum.push(result);

                num_l1.pop();

                num_l2.pop();

            }

            while(!num_l1.empty())

            {

                temp = jinwei + num_l1.front();

                 result = temp % 10;

                jinwei = ((temp - result) == 0 ? 0 : 1);

                sum.push(result);

                num_l1.pop();

            }

            if(jinwei == 1)

            sum.push(1);

        }

        else

        {

            int jinwei = 0;

            int temp = 0;

            int result = 0;

            while(!num_l1.empty())

            {

                temp = jinwei + num_l1.front() + num_l2.front();

                result = temp % 10;

                jinwei = ((temp - result) == 0 ? 0 : 1);

                sum.push(result);

                num_l1.pop();

                num_l2.pop();

            }

            while(!num_l2.empty())

            {

                temp = jinwei + num_l2.front();

                 result = temp % 10;

                jinwei = ((temp - result) == 0 ? 0 : 1);

                sum.push(result);

                num_l2.pop();

            }

            if(jinwei == 1)

            sum.push(1);

        }

        

        

        

        auto final = new ListNode(sum.front());

        sum.pop();

        p = final;

        while(!sum.empty())

        {

            auto newnode = new ListNode(sum.front());

            p->next = newnode;

            p = p->next;

            sum.pop();

        }

        return final;

        

    }
