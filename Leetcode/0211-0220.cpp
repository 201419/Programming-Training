

// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
// 215. 数组中的第K个最大元素

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(NULL));
        return kthLargest(nums, 0, nums.size()-1, k);
    }
    
private:
    int kthLargest(vector<int>& nums, int left, int right, int k) {
        
        int index = _partition(nums, left, right);

        if (index + 1 < k) return kthLargest(nums, index+1, right, k);
        else if (index + 1 > k) return kthLargest(nums, left, index-1, k);
        else return nums[index];
    }

    int _partition(vector<int>& nums, int left, int right) {
        
        int randIndex = rand() % (right-left+1) + left;
        swap(nums[left], nums[randIndex]);

        int j = left, i = left+1;
        while (i <= right) {
            if (nums[i] >= nums[left]) swap(nums[i], nums[++j]);
            i++;
        }
        swap(nums[left], nums[j]);
        return j;
    }
};

// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/contains-duplicate/
// 217. 存在重复元素

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (auto num : nums) {
            if (s.find(num) != s.end())  return true;
            s.insert(num);
        }
        return false;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/contains-duplicate-ii/
// 219. 存在重复元素 II

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); map[nums[i]] = i, i++) {
            if (map.find(nums[i]) != map.end() && i - map[nums[i]] <= k) return true;
        }
        return false;
    }
};

// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------
