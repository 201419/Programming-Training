
// 41.

// ---------------------------------------------------------------------------


// 42.

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

// 45.

// ---------------------------------------------------------------------------

// 46.


// ---------------------------------------------------------------------------

// 47.

// ---------------------------------------------------------------------------

// 48.


// ---------------------------------------------------------------------------

// 49.


// ---------------------------------------------------------------------------

// 50.

