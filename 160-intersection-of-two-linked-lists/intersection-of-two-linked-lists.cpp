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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        vector<ListNode*> a;
        vector<ListNode*> b;
        ListNode* i = headA;
        ListNode* j = headB;
        while(i)
        {
            a.push_back(i);
            i=i->next;
        }
        while(j)
        {
            b.push_back(j);
            j=j->next;
        }
        int p=a.size()-1,q=b.size()-1;

        while(p>=0 && q>=0)
        {
            if(a[p]!=b[q])break;
            p--;
            q--;
        }
        if(p==a.size()-1 && q==b.size()-1)return NULL;
        return a[p+1];
    }
};