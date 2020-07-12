/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class BSTIterator {
public:
    BSTIterator(TreeNode* root){
        cur = root;
        if(!root) return;
        while(cur){
            stk.push(cur);
            cur = cur->left;
        }
    }
        /** @return the next smallest number */
    int next() {
        while(cur){
            stk.push(cur);
            cur = cur->left;
        }
        cur = stk.top();
        stk.pop();
        int res = cur->val;
        cur = cur->right;
        return res;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return cur || !stk.empty();
    }
    
private:
    stack<TreeNode*> stk;
    TreeNode* cur;
};

// void build_parent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent){
//     if(!root) return;
//     parent[root] = nullptr;
//     queue<TreeNode*> level;
//     level.push(root);
//     while(!level.empty()){
//         TreeNode* cur = level.front();
//         level.pop();
//         if(cur->left){
//             parent[cur->left] = cur;
//             level.push(cur->left);
//         }
//         if(cur->right){
//             parent[cur->right] = cur;
//             level.push(cur->right);
//         }
//     }
// }


// class BSTIterator {
// public:
//     BSTIterator(TreeNode* root) {
//         dummy = new TreeNode(0);
//         cur = root;
//         largest = root;
//         if(!root) return;
//         while(cur->left)
//             cur = cur->left;
//         while(largest->right)
//             largest = largest->right;
//         dummy->right = cur;
//         cur = dummy;
//         build_parent(root, parent);
//     }
    
//     /** @return the next smallest number */
//     int next() {
//         if(cur->right){
//             cur = cur->right;
//             while(cur->left)
//                 cur = cur->left;
//         }else{
//             TreeNode* p = parent[cur];
//             while(cur != p->left){
//                 cur = p;
//                 p = parent[cur];
//             }
//             cur = p;
//         }
//         return cur->val;
//     }
    
//     /** @return whether we have a next smallest number */
//     bool hasNext() {
//         if(!cur) return false;
//         return cur != largest;
//     }
// private:
//     TreeNode* cur;
//     TreeNode* dummy;
//     TreeNode* largest;
//     unordered_map<TreeNode*, TreeNode*> parent;
// };

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
