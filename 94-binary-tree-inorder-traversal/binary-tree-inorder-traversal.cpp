class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)return {};
        vector<int> ans;
        TreeNode* cur=root;
        while(cur){
            if(!cur->left){
                ans.push_back(cur->val);
                cur=cur->right;
            }
            else {
                TreeNode*  predecessor = cur->left;
                while(predecessor->right && predecessor->right!=cur )predecessor=predecessor->right;
                if(predecessor->right==cur){
                    predecessor->right=NULL;
                    ans.push_back(cur->val);
                    cur=cur->right;
                }
                else if (predecessor->right==NULL){
                    predecessor->right=cur;
                    cur=cur->left;
                }
                
            }

        }
        return ans;
    }
};