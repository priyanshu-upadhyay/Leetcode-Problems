// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
private:
    bool isprime(long long sk){
      if(sk <= 1) return false;
      for(int i = 2; i <= sqrt(sk); i++){
         if(sk%i == 0) return 0;
      }
      return 1;
    }
public:
    long long primeProduct(long long L, long long R){
        // 1 ---> Prime
        // 0 ---> Not Prime
        // vector<int> sieve(R+1, 1);
        // sieve[0] = sieve[1] = 0;
        // for(int i = 2; i*i <= R; i++)
        // {
        //     for(int j = i*i; j <= R; j = j + i)
        //     {
        //         sieve[j] = 0;
        //     }
        // }
        // long long product = 1;
        // long long int mod = 1e9+7;
        // for(int i = L; i <= R; i++)
        // {
        //     if(sieve[i])
        //     {
        //         product = (product * i)%mod;
        //     }
        // }
        // return product;
        
        long long res = 1;
       long long int mod = 1e9+7;
       for(int i = L; i <= R; i++){
           if(isprime(i)){
            res = (res*i)%mod;
           }
       }
       return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long L, R;
        cin>>L>>R;
        
        Solution ob;
        cout<<ob.primeProduct(L, R)<<"\n";
    }
    return 0;
}  // } Driver Code Ends