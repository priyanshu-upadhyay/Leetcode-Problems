class Solution {
private:
    void computingCombinations(int k, int n, vector<int> temp, vector<vector<int>>& result)
    {
        if(k == 0 && n == 0)
        {
            result.push_back(temp);
            return;
        }
        if(k == 0)
        {
            return;
        }
        if(n <= 0) return;
        
        int last = 0;
        if(temp.size() > 0)
        {
            last = temp.back();
        }
        for(int i = last + 1; i <= 9; i++)
        {
            temp.push_back(i);
            computingCombinations(k - 1, n - i, temp, result);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        computingCombinations(k, n, {}, result);
        return result;
    }
};