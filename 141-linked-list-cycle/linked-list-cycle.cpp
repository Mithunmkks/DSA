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
    bool hasCycle(ListNode *head) {
        if(head==NULL)return false;
        if(head->next==NULL)return false;
        ListNode* i=head;
        ListNode* j=head->next->next;
        while(i!=j && i && j && j->next!=NULL)
        {
            i=i->next;
            j=j->next->next;
        }
        if(i==j)return true;
        else return false;
        
    }
};