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
        int a,b;
        if(p->val > q->val)
        {
            a=p->val;
            b=q->val;
        }
        else 
        {
            a=q->val;
            b=p->val;
        }
        return f(root,b,a);
    }
    TreeNode* f(TreeNode* root , int l ,int h )
    {
        if(!root)return root;
        int x = root->val;
        if(x>= l && x<= h)return root;
        else if (x>l) return f(root->left,l,h);
        else return f(root->right,l,h);
    }
};