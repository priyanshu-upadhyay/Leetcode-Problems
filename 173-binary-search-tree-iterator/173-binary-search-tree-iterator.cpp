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
class BSTIterator {
public:
    TreeNode* curr;
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        curr = root;
    }
    
    int next() {
        while(curr!=NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        TreeNode* top = st.top();
        st.pop();
        curr = top->right;
        return top->val;
    }
    
    bool hasNext() {
        if(st.empty() && curr == NULL)
        {
            return false;
        }
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */