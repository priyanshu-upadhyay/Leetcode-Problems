class Solution {
private:
    void genrateCombinations(vector<int>& nums, int c, set<vector<int>>& result)
    {
        if(c == nums.size())
        {
            result.insert(nums);
            return;
        }
        int n = nums.size();
        for(int i = c; i < n; i++)
        {
            swap(nums[c], nums[i]);
            genrateCombinations(nums, c + 1, result);
            swap(nums[c], nums[i]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> setResult;
        genrateCombinations(nums, 0, setResult);
        vector<vector<int>> result (setResult.begin(), setResult.end());
        return result;
    }
};