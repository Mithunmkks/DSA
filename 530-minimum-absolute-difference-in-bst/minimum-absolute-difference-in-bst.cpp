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
    void getMinDiff(TreeNode* root,int &ans,int maxi,int mini){
        if(!root)return ;
        if(maxi!=-1e6)ans=min(ans,abs(root->val-maxi));
        if(mini!=1e6)ans=min(ans,abs(root->val-mini));
        getMinDiff(root->left,ans,root->val,mini);
        getMinDiff(root->right,ans,maxi,root->val);

    }
    int getMinimumDifference(TreeNode* root) {
        int ans = 1e5;
        getMinDiff(root,ans,-1e6,1e6);
        return ans;
    }
};