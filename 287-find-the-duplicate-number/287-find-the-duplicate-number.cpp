class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;
        while(low <= high)
        {
            int mid = (low + high) >> 1;
            int count = 0;
            for(int num : nums)
            {
                if(num <= mid) count++;
            }
            
            if(count <= mid)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }
};