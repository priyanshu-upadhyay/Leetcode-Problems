// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    private:
    bool check(int i, int j, int n, int m, vector<vector<int>>& grid)
    {
        if(i < 0 || i == n || j < 0 || j == m || grid[i][j] == 0) return false;
        if(grid[i][j] == 2) return true;
        grid[i][j] = 0;
        return check(i + 1,  j,  n,  m, grid) || check(i,  j + 1,  n,  m, grid) || check(i - 1 ,  j,  n,  m, grid) || check(i,  j - 1,  n,  m, grid);
    }
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>> grid) 
    {
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                {
                    return check(i,  j,  n,  m, grid);
                }
            }
        }
        return false;
        
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends