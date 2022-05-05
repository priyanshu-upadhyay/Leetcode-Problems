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
        vector<int> result;
        stack<TreeNode*> st;
        while(!st.empty() || root != NULL)
        {
            while(root != NULL)
            {
                st.push(root);
                root = root->left;
            }
            TreeNode* leftMost = st.top();
            st.pop();
            result.push_back(leftMost->val);
            root = leftMost->right;
        }
        return result;
    }
};