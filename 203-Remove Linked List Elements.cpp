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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* pre = dummyHead;
        ListNode* cur = head;
        while(cur){
            if(cur->val == val){
                pre->next = cur->next;
                cur = cur->next;
            } else {
                pre = pre->next;
                cur = cur->next;
            }
        }
        return dummyHead->next;
    }
};
