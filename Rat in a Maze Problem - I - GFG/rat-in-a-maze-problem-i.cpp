// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    private:
    void genrate_possible_paths(int i, int j, string curr, int n, vector<string>& result, vector<vector<int>> &arr)
    {
        if(i < 0 || j < 0 || i >= n || j >= n || arr[i][j] == 0) return;
        if(i == n-1 && j == n-1) 
        {
            result.push_back(curr);
            return;
        }
        arr[i][j] = 0;
        genrate_possible_paths(i + 1, j, curr + "D", n, result, arr);
        genrate_possible_paths(i, j + 1, curr + "R", n, result, arr);
        genrate_possible_paths(i, j - 1, curr + "L", n, result, arr);
        genrate_possible_paths(i - 1, j, curr + "U", n, result, arr);
        arr[i][j] = 1;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> result;
        genrate_possible_paths(0, 0, "", n, result, m);
        return result;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends