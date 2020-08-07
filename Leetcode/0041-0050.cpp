// https://leetcode-cn.com/problems/first-missing-positive/
// 41. 缺失的第一个正数

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[nums[i] - 1], nums[i]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) return i + 1;
        }
        return n + 1;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/trapping-rain-water/
// 42. 接雨水

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3) return 0;
        vector<int> leftmax(height.size()), rightmax(height.size());
        leftmax[0] = height[0];
        for (int i = 1; i < height.size() - 1; i++) {
            leftmax[i] = max(leftmax[i-1], height[i]);
        }
        rightmax[height.size()-1] = height[height.size()-1];
        for (int i = height.size() - 2; i > 0; i--) {
            rightmax[i] = max(rightmax[i+1], height[i]);
        }
        int ans = 0;
        for (int i = 1; i < height.size() - 1; i++) {
            ans += min(leftmax[i], rightmax[i]) - height[i];
        }
        return ans;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/multiply-strings/
// 43. 字符串相乘

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.empty() || num2.empty()) return num1.empty()?num2:num1;
        if (num1 == "0" || num2 == "0") return "0";
        int size1 = num1.size(), size2 = num2.size();
        string str(size1 + size2, '0');
        
        for (int i = size1 - 1; i >= 0; i--) {
            int mulflag = 0, addflag = 0;
            for (int j = size2 - 1; j >= 0; j--) {
                int tmp = (num1[i] - '0') * (num2[j] - '0') + mulflag;
                mulflag = tmp / 10;
                tmp  = tmp % 10;
                int tmp2 = str[i + j + 1] - '0' + tmp + addflag;
                str[i + j + 1] = tmp2 % 10 + '0';
                addflag = tmp2 / 10;
            }
            str[i] += mulflag + addflag;
        }
        
        if (str[0] == '0') str = str.substr(1, str.size());
        return str;
    }
};

// 下边这个运行的慢

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.empty() || num2.empty()) return num1.empty()?num2:num1;
        if (num1 == "0" || num2 == "0") return "0";
        string res = "";
        int len1 = num1.size(), len2 = num2.size();
        
        for (int i = len1 - 1; i >= 0; i--) {
            if (i == len1-1) {
                res = mulstr(num2, num1[i]-'0');
            } else {
                string b = mulstr(num2, num1[i]-'0');
                string zeros(len1 - i - 1,'0');
                b += zeros;
                res = addstr(res, b);
            }
        }
        return res;
    }
    
    string addstr(string &a, string &b) {
        int i = a.size() - 1, j = b.size() - 1;
        int cnt = 0;
        string res = "";
        while (i >= 0 || j >= 0) {
            if (i < 0) {
                int t = cnt + b[j] - '0';
                cnt = t / 10;
                t %= 10;
                res  = to_string(t) + res;
                j--;
                continue;
            }
            if (j < 0) {
                int t = cnt + a[i] - '0';
                cnt = t / 10;
                t %= 10;
                res = to_string(t) + res;
                i--;
                continue;
            }
            int t = cnt + a[i] - '0' + b[j] - '0';
            cnt = t / 10;
            t %= 10;
            res = to_string(t) + res;
            i--;
            j--;
        }
        if (cnt > 0) res = to_string(cnt) + res;
        return res;
    }
    string mulstr(string &str, int c) {
        string res = "";
        int cnt = 0;
        for (int i = str.size()-1; i >= 0; --i) {
            int t = (str[i] - '0') * c + cnt;
            cnt = t / 10;
            t = t % 10;
            res = to_string(t) + res;
        }
        if (cnt > 0) res = to_string(cnt) + res;
        return res;
    }
};

// ---------------------------------------------------------------------------

// 44.

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/jump-game-ii/
// 45. 跳跃游戏 II

class Solution {
public:
    int jump(vector<int>& nums) {
        int step = 0;
        for (int end = 0, maxPos = 0, i = 0; i < nums.size() - 1; ++i) {
            if (maxPos >= i) {
                maxPos = max(maxPos, i + nums[i]);
                if (i == end) {
                    end = maxPos;
                    ++step;
                }
            }
        }
        return step;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/permutations/
// 46. 全排列

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        permutationrecusive(nums, 0, result);
        return result;
    }
    
    void permutationrecusive(vector<int>& nums, int k, vector<vector<int>>& result) {
        if (k == nums.size() - 1) {
            result.push_back(nums);
            return ;
        }
        for (int i = k; i < nums.size(); i++) {
            for (int j = i; j > k; j--) {
                swap(nums[j], nums[j-1]);
            }
            // swap(nums[k], nums[i]);
            permutationrecusive(nums, k+1, result);
            for (int j = k; j < i; j++) {
                swap(nums[j], nums[j+1]);
            }
            // swap(nums[k], nums[i]);
        }
    }  
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/permutations-ii/
// 47. 全排列 II

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/rotate-image/
// 48. 旋转图像

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (int begin = 0, end = matrix.size() - 1; begin < end; begin++, end--) {
            for (int i = 0; i < end - begin; i++) {
                int tmp = matrix[begin][begin+i];
                matrix[begin][begin+i] = matrix[end-i][begin];
                matrix[end-i][begin] = matrix[end][end-i];
                matrix[end][end-i] = matrix[begin+i][end];
                matrix[begin+i][end] = tmp;
            }
        }
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/group-anagrams/
// 49. 字母异位词分组

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;  
        int sub = 0;
        string tmp;
        unordered_map<string, int> work;
        for (auto str:strs) {
            tmp = str;
            sort(tmp.begin(), tmp.end());
            if (work.count(tmp)) {
               res[work[tmp]].push_back(str);
            } else {
                vector<string> vec(1, str);
                res.push_back(vec);
                work[tmp] = sub++;
            }
        }
        return res;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/powx-n/
// 50. Pow(x, n)

class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }

    double quickMul(double x, long long N) {
        double ans = 1.0;
        double x_contribute = x;
        while (N > 0) {
            if (N & 1 == 1)  ans *= x_contribute;
            x_contribute *= x_contribute;
            N = N >> 1;
        }
        return ans;
    }
};

// ------------------

class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }
    double quickMul(double x, long long N) {
        if (N == 0)  return 1.0;
        double y = quickMul(x, N>>1);
        return (N&1) == 0 ? y*y : y*y*x;
    }
};
