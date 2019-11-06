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
//     bool isPalindrome(ListNode* head) {
        
//     }
    
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode* slow = head;
        ListNode* fast = head->next;
        ListNode* prev; // previous node of slow
        while(fast != NULL && fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* head1; // head of the reverse of first half
        ListNode* head2; // head of second half
        head2 = slow->next;
        slow->next = NULL;
        head1 = reverse(head);
        if(fast == NULL)
            head1 = head1->next; // odd number of nodes
        while(head1){
            if(head1->val != head2->val) return false;
            head1 = head1->next;
            head2 = head2->next;
        }
        return true;
    }
    
    ListNode* reverse(ListNode* head){
        // reverse a list, return the new head
        if(!head || !head->next) return head;
        ListNode* newhead = reverse(head->next);
         head->next->next = head;
         head->next = NULL;
         return newhead;
    }
};
