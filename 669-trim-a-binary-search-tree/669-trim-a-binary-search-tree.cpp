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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        
        if(root == NULL) return NULL;
        
        if(low > root->val)
        {
            // root->left = NULL; (Optional)
            root = trimBST(root->right, low, high);
        }
        else if(high < root->val)
        {
            // root->right = NULL;
            root = trimBST(root->left, low, high);
        }
        else
        {
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
        }
        return root;
    }
};