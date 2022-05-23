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
    TreeNode* createBSTUsingArray(int start, int end, vector<int>& arr)
    {
        if(start > end) return NULL;
        
        int mid = (start + end) >> 1;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = createBSTUsingArray(start, mid - 1, arr);
        root->right = createBSTUsingArray(mid + 1, end, arr);
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        stack<TreeNode*> st;
        while(!st.empty() || root != NULL)
        {
            while(root != NULL)
            {
                st.push(root);
                root = root->left;
            }
            TreeNode* top = st.top();
            st.pop();
            arr.push_back(top->val);
            root = top->right;
        }
        int size = arr.size();
        TreeNode* new_root = createBSTUsingArray(0, size - 1, arr);
        return new_root;
    }
};