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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next) return head;
        ListNode* small_head = new ListNode(0);
        ListNode* big_head = new ListNode(0);
        ListNode* p1 = small_head;
        ListNode* p2 = big_head;
        
        while(head){
            if(head->val < x){
                p1->next = head;
                p1 = p1->next;
            } else{
                p2->next = head;
                p2 = p2->next;
            }
            head = head->next;
        }
        p1->next = big_head->next;
        p2->next = NULL;
        return small_head->next;
    }
    
};
