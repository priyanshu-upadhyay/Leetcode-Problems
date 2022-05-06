class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = n + m - 1;
        while(j >= 0 && i >= 0)
        {
            if(nums1[i] < nums2[j])
            {
                nums1[k] = nums2[j];
                k--;
                j--;
            }
            else
            {
                nums1[k] = nums1[i];
                k--;
                i--;
            }
        }
        while(j >= 0)
        {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};