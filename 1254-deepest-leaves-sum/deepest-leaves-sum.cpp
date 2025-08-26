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
    int height(TreeNode* root){
        if(!root)return 0;
        return 1+max(height(root->left),height(root->right));
    }
    int deepestLeavesSum(TreeNode* root) {
        int H = height(root);
        queue<TreeNode*> q;
        q.push(root);
        for(int i=1;i<H;i++){
            int k = q.size();
            while(k--){
                auto node = q.front();
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
        }
        int ans =0;
        while(!q.empty()){
            ans+=q.front()->val;
            q.pop();
        }
        return ans;
    }
};