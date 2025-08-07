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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode* Dummy = new ListNode();
        ListNode* prev = Dummy;
        Dummy->next=head;
        while( head && head->next){
            ListNode* temp = head->next;
            head->next=head->next->next;
            prev->next=temp;
            temp->next=head;
            prev=head;
            head=head->next;
        }
        return Dummy->next;
    }
};