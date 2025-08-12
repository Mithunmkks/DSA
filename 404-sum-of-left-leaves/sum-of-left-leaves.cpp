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
    int sumLeft(TreeNode* root,int sign){
        if(!root)return 0;
        if(!root->left && !root->right){
            if(sign==-1)return root->val;
            else return 0;
        }
        int l = sumLeft(root->left,-1);
        int r = sumLeft(root->right,1);
        return l+r;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return sumLeft(root,0);
    }
};