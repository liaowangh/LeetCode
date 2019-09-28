/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        helper(root, NULL);
        return root;
        // if(!root) return root;
        // root->next = NULL;
        // Node* p = root;
        // while(!p and !p->left){
        //     Node* q = p;
        //     while(q){
        //         q->left->next = q->right;
        //         q->right->next = q->next ? q->next->left : NULL;
        //         q = q->next;
        //     }
        //     p = p->left;
        // }
        // return root;
    }
    
    void helper(Node* left, Node* right){
        if(left == NULL) return;
        left->next = right;
        helper(left->left, left->right);
        helper(left->right, right ? right->left : NULL);
        if(right)
            helper(right->left, right->right);
    }
    
};
