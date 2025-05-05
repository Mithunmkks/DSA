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
    ListNode* reverseKGroup(ListNode* head, int k) {
        stack<ListNode*> st;
        ListNode* Dummy = new ListNode();
        ListNode* tail = Dummy;
        ListNode* i = head;
        while (i) {
            st.push(i);
            i = i->next;
            if (st.size() == k) {
                while (!st.empty()) {
                    ListNode* temp = st.top();
                    st.pop();
                    tail->next = temp;
                    tail = tail->next;
                    
                }
            }
            
        }
        stack<ListNode*> stack2;
        while(!st.empty())
        {
            stack2.push(st.top());
            st.pop();
        }
        while (!stack2.empty()) {
            ListNode* temp = stack2.top();
            stack2.pop();
            tail->next = temp;
            tail = tail->next;
        }
        tail->next=NULL;
        return Dummy->next;
    }
};

// D->2->1->