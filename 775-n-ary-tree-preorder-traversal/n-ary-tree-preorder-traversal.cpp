/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        stack<Node*> nodeStack;
        nodeStack.push(root);
        vector<int> preorder;
        if(!root)return preorder;
        while(!nodeStack.empty()){
            Node* node = nodeStack.top();
            nodeStack.pop();
            preorder.push_back(node->val);
            reverse(node->children.begin(),node->children.end());
            for(auto childNode:node->children){
                nodeStack.push(childNode);
            }
        }
        return preorder;

    }
};