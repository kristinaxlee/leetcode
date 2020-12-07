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
    bool hasCycle(ListNode *head) {
        ListNode *tortoise = head;
        ListNode *hare;
        
        if(head == NULL || head->next == NULL) {
            return false;
        }
        
        else {
            hare = head->next;
        }
        
        while(hare->next != NULL && hare->next->next != NULL) {
            
            if(tortoise == hare) {
                return true;
            }
            
            tortoise = tortoise->next;
            hare = hare->next->next;
            
        }
        
        return false;
        
    }
};