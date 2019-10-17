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
    // Index the list by 1,2,...,n. Suppose the cycle begins at index k.
    // Use two pointers slow and fast, at time t, the slow walks t steps and
    // fast walks 2t steps, so at time t,
    // the index of slow is (t-k)%(n-k+1)+k,
    // the index of fast is (2t-k)%(n-k+1)+k,
    // when they meet, we have (t1-k)%(n-k+1)=(2t1-k)%(n-k+1)
    // we can further get 2t1-k-(t1-k)=t1=a*(n-k+1),
    // so when slow continue to walk k steps, its index is
    // (t1+k-k)%(n-k+1)+k = k! The start of the cycle!
    // If we let another pointer p start at head and walk k-1 steps then
    // it also reachs the start point, so if we let slow walk one step first
    // and then let slow and p walk together, they will reach the start point
    // at the same time!
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return NULL;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(slow != fast){
            if(fast == NULL || fast->next == NULL) return NULL;
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = head;
        slow = slow->next;
        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
