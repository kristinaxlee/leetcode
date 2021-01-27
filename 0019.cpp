/**
 * Solution Explanation:
 *  We can have 2 pointers to keep track of where we are in the array. 
 *  If we move the fast pointer n+1 spots ahead of the slow pointer, by the time the fast pointer reaches the end of the list
 *  the slow pointer will be at the node before the one we want to remove. There, we can remove it.
 *  We also need a sentinel node at the beginning, because if we want to delete the first node, then this will
 *  help with out of bounds issues.
 * 
 *  Case 1:
 *  1 - 2 - 3 - 4 - 5 - 6, n = 2 (which is 5)
 *  We'll move the fast pointer to 2.
 *  Fast: 2->3->4->5->6
 *  Slow: 0->1->2->3->4
 * 
 *  Now that fast is pointing to the last node, we know to remove slow's next node
 */
class Solution {
public:
    
  ListNode* removeNthFromEnd(ListNode* head, int n) {
      
    ListNode *dummy = new ListNode();
    dummy->next = head;
    ListNode *slow = dummy, *fast = dummy;
    
    if(head->next == NULL) {
        return NULL;
    }
    
    // move the fast node ahead
    for(int i = 0; i < n; i++) {
        fast = fast->next;
    }
    
    // move the slow node to the node before the node to remove
    while(fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    
    // remove the node
    ListNode *temp = slow->next;
    slow->next = slow->next->next;
    
    // check if the temp node is the head, and reassign if necessary
    if(temp == head) {
        head = temp->next;
    }
    
    delete(temp);
    
    return head;
  }
};