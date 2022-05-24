class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<char,int>> stk;
        int arr[s.length()];
        int m = 0;
        vector<int> v;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
            {
                stk.push(make_pair(s[i],i));
            }
            else if(!stk.empty() && stk.top().first == '(')
            {
                arr[m] = stk.top().second;
                m++;
                arr[m] = i;
                m++;
                // v.push_back(stk.top().second);
                // v.push_back(i);
                stk.pop();
            }
        }
        // for(int i : v)
        // {
        //     cout<<i<<" ";
        // }
        // int n = v.size();
        int i = 1;
        int c = 0;
        sort(arr,arr+m);
        while(i<m)
        {
            int k = 0;
            while (  i<m && (arr[i] - arr[i-1] == 1))
            {
                k = k + 1;
                i++;
            }
            c = max(k+1,c);
            i++;
        }
        return c;
    }
};