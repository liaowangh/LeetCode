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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* head1 = head;
        ListNode* head2 = reverse(slow->next);
        slow->next = NULL;
        while(head2){
            ListNode* tmp = head2->next;
            head2->next = head1->next;
            head1->next = head2;
            head1 = head1->next->next;
            head2 = tmp;
        }
    }
    
    ListNode* reverse(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* pre = NULL;
        ListNode* cur = head;
        while(cur){
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
    
    // ListNode* reverse(ListNode* head){
    //     if(!head || !head->next) return head;
    //     ListNode* newHead = reverse(head->next);
    //     head->next->next = head;
    //     head->next = NULL;
    //     return newHead;
    // }
    
};
