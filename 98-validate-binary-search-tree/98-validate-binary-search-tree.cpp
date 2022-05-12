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
    bool isValidBST(TreeNode* root) {
        int prev;
        int flag = 0;
        stack<TreeNode*> st;
        while(!st.empty() || root != NULL)
        {
            while(root != NULL)
            {
                st.push(root);
                root = root->left;
            }
            TreeNode* top = st.top();
            st.pop();
            if(flag == 1 && prev >= top->val) 
            {
                return false;
            }
            flag = 1;
            prev = top->val;
            root = top->right;
        }
        return true;
    }
};