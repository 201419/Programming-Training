// https://leetcode-cn.com/problems/flatten-nested-list-iterator/
// 341. 扁平化嵌套列表迭代器

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/power-of-four/
// 342. 4的幂

class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num < 0 || num & (num-1)) return false;
        return num & 0x55555555;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/integer-break/
// 343. 整数拆分

class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        
        int a = 1;
        while (n > 4) {
            n = n - 3;
            a = a * 3;
        }
        return a * n;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/reverse-string/
// 344. 反转字符串

class Solution {
public:
    void reverseString(vector<char>& s) {
        int head = -1, tail = s.size();
        if (tail <= 1) return;
        
        while(++head < --tail){
            char temp = s[head];
            s[head] = s[tail];
            s[tail] = temp;
        }
    }
};

// ---------------------------------------------------------------------------



// ---------------------------------------------------------------------------



// ---------------------------------------------------------------------------



// ---------------------------------------------------------------------------



// ---------------------------------------------------------------------------



// ---------------------------------------------------------------------------


