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
    // ListNode* reverseList(ListNode* head) {
    //     if(!head || !head->next) return head;
    //     ListNode* prev = head;
    //     ListNode* curr = head->next;
    //     ListNode* next = head->next;
    //     head->next = NULL;
    //     while(next){
    //         curr = next;
    //         next = next->next;
    //         curr->next = prev;
    //         prev = curr;
    //     }
    //     head->next = NULL;
    //     return curr;
    // }
    
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* new_head = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return new_head;
    }
};
