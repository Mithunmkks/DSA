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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int len =0;
        while(!q.empty())
        {
            int k = q.size();
            int min = q.front().second;
            int l=0,r=0;
            for(int i=0;i<k;i++)
            {

                auto it = q.front();
                q.pop();
                auto node = it.first;
                int  cnt = it.second;
                if(i==0)l=cnt;
                if(i==k-1)r=cnt;
                if(node->right)q.push({node->right,2*(cnt-min)+1});
                if(node->left)q.push({node->left,2*(cnt-min)+2});
            }
            len=max(len,r-l+1);
        }
        return len;
    }
};