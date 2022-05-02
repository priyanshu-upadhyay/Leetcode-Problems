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
    
    ListNode* reverse(ListNode* head)
    {
        ListNode *p = NULL, *q = NULL, *r = head;
        while(r != NULL)
        {
            p = q;
            q = r;
            r = r->next;
            q->next = p;
        }
        return q;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while(slow && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast != NULL)
        {
            slow = slow->next;
        }
        ListNode* newReverse = reverse(slow);
        
        while(newReverse!=NULL && head!=NULL)
        {
            if(newReverse->val != head->val)
            {
                
                return false;
            }
            newReverse = newReverse->next;
            head = head->next;
        }
        
        return true;
    }
};