     ListNode* merge(ListNode* l_head, ListNode* r_head)

    {

        ListNode new_head(-1);

        auto ptr_newlist = & new_head;

        if(l_head == NULL) return r_head;

        if(r_head == NULL) return l_head;

        auto ptr_1 = l_head;

        auto ptr_2 = r_head;

        while((ptr_1 != NULL) && (ptr_2 != NULL))

        {

            if(ptr_1->val < ptr_2->val)

            {

                ptr_newlist->next = ptr_1;

                ptr_1 = ptr_1->next;

            }

            else

            {

                ptr_newlist->next = ptr_2;

                ptr_2 = ptr_2->next;

            }

            ptr_newlist = ptr_newlist->next;

        }

        while(ptr_1 != NULL)

        {

            ptr_newlist->next = ptr_1;

            ptr_1 = ptr_1->next;

            ptr_newlist = ptr_newlist->next;

        }

        while(ptr_2 != NULL)

        {

            ptr_newlist->next = ptr_2;

            ptr_2 = ptr_2->next;

            ptr_newlist = ptr_newlist->next;

        }

        return new_head.next;

        

    }

     ListNode* sort(ListNode* head, ListNode* tail)

    {

        if((head == NULL) || (head == tail))

        {

            head->next = NULL;

            return head;

        }

        auto ptr_fast = head;

        auto ptr_slow = head;

        auto pre = ptr_slow;

        while(ptr_fast != tail)

        {

            pre = ptr_slow;

            ptr_fast = ptr_fast->next;

            ptr_slow = ptr_slow->next;

            if(ptr_fast == tail)

            break;

            else

             ptr_fast = ptr_fast->next;

            

        }

        auto sort_head_L = sort(head,pre);

        auto sort_head_R = sort(ptr_slow,ptr_fast);

        auto merge_head = merge(sort_head_L,sort_head_R);

        return merge_head;

    }

    

    ListNode* sortList(ListNode* head) {

        

    if(head==NULL||head->next==NULL)  

            return head;  

        ListNode* pre=NULL;  

        ListNode* cur=head;  

        while(cur!=NULL){  

            pre=cur;  

            cur=cur->next;  

        }  

        return sort(head,pre);  



    }



/*主要思路：
首先通过快慢指针将原列表划分为两段，递归对左右两部分进行排序，然后归并即可
主要问题是想明白递归基*/
