// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string stringPartition(string S, int a, int b){
        int n = S.length();
        int i = n - 1;
        int num = stoi(S);
        while(i>=1)
        {
            int divide = pow(10, i);
            int first_part = num / divide, second_part = num % divide;
            if(first_part%a == 0 && second_part%b == 0)
            {
                string str1 = S.substr(0, n - i);
                string str2 = S.substr(n - i);
                return str1 + " " + str2;
            }
            i--;
        }
        return "-1";
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {   
        int a,b;
        string S;
        cin >> S >> a >> b;
        Solution ob;
        cout << ob.stringPartition(S,a,b) << endl;
    }
    return 0; 
}   // } Driver Code Ends