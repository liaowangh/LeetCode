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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        helper(res, root, 0);
        return res;
    }
    
    void helper(vector<vector<int>>& res, TreeNode* root, int depth){
        if(root == NULL) return;
        if(depth == res.size()) res.push_back(vector<int>());
        res[depth].push_back(root->val);
        
        helper(res, root->left, depth + 1);
        helper(res, root->right, depth + 1);
    }
    
    //     vector<vector<int>> levelOrder(TreeNode* root) {
    //         vector<vector<int>> res;
    //         if(!root) return res;
    //         queue<TreeNode*> curr;
    //         curr.push(root);
    //         while(!curr.empty()){
    //             vector<int> tmp;
    //             queue<TreeNode*> next;
    
    //             while(!curr.empty()){
    //                 tmp.push_back(curr.front()->val);
    //                 if(curr.front()->left) next.push(curr.front()->left);
    //                 if(curr.front()->right) next.push(curr.front()->right);
    //                 curr.pop();
    //             }
    //             res.push_back(tmp);
    //             curr = next;
    //         }
    //         return res;
    //     }
};
