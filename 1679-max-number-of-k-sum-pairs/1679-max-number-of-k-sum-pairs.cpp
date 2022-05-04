class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        int count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(mp[nums[i]] > 0)
            {
                mp[nums[i]]--;
                int toFind = k - nums[i];
                if(mp.find(toFind) != mp.end() && mp[toFind] > 0)
                {
                    mp[toFind]--;
                    count++;
                }
            }
        }
        return count;
    }
};