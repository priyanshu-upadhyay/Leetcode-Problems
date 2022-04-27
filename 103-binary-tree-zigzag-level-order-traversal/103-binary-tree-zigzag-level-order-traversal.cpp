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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);
        int alter = 1;
        while(!q.empty() && root!=NULL)
        {
            int size = q.size();
            vector<int> subArray(size);
            
            for(int i = 0; i < size; i++)
            {
                TreeNode* front = q.front();
                q.pop();
                int index;
                if(alter%2)
                {
                    index = i;
                }
                else
                {
                    index = size - 1 - i;
                }
                
                
                subArray[index] = front->val;
                
                
                if(front->left != NULL)
                {
                    q.push(front->left);
                }
                if(front->right != NULL)
                {
                    q.push(front->right);
                }
            }
            result.push_back(subArray);
            alter++;
        }
        return result;
    }
};