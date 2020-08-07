// https://leetcode-cn.com/problems/next-permutation/
// 31. 下一个排列

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() < 2) return;
        int i;
        for (i = nums.size() - 1; i > 0 && nums[i - 1] >= nums[i]; i--);

        reverse(nums.begin() + i, nums.end());
        if (i-- != 0) {
            auto it = upper_bound(nums.begin() + i + 1, nums.end(), nums[i]);
            swap(nums[i], *it);
        }
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/longest-valid-parentheses/
// 32. 最长有效括号

// https://leetcode-cn.com/problems/longest-valid-parentheses/solution/zui-chang-you-xiao-gua-hao-by-leetcode-solution/

class Solution {
public:
    int longestValidParentheses(string s) {
        
        int res = 0;
        stack<int> sta;
        
        sta.push(-1);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                sta.push(i);
            } else {
                sta.pop();
                if (sta.empty()) {
                    sta.push(i);
                } else {
                    res = max(res, i - sta.top());
                }
            }
        }
        return res;
    }
};

// ------------------

class Solution {
public:
    int longestValidParentheses(string s) {
        
        int res = 0;
        vector<int> dp(s.length());
        
        for (int i = 1; i < s.length(); i++) {  // 动态规划
            if (s[i] == ')') {
                if (s[i-1] == '(') {
                    dp[i] = (i >= 2 ? dp[i-2] : 0) + 2;
                } else if (i - dp[i-1] > 0 && s[i - dp[i-1] - 1] == '(') {
                    dp[i] = dp[i-1] + ((i - dp[i-1]) >= 2 ? dp[i - dp[i-1] - 2] : 0) + 2;
                }
                res = max(res, dp[i]);
            }
        }
        return res;
    }
};

// ---------------

class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        
        int left = 0;
        int mark = 0;
        for (int i = 0; i < s.size(); ++i) {  // 先从左往右遍历
            int prev_mark = mark;
            mark = max(0, mark + ((s[i] == '(') ? 1 : -1));
            if (mark == 0) {  // 左括号和右括号数量相等
                if (prev_mark > 0)  res = max(i - left + 1, res);  // 在此之前左括号多于右括号
                else  left = i + 1;
            }
        }
        mark = 0;
        int right = s.size() - 1;
        for (int i = s.size() - 1; i >= 0; --i) {  // 再从右往左遍历，防止漏掉左括号一直多于右括号的情况
            int prev_mark = mark;
            mark = max(0, mark + ((s[i] == ')') ? 1 : -1));
            if (mark == 0) {
                if (prev_mark > 0)  res = max(right - i + 1, res);
                else  right = i - 1;
            }
        }
        return res;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/search-in-rotated-sorted-array/
// 33. 搜索旋转排序数组

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return search(nums, 0, nums.size()-1, target);
    }
private:
    int search(vector<int>& nums, int low, int high, int target) {
        if (low > high) return -1;
        int mid = (low + high) / 2;
        if (nums[mid] == target) return mid;   
        if (nums[mid] < nums[high]) {
            if (nums[mid] < target && target <= nums[high]) return search(nums, mid + 1, high, target);
            else return search(nums, low, mid - 1, target);
        } else {
            if (nums[low] <= target && target < nums[mid]) return search(nums, low, mid - 1, target);
            else return search(nums, mid + 1, high, target);
        }
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, mid = 0;
        while (low <= high) {
            mid = (low + high) / 2;
            if (nums[mid] == target) return mid;       
            if (nums[mid] < nums[high]) {
                if (nums[mid] < target && target <= nums[high]) low = mid + 1;
                else high = mid - 1;
            } else {
                if (nums[low] <= target && target < nums[mid]) high = mid - 1;
                else low = mid + 1;
            }
        }
        return -1;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// 34. 在排序数组中查找元素的第一个和最后一个位置

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> targetRange(2, -1);

        auto it_begin = lower_bound(nums.begin(), nums.end(), target);
        if(it_begin != nums.end() && *it_begin == target)  targetRange[0] = it_begin - nums.begin();
        
        auto it_end = upper_bound(nums.begin(), nums.end(), target);
        if(it_end != nums.begin() && *(it_end - 1) == target)  targetRange[1] = it_end - nums.begin() - 1;

        return targetRange;
    }
};

// -----------------

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> targetRange(2, -1);

        int leftIdx = extremeInsertionIndex(nums, target, true);
        if (leftIdx == nums.size() || nums[leftIdx] != target) {
            return targetRange;
        }
        targetRange[0] = leftIdx;
        targetRange[1] = extremeInsertionIndex(nums, target, false) - 1;
        return targetRange;
    }
    
    int extremeInsertionIndex(vector<int> &nums, int target, bool isleft) {
        int lo = 0, hi = nums.size();
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] > target || (isleft && target == nums[mid])) {
                hi = mid;
            } else { lo = mid + 1; }
        }
        return lo;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/search-insert-position/
// 35. 搜索插入位置

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] < target) { low = mid + 1; }
            else if (nums[mid] > target) { high = mid - 1; }
            else { return mid; }
        }
        return low;
    }
};

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/sudoku-solver/
// 37. 解数独

class Solution {
public:
    bitset<9> getPossibleStatus(int x, int y) {
        return ~(rows[x] | cols[y] | cells[x/3][y/3]);
    }

    vector<int> getNext(vector<vector<char>>& board) {
        // 找可选数字数目最小的空格
        vector<int> ret;
        int minCnt = 10;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] != '.') continue;
                auto cur = getPossibleStatus(i, j);
                if (cur.count() >= minCnt) continue;
                ret = { i, j };
                minCnt = cur.count();
            }
        }
        return ret;
    }

    void fillNum(int x, int y, int n, bool fillFlag) {
        rows[x][n] = (fillFlag) ? 1 : 0;
        cols[y][n] = (fillFlag) ? 1 : 0;
        cells[x/3][y/3][n] = (fillFlag) ? 1: 0;
    }
    // void fillNum(int x, int y, int n, bool fillFlag) {
    //     bitset<9> pick(1 << n);
    //     rows[x] = (fillFlag) ? (rows[x] | pick) : (rows[x] ^ pick);
    //     cols[y] = (fillFlag) ? (cols[y] | pick) : (cols[y] ^ pick);
    //     cells[x/3][y/3] = (fillFlag) ? (cells[x/3][y/3] | pick) : (cells[x/3][y/3] ^ pick);
    // }
    
    bool dfs(vector<vector<char>>& board, int cnt) {
        if (cnt == 0) return true;

        auto next = getNext(board);
        auto bits = getPossibleStatus(next[0], next[1]);
        for (int n = 0; n < bits.size(); n++) {
            if (!bits.test(n)) continue;  // 返回第n个位,从右往左
            fillNum(next[0], next[1], n, true);
            board[next[0]][next[1]] = n + '1';
            if (dfs(board, cnt - 1)) return true;
            board[next[0]][next[1]] = '.';
            fillNum(next[0], next[1], n, false);
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        rows = vector<bitset<9>>(9, bitset<9>());
        cols = vector<bitset<9>>(9, bitset<9>());
        cells = vector<vector<bitset<9>>>(3, vector<bitset<9>>(3, bitset<9>()));

        int cnt = 0;  // 记录有多少空格需要填
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                cnt += (board[i][j] == '.');
                if (board[i][j] == '.') continue;
                int n = board[i][j] - '1';
                rows[i] |= (1 << n);
                cols[j] |= (1 << n);
                cells[i/3][j/3] |= (1 << n);
            }
        }
        dfs(board, cnt);
    }

private:
    vector<bitset<9>> rows;
    vector<bitset<9>> cols;
    vector<vector<bitset<9>>> cells;
};

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

