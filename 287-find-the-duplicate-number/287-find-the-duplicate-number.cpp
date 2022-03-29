class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        
        // Linked List Cycle 2 question ...... n+1 index hai isliye 0 index se start kiya
        int slow = nums[0];
        int fast = nums[0];
        
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            
        }while(slow != fast);
        
        int entry = nums[0];
        
        while(slow != entry)
        {
            slow = nums[slow];
            entry = nums[entry];
        }
            
        return slow;
            
    }
};