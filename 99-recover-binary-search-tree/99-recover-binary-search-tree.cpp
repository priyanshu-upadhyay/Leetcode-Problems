/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        
        TreeNode* curr = root;
        stack<TreeNode*> st;
        
        TreeNode* first = NULL, *second = NULL;
        TreeNode* prev = NULL;
        int flag = 0;
        while(!st.empty() || curr != NULL)
        {
            while(curr != NULL)
            {
                st.push(curr);
                curr = curr->left;
            }
            TreeNode* top = st.top();
            st.pop();
            if(prev != NULL && flag == 0 && prev->val > top->val)
            {
                first = prev;
                flag = 1;
            }
            if(flag == 1 && prev->val > top->val)
            {
                second = top;
            }
            prev = top;
            curr = top->right;
        }
        // Exchange Values
        int temp = first->val;
        first->val = second->val;
        second->val = temp;

    }
};