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

// https://leetcode-cn.com/problems/reverse-vowels-of-a-string/
// 345. 反转字符串中的元音字母

class Solution {
public:
    string reverseVowels(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (!isVowel(s[left])) { left ++; }
            else if (!isVowel(s[right])) { right --; }
            else {
                swap(s[left], s[right]);
                left ++;
                right --;
            }
        }
        return s;
    }
    
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' 
            || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/moving-average-from-data-stream/
// 346. 数据流中的移动平均值

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/top-k-frequent-elements/
// 347. 前K个高频元素

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/design-tic-tac-toe/
// 348. 判定井字棋胜负

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/intersection-of-two-arrays/
// 349. 两个数组的交集

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hashSet(nums1.begin(), nums1.end());
        unordered_set<int> hashSet2;
        for(const auto &num : nums2) {
            if(hashSet.count(num) > 0) hashSet2.insert(num);
        }
        return vector<int>(hashSet2.begin(), hashSet2.end());
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/
// 350. 两个数组的交集 II

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> record;
        vector<int> res;
        for (int i = 0; i < nums1.size(); i++) record[nums1[i]]++;
        for (int i = 0; i < nums2.size(); i++) {
            if (record[nums2[i]] > 0) {
                res.push_back(nums2[i]);
                record[nums2[i]]--;
            }
        }
        return res;
    }
};
