/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL)
            return NULL;
        unordered_map<RandomListNode*, RandomListNode*> hash_table;
        RandomListNode *result = new RandomListNode(head->label);
        auto p = head;
        auto q = result;
        hash_table[p] = q;
        p = p->next;
        while(p)
        {
            auto tmp = new RandomListNode(p->label);
            q->next = tmp;
            q = q->next;
            hash_table[p]  = q;
            p = p->next;
        
        }
        p = head;
        q = result;
        while(p)
        {
            q->random = hash_table[p->random];
            p = p->next;
            q = q->next;
        }
        
        return result;
    }
};


/*
和克隆图类似，建立一张哈希表，记录顶点之间的映射
*/
