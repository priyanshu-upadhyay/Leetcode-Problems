class Solution {
private:
    void genrate(int left, int right, int n, string curr, vector<string>& result)
    {
        if(curr.length() == n*2)
        {
            result.push_back(curr);
            return;
        }
        if(left < n)
        {
            genrate(left + 1, right, n, curr + "(", result);
        }
        if(right < left)
        {
            genrate(left, right + 1, n, curr + ")", result);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        genrate(0, 0, n, "", result);
        return result;
    }
};