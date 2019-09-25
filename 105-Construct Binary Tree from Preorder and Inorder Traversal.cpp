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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // clearly preorder[0] is the root
        // find preorder[0] in the inorder, suppose is inorder[j]
        // then preorder[1]~preorder[j] is the preorder of root->left
        //      inorder[0] ~ inorder[j-1] is the inorder of root->left
        // preorder[j+1]~end and inorder[j+1] are preorder and inorder of
        // root->right respectively
        return helper(preorder, inorder, 0, 0, preorder.size());
    }
    
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,
                     int i, int j, int len){
        // construct the tree according to preorder[i]~preorder[i+len-1] and
        // inorder[j]~inorder[j+len-1]
        if(len == 0) return NULL;
        TreeNode* root = new TreeNode(preorder[i]);
        if(len == 1) return root;
        // the root of the tree is preorder[i];
        // find preorder[i] in inorder
        int k;
        for(k = 0; k < len; ++k)
            if(inorder[j + k] == preorder[i])
                break;
        root->left = helper(preorder, inorder, i+1, j, k);
        root->right = helper(preorder, inorder, i + k + 1, j + k + 1, len - k - 1);
        return root;
    }
    
};
