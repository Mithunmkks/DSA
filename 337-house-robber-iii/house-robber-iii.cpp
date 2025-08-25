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
    int maxMoney(TreeNode* root,int prevRob,map<pair<TreeNode*,int>,int>&mp){

        if(!root)return 0;
        if(mp.find({root,prevRob})!=mp.end())return mp[{root,prevRob}];
        int take = 0;
        if(!prevRob)take = root->val + maxMoney(root->left,1,mp) + maxMoney(root->right,1,mp);
        int notTake = maxMoney(root->left,0,mp) + maxMoney(root->right,0,mp);
        return mp[{root,prevRob}] = max(take,notTake);
    }
    int rob(TreeNode* root) {
        map<pair<TreeNode*,int> , int > mp;
        return maxMoney(root,0,mp);
    }
};