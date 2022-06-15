class Solution {
public:
    bool isPredecessor(string &a, string &b){
        if(a.size()!=b.size()-1) return false;
		
        int i=0, j=0, ok=0;
        while(i<a.size() && j<b.size()){
            if(a[i]!=b[j]){
                if(ok) return false;
                ok=1;
                j++;
            }else
				i++, j++;
        }
        return true;
    }
    int longestStrChain(vector<string>& words) {
        int N = words.size();
        words.push_back("");
              
        sort(words.begin(), words.end(), [](string &a, string &b){
            return  a.size()<b.size();
        });
        
        vector<int> dp(N+1, 1);
        dp[0]=0;
        int preStart = 0, ans=0;
        
        for(int i=1; i<=N; i++){
            if(words[i].size()==words[i-1].size()+1){
                preStart = i-1;
            }
            for(int j=preStart; j>=0 && words[j].size()==words[preStart].size(); j--){
                if(isPredecessor(words[j], words[i])){
                    dp[i]= max(dp[i],dp[j]+1);
                }
                ans = max(ans, dp[i]);
            }
        }
       
        return ans;
    }
};