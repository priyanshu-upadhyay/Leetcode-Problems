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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head == NULL) return NULL;
        // checking if k elements possible or not.
        bool isPossible = false;
        int c = 0;
        ListNode* curr = head;
        while(curr != NULL)
        {
            c++;
            curr = curr->next;
            if(c == k) isPossible = true;
        }
        
        if(isPossible)
        {
            ListNode *p = NULL, *q = NULL, *r = head;
            int c = 0;
            while(c < k)
            {
                p = q;
                q = r;
                r = r->next;
                q->next = p;
                c++;
            }
            
            head->next = reverseKGroup(r, k);
            return q;
        }
        return head;
    }
};