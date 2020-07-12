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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* last = NULL;
        TreeNode* curr = root;
        while(!stk.empty() || curr){
            if(curr){
                stk.push(curr);
                curr = curr->left;
            } else{
                TreeNode* node = stk.top();
                if(node->right && last != node->right){
                    curr = node->right;
                } else{
                    res.push_back(node->val);
                    stk.pop();
                    last = node;
                }
            }
        }
        return res;
    }
};
