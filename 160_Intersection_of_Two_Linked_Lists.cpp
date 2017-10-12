ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *cur1 = headA, *cur2 = headB;
    while(cur1 != cur2){
        cur1 = cur1?cur1->next:headB;
        cur2 = cur2?cur2->next:headA;
    }
    return cur1;
}
/*设L = L1 + L2
两个指针走过的路程是一样的，如果有公共的节点，后面的长度是一样的，所以最多走L1 + L2 步就可以找到交点。
时间复杂度为o(n),空间复杂度为o(1)
*/
