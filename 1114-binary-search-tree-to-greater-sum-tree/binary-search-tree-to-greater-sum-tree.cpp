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
    int sum = 0;
    void sumBst(TreeNode* root){
        if(!root)return;
        sumBst(root->right);
        root->val+=sum;
        sum=root->val;
        sumBst(root->left);
        cout<<sum<<" ";
    }
    TreeNode* bstToGst(TreeNode* root) {
        sumBst(root);
        return root;
    }
};