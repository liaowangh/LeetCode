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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        rightSide(root, res, 0);
        return res;
    }
    
    // At each level, the rightmost node is pushed to the vector firstly,
    // after pushing, condition res.size() == level is never satisfied at this level,
    // so other node in this level won't be pushed into the vector.
    void rightSide(TreeNode* root, vector<int>& res, int level){
        if(!root) return;
        if(res.size() == level){
            res.push_back(root->val);
        }
        rightSide(root->right, res, level + 1);
        rightSide(root->left, res, level + 1);
    }
    
};

// class Solution {
// public:
//     vector<int> rightSideView(TreeNode* root) {
//         vector<int> res;
//         queue<TreeNode*> que;
//         if(!root) return res;
//         que.push(root);
//         while(!que.empty()){
//             res.push_back(que.back()->val);
//             queue<TreeNode*> tmp;
//             while(!que.empty()){
//                 TreeNode* p = que.front();
//                 if(p->left) tmp.push(p->left);
//                 if(p->right) tmp.push(p->right);
//                 que.pop();
//             }
//             que = tmp;
//         }
//         return res;
//     }
// };
