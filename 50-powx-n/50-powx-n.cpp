class Solution {
public:
    double myPow(double x, int n) {
        
        long long power = n;
        if(n < 0) power = power * -1;
        double ans = 1.0;
        while(power > 0)
        {
            if(power%2)
            {
                ans = ans * x;
                power = power - 1;
            }
            else
            {
                x = x*x;
                power = power / 2;
            }
        }
        if(n < 0)
        {
            ans = 1.0 / ans;
        }
        return ans;
        
    }
};