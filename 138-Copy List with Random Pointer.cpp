/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        Node* p = head;
        while(p){
            Node* tmp = new Node(p->val, p->next, NULL);
            p->next = tmp;
            p = tmp->next;
        }
        p = head;
        while(p){
            if(p->random)
                p->next->random = p->random->next;
            p = p->next->next;
        }
        p = head;
        Node* new_head = p->next;
        Node* q = new_head;
        while(p && q){
            p->next = q->next;
            q->next = p->next ? p->next->next : NULL;
            p = p->next;
            q = q->next;
        }
        return new_head;
    }
};
