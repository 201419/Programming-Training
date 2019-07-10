// https://leetcode-cn.com/problems/employees-earning-more-than-their-managers/
// 181. 超过经理收入的员工

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/duplicate-emails/
// 182. 查找重复的电子邮箱

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/customers-who-never-order/
// 183. 从不订购的客户

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/department-highest-salary/
// 184. 部门工资最高的员工

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/department-top-three-salaries/
// 185. 部门工资前三高的员工

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/reverse-words-in-a-string-ii/
// 186. 翻转字符串里的单词 II

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/repeated-dna-sequences/
// 187. 重复的DNA序列

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/
// 188. 买卖股票的最佳时机 IV

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/rotate-array/
// 189. 旋转数组

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if (k != 0) {
            reverse(nums, 0, nums.size() - 1);
            reverse(nums, 0, k - 1);
            reverse(nums, k, nums.size() - 1);
        }
    }
    
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            int temp = nums[start];
            nums[start++] = nums[end];
            nums[end--] = temp;
        }
    }
};

// other method

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if (k <= 0) return;

        int target = 1;
        if (nums.size() % k == 0) {
            target = k;
        } else {
            for (int i = 2; i <= k / 2; i++) {
                if ((nums.size() % i == 0) && (k %  i) == 0) {
                    target = i;
                }
            }
        }

        for (int i = 0; i < target; i++) {
            int curr = (i + k) % nums.size();
            int pre = nums[i];
            while (curr != i) {
                int temp = nums[curr];
                nums[curr] = pre;
                pre = temp;
                curr = (curr + k) % nums.size();
            }
            nums[i] = pre;
        }
    }
};

// 空间换时间

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> tmp=nums;
        for(int i=0;i<nums.size();++i) {
            nums[(i+k)%nums.size()]=tmp[i];
        }
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/reverse-bits/
// 190. 颠倒二进制位
