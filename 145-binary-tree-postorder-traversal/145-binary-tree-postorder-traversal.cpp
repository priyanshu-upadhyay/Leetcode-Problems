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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        while(!st.empty() || root != NULL)
        {
            while(root != NULL)
            {
                st.push(root);
                result.push_back(root->val);
                root = root->right;
            }
            TreeNode* rightMost = st.top();
            st.pop();
            root = rightMost->left;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};