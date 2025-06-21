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
    ListNode* r(ListNode* head)
    {
        ListNode* prev = NULL;
        while(head->next!=NULL)
        {
            ListNode* temp = head->next;
            head->next=prev;
            prev=head;
            head=temp;
        }
        head->next=prev;
        return head;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* s = head;
        ListNode* f = head;
        while(f && f->next)
        {
            s=s->next;
            f=f->next->next;
        }
        s=r(s);
        f=head;
        while(f && s)
        {
            if(f->val != s->val)return false;
            f=f->next;
            s=s->next;
        }
        return true;
    }
};