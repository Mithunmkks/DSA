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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode* dummy = new ListNode(0,head);
        ListNode* prev = dummy;
        ListNode* cur = head;
        while(cur && cur->next){
            if(cur->val==cur->next->val){
                ListNode* cur2 = cur;
                while( cur2 && cur2->val==cur->val)cur2=cur2->next;
                prev->next=cur2;
                cur=cur2;
            }
            else {
                cur=cur->next;
                prev=prev->next;
            }
        }
        return dummy->next;
    }
};