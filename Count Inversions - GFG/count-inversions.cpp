// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long mergeSortedCountInversions(long long *arr, long long start, long long end)
    {
        long long mid = (start + end) >> 1;
        vector<long long> v1 (mid - start + 1);
        vector<long long> v2 (end - mid);
        for(long long i = 0; i < v1.size(); i++)
        {
            v1[i] = arr[i + start];
        }
        for(long long i = 0; i < v2.size(); i++)
        {
            v2[i] = arr[mid + 1 + i];
        }
        long long i = 0, j = 0, k = start;
        long long count = 0;
        while(i < v1.size() && j < v2.size())
        {
            if(v1[i] <= v2[j])
            {
                arr[k++] = v1[i];
                i++;
            }
            else
            {
                count += v1.size() - i;
                arr[k++] = v2[j];
                j++;
            }
        }
        
        while(i < v1.size())
        {
            arr[k++] = v1[i];
            i++;
        }
        
        while(j < v2.size())
        {
            arr[k++] = v2[j];
            j++;
        }
        return count;
        
    }
    long long mergeSort(long long *arr, int start, int end)
    {
        if(start < end)
        {
            long long mid = (start + end) >> 1;
            long long a = mergeSort(arr, start, mid);
            long long b = mergeSort(arr, mid + 1, end);
            long long c = mergeSortedCountInversions(arr, start, end);
            return a + b + c;
        }
        return 0;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        long long start = 0, end = N-1;
        long long count = mergeSort(arr, start, end);
        return count;
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends