class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int k, j, N = arr.size();
        for(k = N-2; k>=0; k--)
        {
            if(arr[k] < arr[k+1]) break;
        }
        if(k<0)
        {
            reverse(arr.begin(), arr.end()); 
        }
        else
        {
            for(j = N-1; j>=0; j--)
            {
                if(arr[j]>arr[k]) break;
            }
            swap(arr[k], arr[j]);
            reverse(arr.begin()+k+1, arr.end());
        }
    }
};