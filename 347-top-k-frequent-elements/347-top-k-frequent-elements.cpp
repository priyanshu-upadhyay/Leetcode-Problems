class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        vector<pair<int, int>> arr;
        
        for(auto pair : mp)
        {
            arr.push_back({pair.second, pair.first});
        }
        sort(arr.rbegin(), arr.rend());
        
        vector<int> result;
        
        for(int i = 0; i < k; i++)
        {
            result.push_back(arr[i].second);
        }
        return result;
    }
};