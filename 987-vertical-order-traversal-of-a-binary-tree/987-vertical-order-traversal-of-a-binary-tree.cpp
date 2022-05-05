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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while(!q.empty())
        {
            TreeNode* node = q.front().first;
            pair<int, int> curr = q.front().second;
            q.pop();
            mp[curr.first][curr.second].insert(node->val);
            if(node->left != NULL) q.push({node->left, {curr.first  - 1, curr.second + 1}});
                                           
            if(node->right != NULL) q.push({node->right, {curr.first + 1, curr.second + 1}});
                                           
        }
        
        vector<vector<int>> result; 
        for(auto i : mp)
        {
            vector<int> curr;
            cout<<i.first<<"\n";
            for(auto j : i.second)
            {
                for(int k : j.second)
                    curr.push_back(k);
            }
            result.push_back(curr);
        }
        return result;
    }
};