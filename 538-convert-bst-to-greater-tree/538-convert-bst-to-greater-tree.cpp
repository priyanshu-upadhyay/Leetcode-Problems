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

    TreeNode* convertBST(TreeNode* root) {
        
        int sum = 0;
        stack<TreeNode*> st;
        TreeNode* head = root;
        while(!st.empty() || root != NULL)
        {
            while(root != NULL)
            {
                st.push(root);
                root = root->right;
            }
            TreeNode* rightMost = st.top();
            st.pop();
            sum += rightMost->val;
            rightMost->val = sum;
            root = rightMost->left;
        }
        return head;
    }
};