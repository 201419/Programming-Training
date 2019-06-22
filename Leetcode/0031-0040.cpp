


// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/search-in-rotated-sorted-array/
// 33. 搜索旋转排序数组

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return search(nums, 0, nums.size()-1, target);
    }
private:
    int search(vector<int>& nums, int low, int high, int target) {
        if (low > high) return -1;
        int mid = (low + high) / 2;
        if (nums[mid] == target) return mid;   
        if (nums[mid] < nums[high]) {
            if (nums[mid] < target && target <= nums[high]) return search(nums, mid + 1, high, target);
            else return search(nums, low, mid - 1, target);
        } else {
            if (nums[low] <= target && target < nums[mid]) return search(nums, low, mid - 1, target);
            else return search(nums, mid + 1, high, target);
        }
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, mid = 0;
        while (low <= high) {
            mid = (low + high) / 2;
            if (nums[mid] == target) return mid;       
            if (nums[mid] < nums[high]) {
                if (nums[mid] < target && target <= nums[high]) low = mid + 1;
                else high = mid - 1;
            } else {
                if (nums[low] <= target && target < nums[mid]) high = mid - 1;
                else low = mid + 1;
            }
        }
        return -1;
    }
};

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/search-insert-position/
// 35. 搜索插入位置

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] < target) { low = mid + 1; }
            else if (nums[mid] > target) { high = mid - 1; }
            else { return mid; }
        }
        return low;
    }
};

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

