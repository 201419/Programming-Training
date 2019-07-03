// https://leetcode-cn.com/problems/cherry-pickup/
// 741. 摘樱桃

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/closest-leaf-in-a-binary-tree/
// 742. 二叉树最近的叶节点

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/network-delay-time/
// 743. 网络延迟时间

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/find-smallest-letter-greater-than-target/
// 744. 寻找比目标字母大的最小字母

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/prefix-and-suffix-search/
// 745. 前缀和后缀搜索

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/min-cost-climbing-stairs/
// 746. 使用最小花费爬楼梯

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int *dp = new int[n + 1];
        dp[0] = 0;
        dp[1] = 0;
        for(int i = 2; i <= n; i++) {
            dp[i] = (dp[i-1] + cost[i-1]) < (dp[i-2] + cost[i-2]) ? (dp[i-1] + cost[i-1]) : (dp[i-2] + cost[i-2]);
        }
        return dp[n];
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/largest-number-at-least-twice-of-others/
// 747. 至少是其他数字两倍的最大数

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int index = -1, max = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (max < 2 * nums[i]) {
                if (nums[i] >= 2 * max) {
                    index = i;
                    max = nums[i];
                } else if (nums[i] >= max) {
                    index = -1;
                    max = nums[i];
                } else {
                    index = -1;
                }
            }
        }
        return index;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/shortest-completing-word/
// 748. 最短完整词

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/contain-virus/
// 749. 隔离病毒

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/number-of-corner-rectangles/
// 750. 角矩形的数量
