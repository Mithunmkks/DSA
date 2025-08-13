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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode* cur = head;
        int countM = 0;
        while(cur){
            countM++;
            if(countM%m==0){
                ListNode* cur2=cur->next;
                int countN=0;
                while(countN<n && cur2){
                    countN++;
                    cur2=cur2->next;
                }
                cur->next=cur2;
            }
            cur=cur->next;
        }
        return head;
    }
};