class Solution {
public:
    int nextGreaterElement(int n) {
        string num = to_string(n);
        int size = num.length();
        int ind1 = -1;
        for(int i = 0; i < size - 1; i++)
        {
            if(num[i] < num[i+1])
            {
                ind1 = i;
            }
        }
        
        if(ind1 == -1)
        {
            reverse(num.begin(), num.end());
        }
        else
        {
            int ind2 = 0;
            for(int i = size - 1; i >= 0; i--)
            {
                if(num[i] > num[ind1])
                {
                    ind2 = i;
                    break;
                }
            }
            swap(num[ind1], num[ind2]);
            reverse(num.begin() + ind1 + 1, num.end());
        }
        
        long long resultNum = stoll(num);
        if(resultNum > INT_MAX || resultNum <= n)
        {
            return -1;
        }
        return resultNum;
    }
};