class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, queue<int>> mp;
        for(int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]].push(i);
        }
        int count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(!mp[nums[i]].empty())
            {
                mp[nums[i]].pop();
                int toFind = k - nums[i];
                if(mp.find(toFind) != mp.end() && !mp[toFind].empty())
                {
                    mp[toFind].pop();
                    count++;
                }
            }
            
        }
        return count;
    }
};