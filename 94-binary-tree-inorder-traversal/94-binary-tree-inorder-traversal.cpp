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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        while(!st.empty() || root != NULL)
        {
            while(root!=NULL)
            {
                st.push(root);
                root = root->left;
            }
            // Ab ek Nikaaalo usme se 
            TreeNode* top = st.top();
            st.pop();
            result.push_back(top->val);
            root = top->right;
        }
        return result;
    }
};