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
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        long maxSize = 1;
        
        while(!q.empty())
        {
            long leftMost = q.front().second;
            long rightMost = q.back().second;
            long size = q.size();
            maxSize = max(maxSize, rightMost-leftMost+1);
            for(long i = 0; i < size; i++)
            {
                auto front = q.front();
                long indx = front.second;
                if(front.first->left != NULL) q.push({front.first->left, indx * 2 + 1});
                if(front.first->right != NULL) q.push({front.first->right, indx * 2 + 2});
                q.pop();
            }
            
            
        }
        return maxSize;
    }
};