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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> st;
        while(!st.empty() || (p != NULL && q != NULL))
        {
            while(p != NULL && q != NULL)
            {
                st.push(p);
                st.push(q);
                p = p->left;
                q = q->left;
            }
            
            if(p != NULL || q != NULL) return false;
            TreeNode* qTop = st.top();
            st.pop();
            TreeNode* pTop = st.top();
            st.pop();
            // cout<<qTop->val<<" "<<pTop->val<<"\n";
            if(qTop->val != pTop->val) return false;
            q = qTop->right;
            p = pTop->right;
        }
        
        if(p != NULL || q != NULL) return false;
        return true;
    }
};