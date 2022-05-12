class Solution {
private:
    void genrateCombinations(vector<int>& nums, vector<int>& temp, set<vector<int>>& result)
    {
        if(nums.size() == 0)
        {
            result.insert(temp);
            return;
        }
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            temp.push_back(nums[i]);
            vector<int> new_nums;
            for(int j = 0; j < i; j++) new_nums.push_back(nums[j]);
            for(int j = i + 1; j < n; j++) new_nums.push_back(nums[j]);
            genrateCombinations(new_nums, temp, result);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> setResult;
        vector<int> temp;
        genrateCombinations(nums, temp, setResult);
        vector<vector<int>> result (setResult.begin(), setResult.end());
        return result;
    }
};