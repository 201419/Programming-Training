// https://leetcode-cn.com/problems/palindrome-partitioning/
// 131. 分割回文串

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/palindrome-partitioning-ii/
// 132. 分割回文串 II

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/clone-graph/
// 133. 克隆图

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/gas-station/
// 134. 加油站

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/candy/
// 135. 分发糖果

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/single-number/
// 136. 只出现一次的数字

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int i = 0; i < n; i++){
            result ^= nums[i];
        }
        return result;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/single-number-ii/
// 137. 只出现一次的数字 II

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/copy-list-with-random-pointer/
// 138. 复制带随机指针的链表

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/word-break/
// 139. 单词拆分

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/word-break-ii/
// 140. 单词拆分 II
