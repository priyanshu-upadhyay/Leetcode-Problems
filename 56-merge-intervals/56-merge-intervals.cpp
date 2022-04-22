class Solution {
private:

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        
        result.push_back(intervals[0]);
        
        for(int i = 1; i < intervals.size(); i++)
        {
            if(result.back()[1] >= intervals[i][0])
            {
                result.back()[1] = max(intervals[i][1], result.back()[1]);
            }
            else
            {
                result.push_back(intervals[i]);
            }
        }
        
        return result;
    }
};