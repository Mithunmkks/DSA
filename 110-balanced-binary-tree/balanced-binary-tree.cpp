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
    int f(TreeNode* root,bool &balanced)
    {
        if(!root)return 0;
        
        int l =1+f(root->left,balanced);
        int r =1+f(root->right,balanced);
        if(abs(l-r)>1)
        {
            balanced=false;
            return 0;
        }
        return max(l,r);

    }
    bool isBalanced(TreeNode* root) {
        if(!root)return true;
        bool balanced=true;
        f(root,balanced);
        return balanced;
    }
};