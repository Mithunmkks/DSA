class Solution {
public:
    ListNode* mergeTwoLists(ListNode* i, ListNode* j) {
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while(i && j)
        {
            if(i->val<=j->val)
            {
                tail->next=i;
                tail=tail->next;
                i=i->next;
            }
            else
            {
                tail->next=j;
                tail=tail->next;
                j=j->next;
            }
        }
        if(i)tail->next=i;
        if(j)tail->next=j;
        return dummy->next;






    }
};