// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:
	long long int make_pal(long long int num){
       string s=to_string(num);
       int n=s.length();
       int i=0,j=n-1;
       while(i<j){
           s[j]=s[i];
           i++;
           j--;
       }
        return stoll(s);
   }


long long int closestPalindrome(long long int num){
    // Code here
    long long int ans=make_pal(num);         

    //most linkely this will be a ans 
    // if 10, 10000 and 197 ,17 like input is their so we have to upadte some thing       //in ans
    //the ans if most likely upper one becoz if fist half is same so on that way only       //we are going to found diff between ans and num is lesser
    // bet in the case of like 10000 their will be two ans 9999 and 10001 but 9999 is     //a ans and in 197 =>191 and 202 and 202 is and so for that sume times
    //we have to do sume plus minus of value 1 with only for one position else we      //found bigger abd diff
    int gap=abs(ans-num);     
    for(int i=0;i<15;i++){
        int z=pow(10,i);          

        //becoz only we have to change one number like in 23432 we have to                     //change 3rd no. 23432+100=13532 like something thwt

        if(num-z>0){                //check if z is bigger then our input

            long long int temp=make_pal(num-z);

            if(gap>=abs(temp-num)){

                if(gap==abs(temp-num)){

                    ans=min(temp,ans);            //if found same min diff two number then take min one

                }

                else{

                    ans=temp;

                }

            }

        }

        if(num+z<1e15){

           long long int temp=make_pal(num+z);

             if(gap>=abs(temp-num)){

                if(gap==abs(temp-num)){

                    ans=min(temp,ans);            //if found same min diff two number then take min one

                }

                else{

                    ans=temp;

                }

            }

        }

    }

    return ans;

    

}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int num;
		cin >> num;
		Solution obj;
		long long int ans = obj.closestPalindrome(num);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends