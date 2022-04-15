// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        int maxAnswer = INT_MIN;
        for(int i = 0; i < R; i++)
        {
            vector<int> arr(C);
            for(int r = i; r < R; r++)
            {
                for(int j = 0; j < C; j++)
                {
                    arr[j] += M[r][j];
                }
                
                int sum = arr[0];
                int maxOverall = arr[0];
                for(int k = 1; k < C; k++)
                {
                    if(sum > 0)
                    {
                        sum = sum + arr[k];
                    }
                    else
                    {
                        sum = arr[k];
                    }
                    maxOverall = max(maxOverall, sum);
                }
                maxAnswer = max(maxAnswer, maxOverall);
            }
            
        }
        return maxAnswer;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}  // } Driver Code Ends