/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public: 
    bool find(TreeNode* root , int x,TreeNode* cur )
    {
        while(root)
        {
            if(root->val==x && root!=cur)return true;
            if(root->val<x)root=root->right;
            else root=root->left;
        }
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty())
        {
            auto node = st.top();
            st.pop();
            if(find(root,k-node->val,node))return true;
            if(node->right)st.push(node->right);
            if(node->left)st.push(node->left);
        }
        return false;
    }
};