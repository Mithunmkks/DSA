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
    int findTiltSum(TreeNode* root,int &ans){
        if(!root)return 0;
        int l = findTiltSum(root->left,ans);
        int r = findTiltSum(root->right,ans);
        ans+=abs(l-r);
        return l+r+root->val;
    }
    int findTilt(TreeNode* root) {
        int ans=0;
        findTiltSum(root,ans);
        return ans;
    }
};