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
    int f(TreeNode* root,int &d)
    {
        if(root==NULL)return 0;
        int l=0;
        if(root->left) l = 1 + f(root->left,d);
        int r=0; 
        if(root->right) r = 1 + f(root->right,d);
        d=max(d,l+r);
        return max(l,r);
    }
     
    int diameterOfBinaryTree(TreeNode* root) {
        int d=0;
        f(root,d);
        return d;
    }
};