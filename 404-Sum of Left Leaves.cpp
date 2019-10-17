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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        int res = 0;
        res += isLeaf(root->left) ? root->left->val : sumOfLeftLeaves(root->left);
        res += sumOfLeftLeaves(root->right);
        return res;
    }
    
    bool isLeaf(TreeNode* node){
        if(!node) return false;
        return node->left == NULL and node->right == NULL ?
               true : false;
    }
};
