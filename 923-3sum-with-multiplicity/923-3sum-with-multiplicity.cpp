class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
    long long ans=0;
    for(int i=0;i<arr.size();i++){
        int l=i+1,r=arr.size()-1;
        while(l<r){
            if(arr[i]+arr[l]+arr[r]==target){
                int l_cnt=1,r_cnt=1;
                while(l<r && arr[l]==arr[l+1]){
                    l_cnt++;
                    l++;
                }
                 while(l<r && arr[r]==arr[r-1]){
                    r_cnt++;
                    r--;
                }
                if(r==l){
                    long long x=(l_cnt*(l_cnt-1))/2;
                    ans+=x;
                    ans%=1000000007;
                }else{
                    long long x=(l_cnt*r_cnt);
                    ans+=(x%1000000007);
                    ans%=1000000007;
                        
                }
                r--;l++;
                
            }
            else if(arr[i]+arr[l]+arr[r]>target){
                r--;
            }
            else if(arr[i]+arr[l]+arr[r]<target){
                l++;
            }
        }
    }
    return ans;
    }
};