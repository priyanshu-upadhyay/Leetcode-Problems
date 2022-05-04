class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> check;
        unordered_map<int, queue<int>> mp;
        for(int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]].push(i);
        }
        int count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(check[i] == 0)
            {
                mp[nums[i]].pop();
                int toFind = k - nums[i];
                if(mp.find(toFind) != mp.end() && !mp[toFind].empty())
                {
                    check[mp[toFind].front()] = 1;
                    mp[toFind].pop();
                    count++;
                }
                check[i] == 1;
            }
            
        }
        return count;
    }
};