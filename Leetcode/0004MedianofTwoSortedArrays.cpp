class Solution {
private:
    int findKth(vector<int>& nums1, int ii, int m, vector<int>& nums2, int jj, int n, int k) {
        if (m == 0) return nums2[jj+k-1];
        if (n == 0) return nums1[ii+k-1];
        if (k == 1) return min(nums1[ii], nums2[jj]);
        
        int i = min(k/2, m), j = min(k/2, n);
        if (nums1[ii+i-1] < nums2[jj+j-1]) {
            return findKth(nums1, ii+i, m-i, nums2, jj, n, k-i);
        }
        return findKth(nums1, ii, m, nums2, jj+j, n-j, k-j);
    }
    
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        assert(m + n > 0);
        
        if ((m + n) % 2 == 1) {
            return findKth(nums1, 0, m, nums2, 0, n, (m+n+1)/2);
        }
        return ((double)findKth(nums1, 0, m, nums2, 0, n, (m+n)/2) + (double)findKth(nums1, 0, m, nums2, 0, n, 1+(m+n)/2)) / 2;
    }
};