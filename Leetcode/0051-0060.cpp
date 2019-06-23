

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/maximum-subarray/
// 53. 最大子序和

class Solution {
public:
    int findMaxCrossSubArray(vector<int>& nums, int low, int mid, int high) {
        int left = INT_MIN, right = INT_MIN;
        int sum = 0;
        for (int i = mid; i >= low; i--) {
            sum += nums[i];
            if (sum > left)  left = sum;
        }
        sum = 0;
        for (int j = mid + 1; j <= high; j++) {
            sum += nums[j];
            if (sum > right)  right = sum;
        }
        return (left + right);
    }
    
    int findMaxSubArray(vector<int>& nums, int low, int high) {
        if (low == high)  return nums[low];
        else {
            int mid = (low + high) / 2;
            int leftSum = findMaxSubArray(nums, low, mid);
            int rightSum = findMaxSubArray(nums, mid+1, high);
            int crossSum = findMaxCrossSubArray(nums, low, mid, high);
            if (leftSum >= rightSum && leftSum >= crossSum)  return leftSum;
            else if (rightSum >= leftSum && rightSum >= crossSum)  return rightSum;
            else  return crossSum;
        }
    }
    
    int maxSubArray(vector<int>& nums) {
        /*
        int sum = 0, maxSubSum = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            sum = ((sum + nums[i]) > nums[i] ? (sum + nums[i]) : nums[i]);
            if (maxSubSum < sum)  maxSubSum = sum;
        }
        return maxSubSum;*/        
        return findMaxSubArray(nums, 0, nums.size()-1);
    }
};

// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------
