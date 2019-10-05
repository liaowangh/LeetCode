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
    
/************************************************************************/
    // Approach 5: Merge with Divide and Conquer
    // 20 ms, 11 MB
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        int distance = 1;
        while(distance < lists.size()){
            for(int i = 0; i + distance < lists.size(); i += 2 * distance)
                lists[i] = merge2Lists(lists[i], lists[i+distance]);
            distance *= 2;
        }
        return lists[0];
    }
    
    ListNode* merge2Lists(ListNode* l1, ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode* dummyHead = new ListNode(0);
        ListNode* p = dummyHead;
        while(l1 && l2){
            if(l1->val < l2->val){
                p->next = l1;
                l1 = l1->next;
            } else{
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        p->next = !l2 ? l1 : l2;
        return dummyHead->next;
    }
    
/************************************************************************/
    // Approach 2: compare one by one
    // (426 ms, 11.3MB) (O(n) space), 396 ms, 10.6MB(O(1) space)
    // ListNode* mergeKLists(vector<ListNode*>& lists) {
    //     int min_index = 0;
    //     ListNode* head = new ListNode(0);
    //     ListNode* h = head;
    //     while(true){
    //         bool isbreak = true;
    //         int min = INT_MAX;
    //         for(int i = 0; i < lists.size(); ++i){
    //             if(lists[i] && lists[i]->val < min){
    //                 min_index = i;
    //                 min = lists[i]->val;
    //                 isbreak = false;
    //             }
    //         }
    //         if(isbreak) break;
    //         // h->next = new ListNode(min);
    //         h->next = lists[min_index];
    //         h = h->next;
    //         lists[min_index] = lists[min_index]->next;
    //     }
    //     return head->next;
    // }
    
/************************************************************************/
//     Approach 1: Brute Force. Memory Limit Exceeded
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         vector<int> nodes;
//         for(auto l : lists)
//             while(l)
//                 nodes.push_back(l->val);
//         sort(nodes.begin(), nodes.end());
//         ListNode* newhead = new ListNode(0);
//         ListNode* p = newhead;
        
//         for(int x : nodes){
//             p->next = new ListNode(x);
//             p = p->next;
//         }
//         return newhead->next;
//     }
/************************************************************************/

};
