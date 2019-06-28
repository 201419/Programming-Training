// https://leetcode-cn.com/problems/rotate-list/
// 61. 旋转链表

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return NULL;
        
        ListNode *p1 = head;
        while (p1->next != NULL) {
            p1 = p1->next;
        }
        p1->next = head;
        
        p1 = head;
        while (k--) {
            p1 = p1->next;
        }
        
        ListNode *p2 = head;
        while (p1->next != head) {
            p1 = p1->next;
            p2 = p2->next;
        }
        ListNode *ret = p2->next;
        p2->next = NULL;
        return ret;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/unique-paths/
// 62. 不同路径

class Solution {
public:
    int uniquePaths(int m, int n) {
        int step = m + n - 2;
        int minMN = m < n ? m-1 : n-1;
        
        long result = 1;
        for (int i = 0; i < minMN; i++) {
            result = result * (step-i) / (i+1);
        }
        return result;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/unique-paths-ii/
// 63. 不同路径 II


// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/minimum-path-sum/
// 64. 最小路径和

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/valid-number/
// 65. 有效数字

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/plus-one/
// 66. 加一

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] != 9) {
                digits[i]++;
                break;
            } else {
                digits[i] = 0;
                if (i == 0) digits.insert(digits.begin(), 1);
            }
        }
        return digits;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/add-binary/
// 67. 二进制求和

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/text-justification/
// 68. 文本左右对齐

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/sqrtx/
// 69. x 的平方根

class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;
        // https://en.wikipedia.org/wiki/Integer_square_root#Using_only_integer_division
        long r = x;
        while (r > x / r) {
            r = (r + x / r) / 2;
        }
        return r;
    }
};

// 另一种解法

class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;
        // https://en.wikipedia.org/wiki/Integer_square_root#Using_only_integer_division
        
        int smallCandidate = mySqrt(x >> 2) << 1;
        int largeCandidate = smallCandidate + 1;
        if (largeCandidate > (x / largeCandidate)) return smallCandidate;
        else return largeCandidate;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/climbing-stairs/
// 70. 爬楼梯

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1)  return 1;
        else if (n == 2)  return 2;
        else {
            int result = 0;
            int i = 1, j = 2;
            while (n-- > 2) {
                result = i + j;
                i = j;
                j = result;
            }
            return result;
        }
    }
};
