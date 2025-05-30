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
    void f(TreeNode* root,string temp,vector<string> &ans)
    {
        if(!root->left && !root->right)
        {
            temp+=to_string(root->val);
            ans.push_back(temp);
            return;
        }
        else 
        {
            temp+=to_string(root->val);
            temp+="->";
            if(root->left)f(root->left,temp,ans);
            if(root->right)f(root->right,temp,ans);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(!root)return ans;
        f(root,"",ans);
        return ans;
    }
};