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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* prev = head;
        ListNode* curr = head->next;
        // ListNode* dummyHead = new ListNode(0);
        //dummyHead.next = head;
        ListNode dummyHead(0);
        dummyHead.next = head;
        // head ~ prev is sorted, we need the insert curr into sorted part
        while(curr){
            ListNode* tmp = curr->next;
            ListNode* insertPoint = &dummyHead;
            while(insertPoint != prev && curr->val > insertPoint->next->val){
                insertPoint = insertPoint->next;
            }
            if(insertPoint == prev){
                prev = curr;
                curr = curr->next;
            } else{
                curr->next = insertPoint->next;
                insertPoint->next = curr;
                prev->next = tmp;
                curr = tmp;
            }
        }
        // return dummyHead->next;
        return dummyHead.next;
    }
};
