
// https://leetcode-cn.com/problems/zigzag-iterator/
// 281. 锯齿迭代器

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/expression-add-operators/
// 282. 给表达式添加运算符

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/move-zeroes/
// 283. 移动零

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/peeking-iterator/
// 284. 顶端迭代器

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/inorder-successor-in-bst/
// 285. 二叉搜索树中的顺序后继

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/walls-and-gates/
// 286. 墙与门

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/find-the-duplicate-number/
// 287. 寻找重复数

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/unique-word-abbreviation/
// 288. 单词的唯一缩写

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i = 0, j = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                if (i != j) {
                    nums[j] = nums[i];
                    nums[i] = 0;
                }
                j++;
            }
        }
    }
};

// other method

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx = 0;
        for (int i = 0; i < nums.size(); ++i){
            if (nums[i] != 0) //move
                nums[idx++] = nums[i];
        }
        while (idx < nums.size()){
            nums[idx++] = 0;
        }
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/game-of-life/
// 289. 生命游戏

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/word-pattern/
// 290. 单词规律
