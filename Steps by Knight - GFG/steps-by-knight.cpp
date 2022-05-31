// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    private:
        vector<vector<int>> dirs {{-2,-1}, {-2, 1}, {-1, 2}, {1, 2}, {2, -1}, {2, 1}, {-1, -2}, {1, -2}};
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
        vector<vector<int>> visited(N, vector<int> (N, 0));
        // 0 -> unvisited
        // 1 -> visited
        queue<pair<int, int>> q;
        q.push({KnightPos[0] - 1, KnightPos[1] - 1});
        visited[KnightPos[0] - 1][KnightPos[1] - 1] = 1;
        
        int curr = 0;
        while(!q.empty())
        {
            int size = q.size();
            for(int sz = 0; sz < size; sz++)
            {
                pair<int, int> coor = q.front();
                q.pop();
                int row = coor.first;
                int col = coor.second;
                if(row == TargetPos[0] - 1 && col == TargetPos[1] - 1)
                {
                    return curr;
                }
                for(vector<int> each : dirs)
                {
                    int i = row + each[0];
                    int j = col + each[1];
                    if(i >= 0 && i < N && j >= 0 && j < N && visited[i][j] == 0)
                    {
                        q.push({i, j});
                        visited[i][j] = 1;
                    }
                }
            }
            curr++;
        }
        return -1;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends