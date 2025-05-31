class Solution {
public:
    int f(TreeNode* root,int &ans)
    {
        if(!root)return 0;
        
        int l = max(f(root->left,ans),0);
        int r = max(f(root->right,ans),0);

        ans=max(ans,l+r+root->val);
        ans=max(ans,l+root->val);
        ans=max(ans,r+root->val);
        ans=max(ans,root->val);
        return root->val + max(l,r);

    }
    int maxPathSum(TreeNode* root) {
        int ans =INT_MIN;
        f(root,ans);
        return ans;
    }
};