class Solution {
private:
    
    void genratePermutations(int start, int n, vector<int>& nums, vector<vector<int>>& result)
    {
        if(start == n)
        {
            result.push_back(nums);
            return;
        }
        
        for(int i = start; i < n; i++)
        {
            swap(nums[i], nums[start]);
            genratePermutations(start + 1, n, nums, result);
            swap(nums[i], nums[start]);
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        genratePermutations(0, n, nums, result);
        return result;
    }
};