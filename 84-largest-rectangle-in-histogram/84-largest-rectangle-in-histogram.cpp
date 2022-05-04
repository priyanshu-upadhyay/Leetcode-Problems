class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        vector<int> nextSmallestLeft(n);
	vector<int> nextSmallestRight(n);
	stack<int> st;
	// Next Smallest Left
	for(int i = 0; i < n; i++)
	{
		while(!st.empty() && arr[i] <= arr[st.top()])
		{
			st.pop();
		}
		if(st.empty()) nextSmallestLeft[i] = -1;
		else nextSmallestLeft[i] = st.top();
		st.push(i);
	}
	while(!st.empty()) { st.pop(); }

	// next smallest right
	for(int i = n - 1; i >= 0; i--)
	{
		while(!st.empty() && arr[i] <= arr[st.top()])
		{
			st.pop();
		}
		if(st.empty()) nextSmallestRight[i] = n;
		else nextSmallestRight[i] = st.top();
		st.push(i);
	}

	int area_max = -1;
	for(int i = 0; i < n; i++)
	{
		int len = nextSmallestRight[i] - nextSmallestLeft[i] - 1;
		area_max = max(area_max, len * arr[i]);
	}
	return area_max;
    }
};