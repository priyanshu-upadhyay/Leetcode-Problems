// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> maximizeArray(int arr1[], int arr2[], int n) {
            // code here 
        vector<int> res;
        map<int,bool> seen;
        priority_queue<int, vector<int>> heap;
        for(int i=0;i<n;i++){
            heap.push(arr2[i]);
            heap.push(arr1[i]);
            seen[arr2[i]] = false;
            seen[arr1[i]] = false;
        }

        int l = 0;
        while(!heap.empty() and l < n){
            
            if(seen[heap.top()] == true){
                while(!heap.empty() and seen[heap.top()] == true)   heap.pop();
            }
            else    seen[heap.top()] = true, heap.pop(), l++;
        }
        for(int i=0;i<n;i++){
            if(seen[arr2[i]] == true)    res.push_back(arr2[i]), seen[arr2[i]] = false;
        }
        for(int i=0;i<n;i++){
            if(seen[arr1[i]] == true)    res.push_back(arr1[i]), seen[arr1[i]] = false;
        }
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr1[n], arr2[n];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        auto ans = ob.maximizeArray(arr1, arr2, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends