// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    
private:
void recursive(vector<int>& nums, vector<int>& result, int i, int j)
{
    if(i <= j)
    {
        int mid = (i + j) >> 1;
        result.push_back(nums[mid]);
        recursive(nums, result, i, mid - 1);
        recursive(nums, result, mid + 1, j);
    }
}
public:
    vector<int> sortedArrayToBST(vector<int>& nums) {
       vector<int> result;
       int i = 0, j = nums.size() - 1;
       recursive(nums, result, i, j);
       return result;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends