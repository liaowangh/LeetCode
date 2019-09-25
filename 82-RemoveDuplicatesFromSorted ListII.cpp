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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* p1 = new ListNode(0);
        ListNode* p2 = head;
        head = p1;
        while(p2){
            int count = 0;
            while(p2 && p2->next && p2->val == p2->next->val){
                p2 = p2->next;
                count++;
            }
            if(count){
                p1->next = p2->next;
                p2 = p2->next;
            } else{
                p1->next = p2;
                p1 = p2;
                p2 = p2->next;
            }
        }
        return head->next;
    }
};
