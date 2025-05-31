/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)return NULL;

        if(root==p || root==q)return root;

        auto a = lowestCommonAncestor(root->left,p,q);
        auto b = lowestCommonAncestor(root->right,p,q);
        if(a!=NULL && b!=NULL)return root;
        if(a!=NULL)return a;
        if(b!=NULL)return b;
        return NULL;
    }
};