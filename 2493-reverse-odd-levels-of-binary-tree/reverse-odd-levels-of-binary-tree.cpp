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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        vector<int> nodeVals;
        while (!q.empty()) {
            int k = q.size();
            for (int i = 0; i < k; i++) {
                TreeNode* cur = q.front();
                if (level % 2 == 1) {
                    cur->val = nodeVals.back();
                    nodeVals.pop_back();
                }
                q.pop();
                if (cur->left) {
                    q.push(cur->left);
                    if (level % 2 == 0)
                        nodeVals.push_back(cur->left->val);
                }
                if (cur->right) {
                    q.push(cur->right);
                    if (level % 2 == 0)
                        nodeVals.push_back(cur->right->val);
                }
            }
            level++;
        }
        if (level % 2 == 1) {
            while (!q.empty()) {
                auto cur = q.front();
                q.pop();
                cur->val = nodeVals.back();
                nodeVals.pop_back();
            }
        }
        return root;
    }
};