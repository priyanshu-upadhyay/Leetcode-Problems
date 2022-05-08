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
    bool isBalanced(TreeNode* root) {
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
            if(abs(maxDepth(top->left) - maxDepth(top->right)) > 1) return false;
            curr = top->right;
        }
        return true;
    }
};