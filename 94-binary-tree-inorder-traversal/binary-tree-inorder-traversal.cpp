class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        auto cur = root;
        while(cur)
        {
            if(!cur->left)
            {
                ans.push_back(cur->val);
                cur=cur->right;
            }
            else
            {
                auto temp = cur->left;
                while(temp->right && temp->right!=cur)temp=temp->right;
                if(temp->right==NULL)
                {
                    temp->right=cur;
                    cur=cur->left;
                }
                else
                {
                    temp->right=NULL;
                    ans.push_back(cur->val);
                    cur=cur->right;
                }
            }
        }
        return ans;
    }
};