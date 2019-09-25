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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        
        stack<TreeNode*> cur;
        stack<TreeNode*> next;
        int level = 1;  // odd level push left first, even level push right first
        next.push(root);
        while(!next.empty()){
            vector<int> inst;
            swap(cur, next);
            while(!cur.empty()){
                TreeNode* tmp = cur.top();
                inst.push_back(tmp->val);
                if(level % 2){
                    if(tmp->left) next.push(tmp->left);
                    if(tmp->right) next.push(tmp->right);
                } else{
                    if(tmp->right) next.push(tmp->right);
                    if(tmp->left) next.push(tmp->left);
                }
                cur.pop();
            }
            level++;
            res.push_back(inst);
        }
        return res;
    }
};
