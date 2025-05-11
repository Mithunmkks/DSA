/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*,Node*> mp;
        Node* i = head;
        Node* j;
        Node* dummy = new Node(-1);
        j=dummy;
        while(i)
        {
            j->next = new Node(i->val);
            j=j->next;
            mp[i]=j;
            i=i->next;
        }
        i=head;
        j=dummy->next;
        while(i)
        {
            j->random=mp[i->random];
            i=i->next;
            j=j->next;
        }
        return dummy->next;
    }
};