// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
 
	public:
	void findAllComb(vector<vector<char>> &mat, int n,int m,int r,int c,int  u,int d, vector<vector<int>> &v, vector<vector<bool>> visited){
	    if(r >= n || c >= m || r < 0 || c < 0 || u < 0 || d < 0){
	        return;
	    }
	    if(mat[r][c] == '#'){
	        return;
	    }
	    if(visited[r][c]){
	        return;
	    }
	    visited[r][c] = true;
	    v[r][c] = 1;
	    findAllComb(mat, n, m , r + 1, c , u, d - 1, v, visited);
	    findAllComb(mat, n, m , r - 1, c , u - 1, d, v, visited);
	    findAllComb(mat, n, m , r , c + 1, u, d , v, visited);
	    findAllComb(mat, n, m , r , c - 1, u, d, v, visited);
	}
 

//Bfs based solution for efficient implementation

int numberOfCells(int n, int m, int r, int c, int u, int d, vector<vector<char>> &mat)
{
 vector<vector<bool>> visited;
 for(int i = 0; i < n; i++){
     vector<bool> vec (m , false);
     visited.push_back(vec);
 }
 queue<pair<pair<int, int>, pair<int, int>>> q;
 if(mat[r][c] ==  '#'){
     return 0;
 }
 q.push({{r,c}, {0, 0}});
 visited[r][c] = true;
 int cnt = 1;
 while(!q.empty()){
     int x = q.front().first.first;
     int y = q.front().first.second;
     int up = q.front().second.first;
     int down = q.front().second.second;
     q.pop();
     if(y - 1 >= 0 && mat[x][y - 1] == '.' && visited[x][y - 1] == false){
         q.push({{x, y - 1}, {up, down}});
         visited[x][y - 1] = true;
         cnt++;
     }
     if(y + 1 < m && mat[x][y + 1] == '.' && visited[x][y + 1] == false){
         q.push({{x, y + 1}, {up, down}});
         visited[x][y + 1] = true;
         cnt++;
     }
     if(x - 1 >= 0 && mat[x - 1][y] == '.' && visited[x - 1][y] == false && up != u){
         q.push({{x - 1, y}, {up + 1, down}});
         visited[x - 1][y] = true;
         cnt++;
     }
     if(x + 1 < n && mat[x  + 1][y] == '.' && visited[x + 1][y] == false && down != d){
         q.push({{x + 1, y}, {up, down + 1}});
         visited[x + 1][y] = true;
         cnt++;
     }
 }
 return cnt;
}

};

// { Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;

    while (t--)
    {
    	int n, m, r, c, u, d;
        cin >> n >> m >> r >> c >> u >> d;
        
        vector<vector<char>> mat(n, vector<char>(m, '.'));

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < m; j++)
        	{
        		cin >> mat[i][j];
        	}
        }

      

        Solution obj;
        cout << obj.numberOfCells(n, m, r, c, u, d, mat) << "\n";
    
    }

    return 0;
}


  // } Driver Code Ends