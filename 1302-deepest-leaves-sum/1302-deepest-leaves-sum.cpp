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
    int deepestLeavesSum(TreeNode* root) {
        int res = 0, i;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            res = 0;
            int size = q.size();
            for (int i = 0; i < size; i++) 
            {
                TreeNode* node = q.front(); q.pop();
                res += node->val;
                if (node->right) q.push(node->right);
                if (node->left)  q.push(node->left);
            }
        }
        return res;
    }
};