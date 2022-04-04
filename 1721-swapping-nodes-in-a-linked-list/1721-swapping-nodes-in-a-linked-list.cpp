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
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode* current = head;
        ListNode* begNode;
        ListNode* lastNode;
        int c = 1;
        int n = 0;
        
        while(current!=NULL)
        {
            n++;
            current = current->next;
        }
        
        current = head;
        int f1 = 0;
        int f2 = 0;
        while(current!=NULL)
        {
            if(c == k)
            {
                begNode = current;
                f1 = 1;
            }
            if(c == n-k+1)
            {
                lastNode = current;
                f1 = 1;
            }
            if(f1 == 1 && f2 ==1)
            {
                break;
            }
            c++;
            current = current->next;
        }
        int temp = begNode->val;
        begNode->val = lastNode->val;
        lastNode->val = temp;
        return head;
        
        
        
    }
};