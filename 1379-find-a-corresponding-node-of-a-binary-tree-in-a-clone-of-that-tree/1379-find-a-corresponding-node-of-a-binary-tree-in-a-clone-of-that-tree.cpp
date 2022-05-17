/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* root = cloned;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* front = q.front();
            q.pop();
            if(front->val == target->val) return front;
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
        return NULL;
    }
};