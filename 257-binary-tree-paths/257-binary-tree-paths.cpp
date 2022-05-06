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
    void tracePath(TreeNode* root, string curr, vector<string> &result)
    {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL)
        {
            curr = curr + to_string(root->val);
            result.push_back(curr);
            return;
        }
        curr = curr + to_string(root->val) + "->";
        tracePath(root->left, curr, result);
        tracePath(root->right, curr, result);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        tracePath(root, "", result);
        return result;
    }
};