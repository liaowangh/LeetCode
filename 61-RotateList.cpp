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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k == 0) return head;
        int n = 1; // lenght of the list
        ListNode* p1 = head;
        while(p1->next){
            p1 = p1->next;
            n++;
        }
        // now p1 points to the last node
        int m = n - k % n;
        if(m == 0) return head;
        ListNode* p2 = head;
        for(int i = 0; i < m - 1; ++i)
            p2 = p2->next;
        p1->next = head;
        head = p2->next;
        p2->next = NULL;
        return head;
    }
};
