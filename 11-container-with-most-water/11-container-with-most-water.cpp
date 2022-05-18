class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0, j = n - 1;
        int ans = 0;
        while(i < j)
        {
            ans = max( ans, (j - i) * min(height[i], height[j]) );
            if(height[i] > height[j]) j--;
            else i++;
        }
        return ans;
    }
};