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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head || m == n) return head;
        ListNode* curr = head;
        ListNode* prev;
        ListNode* next;
        ListNode* p1;
        ListNode* p2;
        int pos = 1;
        while(pos != m){
            p1 = curr;
            curr = curr->next;
            pos++;
        }
        p2 = curr;
        
        prev = curr;
        next = curr->next;
        while(pos != n){
            curr = next;
            next = next->next;
            curr->next = prev;
            prev = curr;
            pos++;
        }
        if(m == 1){
            p2->next = next;
            return curr;
        }
        p1->next = curr;
        p2->next = next;
        return head;
    }
};
