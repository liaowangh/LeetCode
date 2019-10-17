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
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int pass_root = depth(root->left) + depth(root->right);
        int notpass_root = max(diameterOfBinaryTree(root->left),
                               diameterOfBinaryTree(root->right));
        return max(pass_root, notpass_root);
    }
    
    int depth(TreeNode* root){
        if(!root) return 0;
        return 1 + max(depth(root->left), depth(root->right));
    }
};
