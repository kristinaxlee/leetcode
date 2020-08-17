/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode *createNode(int val) {

        return new ListNode(val);

    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // create new linked list to hold the answers
        ListNode *answer = createNode(0);

        // pointer to previous node in answer
        ListNode *prev = answer;

        //create pointers to hold the current node for l1 and l2
        ListNode *l1_cur = l1;
        ListNode *l2_cur = l2;


        //create variable for carry
        int carry = 0;

        // keep going to the end of the two lists
        while(1) {

            //if one node is null or the other is null
            int a = 0;
            int b = 0;

            if(l1_cur != NULL) {
                a = l1_cur->val;
            }

            if(l2_cur != NULL) {
                b = l2_cur->val;
            }

            // put value in previous node
            int sum = a + b + carry;
            carry = 0;

            if(sum >= 10) {
                carry++;
                sum -= 10;
            }

            prev->val = sum;

            // set prev next to null
            prev->next = NULL;

            // move to next element in l1 and l2
            if(l1_cur != NULL) {
                l1_cur = l1_cur->next;
            }

            if(l2_cur != NULL) {
                l2_cur = l2_cur->next;
            }

            //if there are more numbers, create more nodes and keep going
            if(!l1_cur && !l2_cur && carry == 0) {
                break;
            }

            prev->next = createNode(0);
            prev = prev->next;

        }

        return answer;

    }
};
