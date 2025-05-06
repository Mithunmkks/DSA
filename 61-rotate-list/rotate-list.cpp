/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)return head;
        int count =0;
        ListNode* i= head;
        ListNode* last = NULL;
        while(i)
        {
            count++;
            last=i;
            i=i->next;
        }
        k%=count;
        if(k==0)return head;
        last->next=head;
        int sc =0;
        i=head;
        while(i)
        {
            sc++;
            if(sc==count-k)
            {
                ListNode* temp = i->next;
                i->next=NULL;
                return temp;
            }
            i=i->next;
        }
        return NULL;
        
    }
};