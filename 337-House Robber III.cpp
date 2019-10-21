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
    int rob(TreeNode* root) {
        if(!root) return 0;
        unordered_map<TreeNode*, int> map;
        return helper(root, map);
    }
    
    int helper(TreeNode* root, unordered_map<TreeNode*, int>& map){
        if(!root) return 0;
        if(map.find(root) != map.end())
            return map[root];
        int robroot = root->val;
        if(root->left)
            robroot += helper(root->left->left, map) +
                       helper(root->left->right, map);
        if(root->right)
            robroot += helper(root->right->left, map) +
                       helper(root->right->right, map);
        int res = max(robroot, helper(root->left, map) +
                               helper(root->right, map));
        map[root] = res;
        return res;
    }
    
// 28 ms, 28.3MB
//     int rob(TreeNode* root) {
//         vector<int> res = robsub(root);
//         return max(res[0], res[1]);
//     }
    
//     vector<int> robsub(TreeNode* root){
//         if(!root) return vector<int>(2,0);
//         vector<int> res(2,0);
//         vector<int> left = robsub(root->left),
//                     right = robsub(root->right);
//         res[0] = max(left[0], left[1]) + max(right[0], right[1]);
//             // not rob the root
//         res[1] = root->val + left[0] + right[0]; // rob the root
//         return res;
//     }
    
    // time limit exceeded
    // int rob(TreeNode* root) {
    //     if(!root) return 0;
    //     int res1, res2;
    //     res1 = root->val; // rob the root
    //     if(root->left) res1 += rob(root->left->left) + rob(root->left->right);
    //     if(root->right) res1 += rob(root->right->left) +
    //                             rob(root->right->right);
    //     res2 = rob(root->left) + rob(root->right); // not rob the root
    //     return max(res1, res2);
    // }
};
