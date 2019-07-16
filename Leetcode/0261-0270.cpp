// https://leetcode-cn.com/problems/graph-valid-tree/
// 261. 以图判树

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/trips-and-users/
// 262. 行程和用户

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/ugly-number/
// 263. 丑数


// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/ugly-number-ii/
// 264. 丑数 II

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/paint-house-ii/
// 265. 粉刷房子 II

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/palindrome-permutation/
// 266. 回文排列

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/palindrome-permutation-ii/
// 267. 回文排列 II

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/missing-number/
// 268. 缺失数字

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xOR = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            xOR ^= (nums[i] ^ i);
        }
        return xOR;
    }
};

// other method 

/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 缺失数字
 *
 * https://leetcode-cn.com/problems/missing-number/description/
 *
 * algorithms
 * Easy (50.85%)
 * Likes:    129
 * Dislikes: 0
 * Total Accepted:    22.2K
 * Total Submissions: 43.6K
 * Testcase Example:  '[3,0,1]'
 *
 * 给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。
 * 
 * 示例 1:
 * 
 * 输入: [3,0,1]
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: [9,6,4,2,3,5,7,0,1]
 * 输出: 8
 * 
 * 
 * 说明:
 * 你的算法应具有线性时间复杂度。你能否仅使用额外常数空间来实现?
 * 
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        int ans = nums.size() * (nums.size() + 1) / 2;
        for (auto p : nums) {
            ans -= p;
        }
        return (int)ans;
    }
};

static const auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return nullptr;
}();

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/alien-dictionary/
// 269. 火星词典

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/closest-binary-search-tree-value/
// 270. 最接近的二叉搜索树值
