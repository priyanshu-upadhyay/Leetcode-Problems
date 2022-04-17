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
    TreeNode* result = NULL;
    TreeNode* pre = NULL;
public:
    void helper(TreeNode* root)
    {
        if(root == NULL) return;
        helper(root->left);
        if(result == NULL)
        {
            result = root;
        }
        else
        {
            pre->right = root;
        }
        
        pre = root;
        root->left = NULL;
        helper(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        helper(root);
        return result;
    }
};