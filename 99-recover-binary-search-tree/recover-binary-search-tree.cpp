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
    void recoverTree(TreeNode* root) {
        TreeNode* pre = NULL;
        vector<TreeNode*> vec;
        TreeNode* cur = root;
        if (!root)
            return;
        while (cur) {
            if (!cur->left) {
                if (pre && pre->val > cur->val) {
                    if (vec.size() == 0) {
                        vec.push_back(pre);
                        vec.push_back(cur);
                    } else
                        vec.push_back(cur);
                }
                pre = cur;
                cur = cur->right;
            } else {
                TreeNode* predec = cur->left;
                while (predec->right && predec->right != cur)
                    predec = predec->right;
                if (predec->right == cur) {
                    predec->right = NULL;
                    if (pre && pre->val > cur->val) {
                        if (vec.size() == 0) {
                            vec.push_back(pre);
                            vec.push_back(cur);
                        } else
                            vec.push_back(cur);
                    }
                    pre = cur;
                    cur = cur->right;
                } else {
                    predec->right = cur;
                    cur = cur->left;
                }
            }
        }
        if (vec.size() == 2)
            swap(vec[0]->val, vec[1]->val);
        else if (vec.size() == 3)
            swap(vec[0]->val, vec[2]->val);
    }
};