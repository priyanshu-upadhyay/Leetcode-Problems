#User function Template for python3

class Solution:
    def maxBinTreeGCD(self, arr, N):
        # Contributed By: Mridul Bhaskar
        dict_ = {}
        res = 0
        if(N<=2):
            return res
        else:
            for i in range(0,len(arr),1):
                if(arr[i][0] not in dict_):
                    dict_[arr[i][0]] = arr[i][1]
                else:
                    temp = gcd(arr[i][1],dict_[arr[i][0]])
                    res = max(temp,res)
        return res

#{ 
#  Driver Code Starts
#Initial Template for Python 3

from math import gcd
if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        N=int(input())
        arr=[]
        
        for i in range(N-1):
            u,v=map(int,input().split())
            arr.append([u,v])
        
        ob = Solution()
        print(ob.maxBinTreeGCD(arr,N))
# } Driver Code Ends