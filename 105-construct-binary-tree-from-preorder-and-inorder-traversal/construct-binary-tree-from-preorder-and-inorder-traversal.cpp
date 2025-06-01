/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++)
        mp[inorder[i]] = i;
auto root = buildTree(0, preorder.size() - 1, preorder, 0,inorder.size() - 1, inorder, mp);
        return root;
    }
    TreeNode* buildTree(int ps, int pe, vector<int>& preorder,int is, int ie,
    vector<int>& inorder, map<int, int>& mp)
    {   
        if(ps>pe || is>ie)return NULL;
        TreeNode* node = new TreeNode(preorder[ps]);
        int ir = mp[preorder[ps]];
        int numsleft = ir-is;

        node->left = buildTree(ps+1,ps+numsleft,preorder,is,ir-1,inorder,mp);
        node->right = buildTree(ps+1+numsleft,pe,preorder,ir+1,ie,inorder,mp);
        return node;
    }
};