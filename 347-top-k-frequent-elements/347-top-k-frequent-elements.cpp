class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        priority_queue<pair<int, int>> pq;
        vector<int> result;
        for(auto pair : mp)
        {
            pq.push({pair.second, pair.first});
            if(pq.size() > mp.size() - k) // usse jda hua to hum le skte h 
            {
                result.push_back(pq.top().second);
                pq.pop();
            }
        }
        
        return result;
    }
};