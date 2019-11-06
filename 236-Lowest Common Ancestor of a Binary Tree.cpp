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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(!left) return right;
        if(!right) return left;
        return root;
    }
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
//         // if(root == p || root == q) return root;
//         // store the nodes that are ancestors of p or q.
//         unordered_map<TreeNode*, bool> ancestor_p;
//         unordered_map<TreeNode*, bool> ancestor_q;
//         ancestor_p[root] = true;
//         ancestor_q[root] = true;
//         return helper(root, p, q, ancestor_p, ancestor_q);
//     }
    
//     TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q,
//                      unordered_map<TreeNode*, bool>& ancestor_p,
//                      unordered_map<TreeNode*, bool>& ancestor_q){
//         if(root == p || root == q) return root;
//         if(isAncestor(root->left, p, ancestor_p) &&
//            isAncestor(root->left, q, ancestor_q))
//             return helper(root->left, p, q, ancestor_p, ancestor_q);
//         else if (isAncestor(root->right, p, ancestor_p) &&
//                  isAncestor(root->right, q, ancestor_q))
//             return helper(root->right, p, q, ancestor_p, ancestor_q);
//         else
//             return root;
//     }
    
//     bool isAncestor(TreeNode* root, TreeNode* p,
//                       unordered_map<TreeNode*, bool>& ancestor){
//         // return true if root is ancestor of p.
//         if(!root) return false;
//         if(ancestor.count(root)) return ancestor[root];
//         if(root == p)
//             ancestor[root] = true;
//         else
//             ancestor[root] = isAncestor(root->left, p, ancestor) ||
//                              isAncestor(root->right, p, ancestor);
//         return ancestor[root];
//     }
    
    
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if(root == p || root == q) return root;
//         unordered_map<TreeNode*, TreeNode*> parent;
//         FindParent(parent, root, p, q);
//         unordered_set<TreeNode*> ancestor_p;
//         TreeNode* tmp = p;
//         while(tmp != root){
//             ancestor_p.insert(tmp);
//             tmp = parent[tmp];
//         }
//         ancestor_p.insert(root);
        
//         tmp = q;
//         while(1){
//             if(ancestor_p.count(tmp))
//                 break;
//             tmp = parent[tmp];
//         }
//         return tmp;
//     }
    
//     void FindParent(unordered_map<TreeNode*, TreeNode*>& parent, TreeNode* root,
//                     TreeNode* p, TreeNode* q){
//         if(parent.count(p) && parent.count(q))
//             return;
//         if(root->left){
//             parent[root->left] = root;
//             FindParent(parent, root->left, p, q);
//         }
//         if(root->right){
//             parent[root->right] = root;
//             FindParent(parent, root->right, p, q);
//         }
//     }
};
