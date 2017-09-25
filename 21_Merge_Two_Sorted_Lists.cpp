    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        auto l1_start = l1;

        auto l2_start = l2;

        auto new_list = l1;

        

        if(!l1) return l2;

        if(!l2) return l1;

        

         if(l1->val <= l2->val)

            {

                new_list = l1;

                l1 = l1->next;

            }

        else

            {

                new_list = l2;

                l2 = l2->next;

            }

        auto new_list_diedai = new_list;

      

        while(l1 && l2)

        {

            if(l1->val <= l2->val)

            {

                new_list_diedai->next = l1;

                l1 = l1->next;

            }

        else

            {

                new_list_diedai->next = l2;

                l2 = l2->next;

            }

            new_list_diedai = new_list_diedai->next;

        }

        

        while(l1)

        {

            new_list_diedai->next = l1;

            l1 = l1->next;

            new_list_diedai = new_list_diedai->next;

        }

        

        while(l2)

        {

            new_list_diedai->next = l2;

            l2 = l2->next;

            new_list_diedai = new_list_diedai->next;

        }

        

        return new_list;

    }

//考察归并排序
