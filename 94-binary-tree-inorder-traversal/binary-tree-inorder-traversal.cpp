class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* current = root;
        while(current || !st.empty())
        {
            while(current!=NULL)
            {
                st.push(current);
                current=current->left;
            }
            current= st.top();
            st.pop();
            ans.push_back(current->val);
            current=current->right;
        }
        return ans;
    }
};