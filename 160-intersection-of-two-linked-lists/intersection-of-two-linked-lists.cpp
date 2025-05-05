/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* i=headA;
        ListNode* j=headB;

        while(i && j)
        {
            if(i==j)return i;
            i=i->next;
            j=j->next;
        }
        if(!i && !j)return NULL;
        if(!i)i=headB;
        if(!j)j=headA;
        while(i && j)
        {
            i=i->next;
            j=j->next;
        }
        if(!j)j=headA;
        if(!i)i=headB;
        while(i && j)
        {
            if(i==j)return i;
            i=i->next;
            j=j->next;
        }
        return NULL;
    }
};