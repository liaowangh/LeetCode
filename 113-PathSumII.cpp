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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if(!root) return res;
        vector<int> inst;
        dfs(root, res, inst, sum);
        return res;
    }
    
    void dfs(TreeNode* root, vector<vector<int>>& res, vector<int>& inst,
             int diff){
        if(!root) return;
        if(!root->left && !root->right && root->val == diff){
            inst.push_back(root->val);
            res.push_back(inst);
            inst.pop_back();
            return;
        }
        if(root->left){
            inst.push_back(root->val);
            dfs(root->left, res, inst, diff - root->val);
            inst.pop_back();
        }
        if(root->right){
            inst.push_back(root->val);
            dfs(root->right, res, inst, diff - root->val);
            inst.pop_back();
        }
    }
    
};
