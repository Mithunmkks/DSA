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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL)return {};
        stack<TreeNode*> s1;
        auto cur = root;
        vector<int> ans;
        while(!s1.empty() || cur)
        {
            if(cur)
            {
                s1.push(cur);
                cur=cur->left;
            }
            else 
            {
               auto temp = s1.top()->right;
               if(temp==NULL)
               {
                    temp = s1.top();
                    s1.pop();
                    ans.push_back(temp->val);
                    while(!s1.empty() && (temp==s1.top()->right))
                    {
                        temp=s1.top();
                        ans.push_back(temp->val);
                        s1.pop();
                    }
               }
               else 
               {
                cur=temp;
               }
            }
        }
        while(!s1.empty())
        {
            ans.push_back(s1.top()->val);
            s1.pop();
        }
        return ans;
    }
};