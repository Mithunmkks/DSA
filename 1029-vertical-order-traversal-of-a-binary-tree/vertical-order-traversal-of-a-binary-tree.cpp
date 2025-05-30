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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, map<int, vector<int>>> mp;
        stack<pair<int, pair<int, TreeNode*>>> st;
        st.push({0, {0, root}});
        while (!st.empty()) {
            auto it = st.top();
            st.pop();
            auto node = it.second.second;
            ;
            int x = it.first;
            int y = it.second.first;
            mp[x][y].push_back(node->val);
            if (node->left)
                st.push({x - 1, {y + 1, node->left}});
            if (node->right)
                st.push({x + 1, {y + 1, node->right}});
        }
        for (auto& it : mp) {
            vector<int> col;
            for (auto& itt : it.second) {
                auto& v = itt.second;
                sort(v.begin(), v.end());
                col.insert(col.end(), v.begin(), v.end());
            }
            ans.push_back(col); // Push the whole column
        }
        return ans;
    }
};