class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int sum = 0, n = nums.size();
        int target = 0;
        for(int i = 0; i < n; i++)
        {
            target += nums[i];
        }
        target -= x;
        if(target == 0) return n;
        unordered_map<int, int> mp;
        mp[0] = -1;
        int maxLength = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            if(mp.find(sum - target) != mp.end())
            {
                maxLength = max(maxLength, i - mp[sum - target]);
            }
            mp[sum] = i;
        }
        if(maxLength == INT_MIN) return -1;
        return n - maxLength;
    }
};