#User function Template for python3

import heapq

class Solution:
    def minOperations(self,a,n):
        data = []
        res = 0
        for i in range(n):
            if data and data[0] < a[i]:
                res += a[i] - data[0]
                heapq.heappush(data,a[i])
                heapq.heappop(data)
            heapq.heappush(data,a[i])
        return res


#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t=int(input())
    for _ in range(t):
        n=int(input())
        a=[int(x) for x in input().strip().split()]
        obj=Solution()
        print(obj.minOperations(a,n))


# } Driver Code Ends