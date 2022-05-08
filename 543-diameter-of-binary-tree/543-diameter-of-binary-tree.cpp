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
private:
    int maxDepth(TreeNode* root)
    {
        if(root == NULL) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        TreeNode* curr = root;
        stack<TreeNode*> st;
        int diameter = 0;
        while(!st.empty() || curr != NULL)
        {
            while(curr != NULL)
            {
                st.push(curr);
                curr = curr->left;
            }
            TreeNode* top = st.top();
            st.pop();
            diameter = max(diameter, maxDepth(top->left) + maxDepth(top->right));
            curr = top->right;
        }
        return diameter;
    }
};