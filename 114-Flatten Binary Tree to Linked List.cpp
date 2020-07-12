/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution{
public:
    void flatten(TreeNode* root) {
        flatten(root, NULL);
    }
private:
    TreeNode* flatten(TreeNode* root, TreeNode* pre) {
        if(!root) return pre;
        pre=flatten(root->right,pre);
        pre=flatten(root->left,pre);
        root->right = pre;
        root->left = NULL;
        return root;
    }
    
};

// class Solution {
// public:
//     void flatten(TreeNode* root) {
//         if(!root) return ;
//         flatten(root->right);
//         TreeNode* right = root->right;
//         flatten(root->left);
//         root->right = root->left;
//         root->left = NULL;
//         TreeNode* tmp = root;
//         while(tmp->right) tmp = tmp->right;
//         tmp->right = right;
//     }
    
    
// };
