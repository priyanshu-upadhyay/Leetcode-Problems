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
        int cameras = 0;
public:
    int minCameraCoverHelper(TreeNode* root)
    {
        if(root == NULL) return 1;
        
        int left = minCameraCoverHelper(root->left);
        int right = minCameraCoverHelper(root->right);
        
        if(left == -1 || right == -1)
        {
            cameras++;
            return 0;
        }
        if(left == 0 || right == 0)
        {
            return 1;
        }
        //  if(left == 1 || right == 1)   hume to cover kar rkha h ... root bolege to me chala apne papa ke paas
        return -1;
        
    }
    int minCameraCover(TreeNode* root) {
        if(minCameraCoverHelper(root) == -1) cameras++;
        return cameras;
    }
};