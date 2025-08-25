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
    // {withRoot,withoutRoot}
    vector<int> maxRob(TreeNode* root){
        if(!root)return {0,0};
        // 0 -> with root , 1->without root
        vector<int> lr = maxRob(root->left);
        vector<int> rr = maxRob(root->right);
        int withRoot = root->val + lr[1] + rr[1];
        int withOutRoot = max({lr[0]+rr[0],lr[1]+rr[1],lr[0]+rr[1],lr[1]+rr[0]});
        return {withRoot,withOutRoot};
    }
    int rob(TreeNode* root) {
        vector<int> ans = maxRob(root);
        return max(ans[0],ans[1]);
    }
};