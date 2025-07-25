class Solution {
public:
    // returns: {isBST (1 or 0), sum, min, max}
    vector<int> f(TreeNode* root, int& maxSum) {
        if (!root) return {1, 0, INT_MAX, INT_MIN};

        auto l = f(root->left, maxSum);
        auto r = f(root->right, maxSum);

        int isBST_l = l[0], sum_l = l[1], min_l = l[2], max_l = l[3];
        int isBST_r = r[0], sum_r = r[1], min_r = r[2], max_r = r[3];

        if (isBST_l && isBST_r && root->val > max_l && root->val < min_r) {
            int currSum = root->val + sum_l + sum_r;
            maxSum = max(maxSum, currSum);
            int currMin = min(min_l, root->val);
            int currMax = max(max_r, root->val);
            return {1, currSum, currMin, currMax};
        }

        return {0, 0, 0, 0};  // Not a BST
    }

    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        f(root, maxSum);
        return maxSum;
    }
};
