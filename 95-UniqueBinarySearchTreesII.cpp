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
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return vector<TreeNode*>();
        return genTree(1, n);
    }
    
    vector<TreeNode*> genTree(int begin, int end){
        vector<TreeNode*> res;
        if(begin > end){
            res.push_back(NULL);
            return res;
        }
        if(end == begin){
            res.push_back(new TreeNode(begin));
            return res;
        }
        for(int i = begin; i <= end; i++){
            vector<TreeNode*> ltree = genTree(begin, i-1);
            vector<TreeNode*> rtree = genTree(i+1, end);
            for(auto l : ltree){
                for(auto r: rtree){
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    
};
