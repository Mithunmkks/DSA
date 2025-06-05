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
    void f(TreeNode* root , int &count , int k,int & ans)
    {
        if(!root)return;
        f(root->left,count,k,ans);
        count++;
        if(count==k)ans=root->val;
        f(root->right,count,k,ans);

    }
    int kthSmallest(TreeNode* root, int k) {
        int x=0;
        int ans=0;
        f(root,x,k,ans);
        return ans;
    }
};