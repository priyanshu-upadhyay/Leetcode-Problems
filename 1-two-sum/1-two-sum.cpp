class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++)
        {
            int toFind = target - nums[i];
            if(mp.find(toFind) != mp.end())
            {
                return {i, mp[toFind]};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};