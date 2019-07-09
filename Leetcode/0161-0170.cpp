// https://leetcode-cn.com/problems/one-edit-distance/
// 161. 相隔为 1 的编辑距离

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/find-peak-element/
// 162. 寻找峰值

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/missing-ranges/
// 163. 缺失的区间

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/maximum-gap/
// 164. 最大间距

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/compare-version-numbers/
// 165. 比较版本号

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/fraction-to-recurring-decimal/
// 166. 分数到小数

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/
// 167. 两数之和 II - 输入有序数组

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result(2);
        int low = 0, high = numbers.size() - 1;
        while (low < high) {
            if (numbers[low] + numbers[high] < target) { low++; }
            else if (numbers[low] + numbers[high] > target) { high--; }
            else {
                result[0] = low + 1;
                result[1] = high + 1;
                return result;
            }
        }
        return result;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/excel-sheet-column-title/
// 168. Excel表列名称

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/majority-element/
// 169. 求众数

// 40 ms

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
		int majority = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			if (majority == nums[i]) count++;
			else {
				count--;
				if (count == 0) majority = nums[i + 1];
			}
		}
		return majority;
    }
};

// 24 ms

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int result = nums[0], cnt = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == result) { cnt++; }
            else if (cnt == 0) {
                result = nums[i];
                cnt++;
            }
            else { cnt--; }
        }
        return result;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/two-sum-iii-data-structure-design/
// 170. 两数之和 III - 数据结构设计
