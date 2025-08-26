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
    TreeNode* makeTree(int l,int r,vector<int>&nums){
        if(l>r)return NULL;
        int rootInd = max_element(nums.begin()+l,nums.begin()+r+1)-nums.begin();
        TreeNode* root = new TreeNode(nums[rootInd]);
        root->left = makeTree(l,rootInd-1,nums);
        root->right = makeTree(rootInd+1,r,nums);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root = makeTree(0,nums.size()-1,nums);
        return root;
    }
};