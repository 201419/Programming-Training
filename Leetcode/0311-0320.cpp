
// https://leetcode-cn.com/problems/sparse-matrix-multiplication/
// 311. 稀疏矩阵的乘法


// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/burst-balloons/
// 312. 戳气球

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1); nums.push_back(1);
        
        vector<vector<int> > dp(nums.size(), vector<int>(nums.size() , 0));
        for (int len = 1; len <= n; ++len) {
            for (int left = 1; left <= n - len + 1; ++left) {
                int right = left + len - 1;
                for (int k = left; k <= right; ++k) {
                    dp[left][right] = max(dp[left][right], nums[left-1]*nums[k]*nums[right+1] + dp[left][k-1] + dp[k+1][right]);
                }
            }
        }
        return dp[1][n];
    }
    
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/super-ugly-number/
// 313. 超级丑数


// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/binary-tree-vertical-order-traversal/
// 314. 二叉树的垂直遍历


// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/
// 315. 计算右侧小于当前元素的个数


// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/remove-duplicate-letters/
// 316. 去除重复字母


// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/shortest-distance-from-all-buildings/
// 317. 离建筑物最近的距离


// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/maximum-product-of-word-lengths/
// 318. 最大单词长度乘积


// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/bulb-switcher/
// 319. 灯泡开关


// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/generalized-abbreviation/
// 320. 列举单词的全部缩写

