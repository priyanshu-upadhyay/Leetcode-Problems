// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
private:
    int dfsAndDp(int row, int col, int prev, vector<vector<int>>& matrix, int n, int m, vector<vector<int>>& dp)
    {
        if(row < 0 || col < 0 || row >= n || col >= m || prev >= matrix[row][col])
        {
            return 0;
        }
        
        if(dp[row][col] != -1) return dp[row][col];
        
        int curr = matrix[row][col];
        // Four Call for Left, Right, Top, Bottom
        int bottom = dfsAndDp(row + 1, col, curr, matrix, n, m, dp);
        int right = dfsAndDp(row, col + 1, curr, matrix, n, m, dp);
        int top = dfsAndDp(row - 1, col, curr, matrix, n, m, dp);
        int left = dfsAndDp(row, col - 1, curr, matrix, n, m, dp);
        
        dp[row][col] = 1 + max(bottom, max(right, max(top, left)));
        return dp[row][col];
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        int max_length = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(dp[i][j] == -1)
                {
                    int curr_length = dfsAndDp(i, j, -1, matrix, n, m, dp);
                    max_length = max(max_length, curr_length);
                }
            }
        }
        return max_length;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>matrix(n, vector<int>(m, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)cin >> matrix[i][j];
		Solution obj;
		int ans = obj.longestIncreasingPath(matrix);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends