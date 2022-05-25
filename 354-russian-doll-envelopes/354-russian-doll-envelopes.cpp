class Solution {
public:
    int find_bound(vector<int> &dp,int target){
       
       int pos = dp.size();
       
       int low = 0;
       int high = dp.size()-1;
       
       while(low<=high){
           
           int mid = low + (high-low)/2;
           
           if(dp[mid]>=target){
               pos = mid;
               high = mid-1;
           }
           else{
               low = mid+1;
           }
           
       }
       
       return pos;
       
   } 
    
    
   int maxEnvelopes(vector<vector<int>>& envelopes) {
       
        sort(envelopes.begin(),envelopes.end());
        
        for(int i=0;i<envelopes.size();){
            int start = i;
            int num = envelopes[i][0];
           
            
            while(i<envelopes.size() && envelopes[i][0]==num){
                i++;
            }
            
            int end = i-1;
            
            reverse(envelopes.begin()+start,envelopes.begin()+end+1);
            
        }
       
        
        vector<int> height;
        
        for(int i=0;i<envelopes.size();i++){
            int h = envelopes[i][1];
            height.push_back(h);
           
        }
       
        vector<int> dp;
        
        for(int i=0;i<height.size();i++){
            int sz = dp.size();
            
            if(sz == 0){
                dp.push_back(height[i]);
            }
            else if(dp[sz-1]<height[i]){
                dp.push_back(height[i]);
            }
            else{                
                int pos = find_bound(dp,height[i]);
                if(pos >= dp.size()) continue;
                dp[pos] = height[i];
                
            }
        }
       
	    return dp.size();
    }
};