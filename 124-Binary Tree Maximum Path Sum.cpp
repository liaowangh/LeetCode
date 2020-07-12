/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// For any path, it must first go up for 0 or several levels and then
// go down 0 or several levels, so there is a higest node.
// We can iterate every node in the tree, treat this node as the higest node,
// compute the maximum path sum.

class Solution {
public:
    int maxValue = INT_MIN;
    
    int maxPathSum(TreeNode* root) {
        maxPathDown(root);
        return maxValue;
    }
    
    // max path sum of the path going down from the input node
    int maxPathDown(TreeNode* root){
        if(!root) return INT_MIN;
        
        int maxLeft = max(0, maxPathDown(root->left));
        int maxRight = max(0, maxPathDown(root->right));
        int maxDown = root->val + max(maxLeft, maxRight);
        
        // the max path sum treating the input node as the higest node.
        int maxCrossRoot = root->val + maxLeft + maxRight;
        maxValue = max(maxValue, maxCrossRoot);
        return maxDown;
    }
};

// class Solution {
// public:
//     int maxPathSum(TreeNode* root) {
//         unordered_map<TreeNode*, int> record;
//         return helper(root, record);
//     }
    
//     int helper(TreeNode* root, unordered_map<TreeNode*, int>& record){
//         if(!root) return INT_MIN;
//         int maxLeft = helper(root->left, record);
//         int maxRight = helper(root->right, record);
//         int crossRoot = maxPathPassRoot(root, record);
//         return max(max(maxLeft, maxRight), crossRoot);
//     }
    
//     int maxPathPassRoot(TreeNode* root, unordered_map<TreeNode*, int>& record){
//         if(!root) return 0;
//         if(!root->left && !root->right) return root->val;
//         int maxPathLeft = maxPath(root->left, record);
//         int maxPathRight = maxPath(root->right, record);
//         maxPathLeft = maxPathLeft > 0 ? maxPathLeft : 0;
//         maxPathRight = maxPathRight > 0 ? maxPathRight : 0;
//         return root->val + maxPathLeft + maxPathRight;
//     }
    
//     int maxPath(TreeNode* root, unordered_map<TreeNode*, int>& record){
//         if(!root) return INT_MIN;
//         if(record.count(root)) return record[root];
//         int res;
//         if(!root->left && !root->right)
//             res = root->val;
//         else{
//             int maxLeft = maxPath(root->left, record);
//             int maxRight = maxPath(root->right, record);
//             int maxLR = max(maxLeft, maxRight);
//             res = root->val + (maxLR > 0 ? maxLR : 0);
//         }
//         record[root] = res;
//         return res;
//     }
    
// };
