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
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        stack<TreeNode*> stack;
        int prev;
        TreeNode* curr = root;
        int k = 0;
        while(curr || !stack.empty()){
            while(curr){
                stack.push(curr);
                curr = curr->left;
            }
            curr = stack.top();
            if(k!= 0 && curr->val <= prev) return false;
            k = 1;
            prev = curr->val;
            stack.pop();
            curr = curr->right;
        }
        return true;
    }
};
