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
    int kthSmallest(TreeNode* root, int k) {
        
        TreeNode* curr = root;
        stack<TreeNode*> st;
        int count = 0;
        while(!st.empty() || curr != NULL)
        {
            while(curr != NULL)
            {
                st.push(curr);
                curr = curr->left;
            }
            count++;
            TreeNode* topElement = st.top();
            curr = topElement->right;
            st.pop();
            if(count == k)
            {
                return topElement->val;
            }
        }
        return 0;
    }
};