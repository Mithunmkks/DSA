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
        map<int,int> mp;
        ListNode* cur = head;
        while(cur){
            mp[cur->val]++;
            cur=cur->next;
        }
        cur=head;
        while(cur->next){
            if(mp[cur->next->val]>1)cur->next=cur->next->next;
            else cur=cur->next;
        }
        if(mp[head->val]>1)return head->next;
        return head;

        
    }
};