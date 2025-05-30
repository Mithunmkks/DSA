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
    vector<int> preorderTraversal(TreeNode* root) 
    {
        auto cur = root;
        vector<int> ans;
        while(cur)
        {
            if(cur->left==NULL)
            {
                ans.push_back(cur->val);
                cur=cur->right;
            }
            else 
            {
                auto node = cur->left;
                while(node->right && node->right!=cur)node=node->right;
                if(node->right==NULL)
                {
                    node->right=cur;
                    ans.push_back(cur->val);
                    cur=cur->left;
                }
                else 
                {
                    node->right=NULL;
                    cur=cur->right;
                }
            }


        }
          return ans;

    }
};