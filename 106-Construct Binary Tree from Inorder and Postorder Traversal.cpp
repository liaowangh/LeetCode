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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // clearly the last element of postorder is the root
        // find root in the inorder, suppose is inorder[j]
        // then postorder[0]~postorder[j-1] is the postorder of root->left
        //      inorder[0] ~ inorder[j-1] is the inorder of root->left
        // postorder[j]~end-1 and inorder[j+1]~end are postorder and inorder of
        // root->right respectively
        return helper(postorder, inorder, 0, 0, postorder.size());
    }
    
    TreeNode* helper(vector<int>& postorder, vector<int>& inorder,
                     int i, int j, int len){
        // construct the tree according to postorder[i]~postorder[i+len-1] and
        // inorder[j]~inorder[j+len-1]
        if(len == 0) return NULL;
        TreeNode* root = new TreeNode(postorder[i+len-1]);
        if(len == 1) return root;
        // the root of the tree is preorder[i];
        // find preorder[i] in inorder
        int k;
        for(k = 0; k < len; ++k)
            if(inorder[j + k] == postorder[i+len-1])
                break;
        root->left = helper(postorder, inorder, i, j, k);
        root->right = helper(postorder, inorder, i + k, j + k + 1, len - k - 1);
        return root;
    }
};
