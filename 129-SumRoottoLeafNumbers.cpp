/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return root->val;
        int res = 0;
        if(root->left) dfs(root->left, res, root->val);
        if(root->right) dfs(root->right, res, root->val);
        return res;
    }
    
    void dfs(TreeNode* root, int& res, int tmp){
        if(!root->left && !root->right){
            res += tmp * 10 + root->val;
            return;
        }
        if(root->left)
            dfs(root->left, res, tmp * 10 + root->val);
        if(root->right)
            dfs(root->right, res, tmp * 10 + root->val);
    }
};
