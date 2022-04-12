class Solution {
public:
    vector<int> sortedSquares(vector<int>& arr) {
        
        int n = n = arr.size();
        int i = 0,  j = n - 1;
        vector<int> result(n);
        int k = n-1;
        while(i <= j)
        {
            if(abs(arr[i]) < abs(arr[j]))
            {
                result[k] = arr[j]*arr[j];
                j--;
            }
            else
            {
                result[k] = arr[i]*arr[i];
                i++;
            }
            k--;
        }
        return result;
    }
};