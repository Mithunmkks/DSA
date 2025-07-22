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
    map<int,int> mp;
    TreeNode* f(int prestart , int preEnd , vector<int>&preorder , int instart ,int inEnd , vector<int> &inorder)
    {
        if(prestart>preEnd || instart>inEnd)return NULL;
        int rootInd = mp[preorder[prestart]];
        int len = rootInd-instart;
        TreeNode* root = new TreeNode(inorder[rootInd]);
        root->left = f(prestart+1,prestart+len,preorder,instart,rootInd-1,inorder);
        root->right = f(prestart+len+1,preEnd,preorder,rootInd+1,inEnd,inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i=0;i<n;i++)mp[inorder[i]]=i;
        TreeNode *root = f(0,n-1,preorder,0,n-1,inorder);
        return root;
    }
};