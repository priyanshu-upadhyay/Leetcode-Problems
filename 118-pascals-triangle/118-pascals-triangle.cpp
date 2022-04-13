class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(int i = 0; i < numRows; i++)
        {
            vector<int> inner(i+1, 1);
            result.push_back(inner);
        }
        for(int i = 0; i < numRows - 1; i++)
        {
            int k = 1;
            for(int j = 0; j < i; j++)
            {
                result[i+1][k++] = result[i][j] + result[i][j+1];
            }
        }
        return result;
    }
};