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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* cur = head->next;
        int curSum = 0;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(cur){
            curSum+=cur->val;
            if(cur->val==0){
                temp->next = new ListNode(curSum);
                temp=temp->next;
                curSum=0;
            }
            cur=cur->next;
        } 
        return dummy->next;
    }
};