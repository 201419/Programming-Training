
// https://leetcode-cn.com/problems/arranging-coins/
// 441. 排列硬币


// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/find-all-duplicates-in-an-array/
// 442. 数组中重复的数据


// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/string-compression/
// 443. 压缩字符串


// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/sequence-reconstruction/
// 444. 序列重建


// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/add-two-numbers-ii/
// 445. 两数相加 II


// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/
// 446. 等差数列划分 II - 子序列


// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/number-of-boomerangs/
// 447. 回旋镖的数量


// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/
// 448. 找到所有数组中消失的数字

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
        }
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) result.push_back(i + 1);
        }
        return result;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/serialize-and-deserialize-bst/
// 449. 序列化和反序列化二叉搜索树


// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/delete-node-in-a-bst/
// 450. 删除二叉搜索树中的节点


