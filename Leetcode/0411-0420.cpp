
// https://leetcode-cn.com/problems/minimum-unique-word-abbreviation/
// 411. 最短特异单词缩写


// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/fizz-buzz/
// 412. Fizz Buzz


// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/arithmetic-slices/
// 413. 等差数列划分


// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/third-maximum-number/
// 414. 第三大的数

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        else if (nums.size() == 2) return (nums[0] > nums[1] ? nums[0] : nums[1]);
        else {
            vector<int> result(3, INT_MIN);
            result[0] = nums[0];
            bool flag = (result[0] == INT_MIN ? true : false);
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] == INT_MIN) flag = true;
                if (nums[i] > result[0]) {
                    result.insert(result.begin(), nums[i]);
                } else if (nums[i] > result[1] && nums[i] != result[0]) {
                    result.insert(1+result.begin(), nums[i]);
                } else if (nums[i] > result[2] && nums[i] != result[0] && nums[i] != result[1]) {
                    result.insert(2+result.begin(), nums[i]);
                }
                result.resize(3);
            }
            if ((flag && result[1] != INT_MIN) || result[2] != INT_MIN) return result[2];
            else return result[0];
        }
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/add-strings/
// 415. 字符串相加


// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/partition-equal-subset-sum/
// 416. 分割等和子集


// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/pacific-atlantic-water-flow/
// 417. 太平洋大西洋水流问题


// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/sentence-screen-fitting/
// 418. 屏幕可显示句子的数量


// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/battleships-in-a-board/
// 419. 甲板上的战舰


// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/strong-password-checker/
// 420. 强密码检验器


