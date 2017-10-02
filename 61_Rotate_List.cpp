    ListNode* rotateRight(ListNode* head, int k) {

        int i = 0;

        auto now = head ;

        while (now)

        {

            i++;

            now = now->next;

        }

        if( i == 0) return head;

        int z = k % i;

        if( z== 0) return head;

        int j = 0;

        now = head;

        while(j < i -z -1)

        {

            now = now->next;

            j++;

        }

        auto result = now;

        result = result->next;

        j++;

        now->next = NULL;

        now = result;

        while(j < i - 1)

        {

            now = now->next;

            j++;

        }

        now->next = head;

        return result;

    }
