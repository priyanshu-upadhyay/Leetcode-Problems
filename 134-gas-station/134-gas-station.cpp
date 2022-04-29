class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> effectiveLeftFuel(n);
        for(int i = 0; i < n; i++)
        {
            effectiveLeftFuel[i] = gas[i] - cost[i];
        }
        
        int totalSum = accumulate(effectiveLeftFuel.begin(), effectiveLeftFuel.end(), 0);
        if(totalSum < 0)
        {
            return -1;
        }
        int start = 0, currSum = 0;
        for(int i = 0; i < n; i++)
        {
            if(currSum < 0)
            {
                start = i;
                currSum = 0;
            }
            currSum += effectiveLeftFuel[i];
        }
        return start;
    }
};