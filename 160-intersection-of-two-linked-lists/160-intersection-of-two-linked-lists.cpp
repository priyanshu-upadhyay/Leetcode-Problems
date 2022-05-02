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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *first = headA, *second = headB;
        int enterA = 0, enterB = 0;
        while(first != NULL && second != NULL)
        {
            if(first == second)
            {
                return second;
            }
            first = first->next;
            second = second->next;
            
            if(enterB == 0 && second == NULL)
            {
                enterB = 1;
                second = headA;
            }
            
            if(enterA == 0 && first == NULL)
            {
                enterA = 1;
                first = headB;
            }
        }
        return NULL;
    }
};