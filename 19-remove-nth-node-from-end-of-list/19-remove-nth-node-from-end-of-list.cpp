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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *first = head, *second = head;
        while(n > 0)
        {
            second = second->next;
            n--;
        }
        ListNode* prev = NULL;
        while(second !=  NULL)
        {
            prev = first;
            first = first->next;
            second = second->next;
        }
        
        // Fist Element he ho wo
        
        if(prev == NULL)
        {
            head = first->next;
        }
        else
        {
            prev->next = first->next;
        }
        
        
        return head;
    }
};