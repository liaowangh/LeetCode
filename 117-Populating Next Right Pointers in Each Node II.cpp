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
        if(!root || (!root->left && !root->right)) return root;
        Node* cur = root;
        Node* nextdummyHead = new Node(0);
        Node* prev = nextdummyHead;
        while(cur){
            if(cur->left){
                prev->next = cur->left;
                prev = prev->next;
            }
            if(cur->right){
                prev->next = cur->right;
                prev = prev->next;
            }
            if(cur->next)
                cur = cur->next;
            else{
                cur = nextdummyHead->next;
                nextdummyHead->next = NULL;
                prev = nextdummyHead;
            }
        }
        return root;
    }
    
};
