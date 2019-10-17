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
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        int res = 0;
        helper(root, sum, res);
        res += pathSum(root->left, sum);
        res += pathSum(root->right, sum);
        return res;
    }
    
    void helper(TreeNode* root, int sum, int& res){
        if(root == NULL) return;
        if(sum == root->val) res++;
        helper(root->left, sum - root->val, res);
        helper(root->right, sum - root->val, res);
    }
};
