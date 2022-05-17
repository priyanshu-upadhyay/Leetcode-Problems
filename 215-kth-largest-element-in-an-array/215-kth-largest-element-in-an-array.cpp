class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int each : nums)
        {
            pq.push(each);
        }
        int largest;
        while(k > 0)
        {
            largest = pq.top();
            pq.pop();
            k--;
        }
        return largest;
    }
};