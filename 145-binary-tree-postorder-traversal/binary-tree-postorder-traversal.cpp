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
        stack<TreeNode*> s1,s2;
        auto cur = root;
        while(!s1.empty() || cur)
        {
            if(cur)
            {
                s1.push(cur);
                cur=cur->left;
            }
            else 
            {

                if(s1.top()->right)
                {
                        if(!s2.empty() && (s1.top()->right==s2.top()))
                        {
                            s2.push(s1.top());
                            s1.pop();
                        }
                        else cur=s1.top()->right;
                }
                else 
                {
                    s2.push(s1.top());
                    s1.pop();
                }
            }
        }
        vector<int> ans;
        while(!s2.empty())
        {
            ans.push_back(s2.top()->val);
            s2.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};