/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // reverse first k nodes, then use recursive to reverse the
        // next n-k nodes.
        if(!head || !head->next || k == 1) return head;
        ListNode* q = head;
        int i = 1;
        while(q->next && i < k){
            q = q->next;
            ++i;
        }
        if(i < k) return head;
        ListNode* p = reverseKGroup(q->next, k);
        q->next = NULL;
        ListNode* newHead = reverse(head);
        head->next = p;
        return newHead;
    }
    
    ListNode* reverse(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* newhead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return newhead;
    }
    
};
