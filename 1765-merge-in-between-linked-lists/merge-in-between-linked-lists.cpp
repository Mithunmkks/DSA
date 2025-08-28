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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int countA = 1;
        ListNode* curA = list1;
        while(countA<a){
        curA=curA->next;
        countA++;
        }
        int countB = 0;
        ListNode* curB = list1;
        while(countB<b){
            curB=curB->next;
            countB++;
        }
        ListNode* curS = list2;
        ListNode* curE = list2;
        while(curE->next)curE=curE->next;
        curA->next=curS;
        curE->next=curB->next;
        return list1;

    }
};