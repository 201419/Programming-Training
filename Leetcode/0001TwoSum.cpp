// https://leetcode-cn.com/problems/two-sum/
// 1. 两数之和

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            int numberToFind = target - nums[i];
            if (hash.find(numberToFind) != hash.end()) {
                result.push_back(hash[numberToFind]);
                result.push_back(i);
                return result;
            }
            hash[nums[i]] = i;
        }
        return result;
    }
};

// hash.find() takes constant time
// http://www.cplusplus.com/reference/unordered_map/unordered_map/find/

// 更简洁的版本
// 没有考虑无返回值的情况，但是submit solution是可以accepted的
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> imap;

        for (int i = 0;; ++i) {
            auto it = imap.find(target - nums[i]);
            if (it != imap.end()) 
                return vector<int> {it->second, i};
            imap[nums[i]] = i;
        }
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/add-two-numbers/
// 2. 两数相加

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode preHead(0), *p = &preHead;
        int extra = 0;
        while (l1 || l2 || extra) {
            if (l1) extra += l1->val, l1 = l1->next;
            if (l2) extra += l2->val, l2 = l2->next;
            p->next = new ListNode(extra % 10);
            extra /= 10;
            p = p->next;
        }
        return preHead.next;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
// 3. 无重复字符的最长子串

// 区区9行就实现了要求，而且时间复杂度为o(n)，简直是神来之笔
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
// 4. 寻找两个有序数组的中位数

class Solution {
private:
    int findKth(vector<int>& nums1, int ii, int m, vector<int>& nums2, int jj, int n, int k) {
        if (m == 0) return nums2[jj+k-1];
        if (n == 0) return nums1[ii+k-1];
        if (k == 1) return min(nums1[ii], nums2[jj]);
        int i = min(k/2, m), j = min(k/2, n);
        if (nums1[ii+i-1] < nums2[jj+j-1]) {
            return findKth(nums1, ii+i, m-i, nums2, jj, n, k-i);
        }
        return findKth(nums1, ii, m, nums2, jj+j, n-j, k-j);
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        assert(m + n > 0);
        if ((m + n) % 2 == 1) {
            return findKth(nums1, 0, m, nums2, 0, n, (m+n+1)/2);
        }
        return ((double)findKth(nums1, 0, m, nums2, 0, n, (m+n)/2) + (double)findKth(nums1, 0, m, nums2, 0, n, 1+(m+n)/2)) / 2;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/longest-palindromic-substring/
// 5. 最长回文子串

class Solution {
public:
    string longestPalindrome(string s) {
        const int n = s.size();
        
        if (n == 0) return "";
        if (n == 1) return s;
        
        int start = 0, maxlen = 1;
        for (int i = 0; i < n;) {
            if (n - i <= maxlen / 2) break;
            int j = i, k = i + 1;
            while (k < n && s[i] == s[k]) ++k; // Skip duplicate characters.
            i = k;
            while (k < n && j > 0 && s[k] == s[j - 1]) { ++k; --j; } // Expand.
            int newlen = k - j;
            if (newlen >= maxlen) { start = j; maxlen = newlen; }
        }
        return s.substr(start, maxlen);
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/zigzag-conversion/
// 6. Z 字形变换

class Solution {
public:
    string convert(string s, int numRows) {
        const int n = s.size();
        if (n <= numRows || numRows == 1) return s;
        
        string result;
        int gap = numRows + numRows - 2;

        for (int i = 0; i < numRows; i++) {
            int gapII = gap-i-i;
            for (int j = i; j < n; j += gap) {
                result.push_back(s[j]);
                if (i>0 && i<numRows-1 && j+gapII<n) result.push_back(s[j+gapII]);
            }
        }

        return result;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/reverse-integer/
// 7. 整数反转

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
            x /= 10;
        }
        return rev;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/string-to-integer-atoi/
// 8. 字符串转换整数 (atoi)

class Solution {
public:
    int myAtoi(string str) {
        const int n = str.size();
        if (n == 0) return 0;
        
        int i = 0, sign = 1;
        while (i + 1 < n && isspace(str[i])) ++i;
        if (i == n) return 0;
        
        long result = 0;
        if (str[i] == '-' || str[i] == '+') sign = 44 - str[i++];
        
        while (i < n) {
            if (isdigit(str[i])) result = 10 * result + str[i++] - '0';
            else return result * sign;
            if (result > INT_MAX) return sign == -1 ? INT_MIN : INT_MAX;
        }
        return result * sign;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/palindrome-number/
// 9. 回文数

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x!=0 && x%10==0)) return false;
        
        int j = 1000000000;
        while (!(x / j) && (j /= 10));
        
        for (int i = 1; i < j; i *= 10, j /= 10) {
            if ((x / i) % 10 != (x / j) % 10) return false;
        }
        return true;
    }
};

// ---------------------------------------------------------------------------
