class Solution {
public:
    int nextGreaterElement(int n) {
        string numStr = to_string(n);
        next_permutation(numStr.begin(), numStr.end());
        long long newInt = stoll(numStr);
        if(newInt > INT_MAX || n >= newInt) return -1;
        return newInt;
    }
};