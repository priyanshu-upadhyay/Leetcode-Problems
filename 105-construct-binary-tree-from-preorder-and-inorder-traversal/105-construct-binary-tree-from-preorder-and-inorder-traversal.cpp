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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        if(inorder.empty()) return NULL;
        int num = preorder.front();
        TreeNode* root = new TreeNode(num);
        auto itr = find(inorder.begin(), inorder.end(), num);
        preorder.erase(preorder.begin()); // removing first element
        
        vector<int> leftPart(inorder.begin(), itr);      // ek kum tak he chalta h islye itr-- ki need nhi hai
        vector<int> rightPart(itr + 1, inorder.end());
        
        root->left = buildTree(preorder, leftPart);
        root->right = buildTree(preorder, rightPart);
        
        return root;
        
    }
};