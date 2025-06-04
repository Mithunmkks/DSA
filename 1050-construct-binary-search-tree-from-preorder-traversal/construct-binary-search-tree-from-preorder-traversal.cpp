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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(),inorder.end());
        int n = inorder.size();
        map<int,int> mp;
        for(int i=0;i<n;i++)mp[inorder[i]]=i;
        return f(0,n-1,inorder,0,n-1,preorder,mp);
    }
    TreeNode* f(int instart , int inend , vector<int> &inorder,int prestart , int preend, vector<int> &preorder,map<int,int> &mp)
    {
        if(prestart>preend || instart>inend)return NULL;
        TreeNode* node = new TreeNode(preorder[prestart]);
        int pos = mp[preorder[prestart]];
        int leftSize = pos - instart;
        node->left = f(instart,pos-1,inorder,prestart+1,prestart+leftSize,preorder,mp);
        node->right= f(pos+1,inend,inorder,prestart+leftSize+1,preend,preorder,mp);
        return node;
    }
};