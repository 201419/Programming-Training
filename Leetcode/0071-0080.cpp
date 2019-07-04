// https://leetcode-cn.com/problems/simplify-path/
// 71. 简化路径

class Solution {
public:
    string simplifyPath(string path) {
        deque<string> d;
        istringstream iss(path);
        
        for (string str; getline(iss, str, '/'); ) {
            if (!str.empty() && str != "." && str != "..") {
                d.push_back(str);
            } else if (!d.empty() && str == "..") {
                d.pop_back();
            }
        }
        
        if (d.empty()) return "/";
                
        string ans;
        while (!d.empty()) {
            ans += '/' + d.front();
            d.pop_front();
        }
        return ans;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/edit-distance/
// 72. 编辑距离

class Solution {
public:
    int minDistance(string word1, string word2) {
        // 将 word1 转换成 word2 所使用的最少操作数 
        
        int insertCost = 1;  // 插入的代价
	    int deleteCost = 1;  // 删除的代价
	    int replaceCost = 1;  // 替换的代价
        
        int m = word1.length();
        int n = word2.length();
        
        // 特殊情况的处理
	    if (m == 0) return n*insertCost;
	    if (n == 0) return m*deleteCost;
        
        // ----- 创建二维数组并初始化 -----
        vector<vector<int>> cost(m+1, vector<int>(n+1));
        for (int i = 0; i <= m; ++i) cost[i][0] = i*deleteCost;
        for (int j = 0; j <= n; ++j) cost[0][j] = j*insertCost;
        
        // ----- 填充二维数组 -----
        char firstChar;
        int costTmp;  // 相等则代价为0; 不相等代价为 replaceCost
        for (int i = 1; i <= m; ++i) {
            firstChar = word1[i - 1];
            for (int j = 1; j <= n; ++j) {
                costTmp = (firstChar == word2[j - 1]) ? 0 : replaceCost;
                cost[i][j] = min(min(cost[i - 1][j] + deleteCost, cost[i][j - 1] + insertCost), cost[i - 1][j - 1] + costTmp);            
            }
        }
        
        return cost[m][n];
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/set-matrix-zeroes/
// 73. 矩阵置零

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/search-a-2d-matrix/
// 74. 搜索二维矩阵

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/sort-colors/
// 75. 颜色分类

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/minimum-window-substring/
// 76. 最小覆盖子串

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/combinations/
// 77. 组合

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/subsets/
// 78. 子集

class Solution {
public:
    //回溯法
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> vec;
        backtrade(nums, vec, 0);
        return res;
    }
    
    void backtrade(vector<int>& nums, vector<int> vec, int pos) {
        res.push_back(vec);
        
        for(int i=pos; i<nums.size(); i++) {
            vec.push_back(nums[i]);
            backtrade(nums,vec,i+1);
            //回溯到上一个状态
            vec.pop_back();
        }
    }
};

// other method

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        result.push_back({});
        int size = nums.size();
        int subsize = pow(2, size);
        int hash = 1;
        while (hash < subsize) {
            vector<int> temp;
            for (int k = 0; k < size; k++) {
                int a = 1<<k;
                if (a & hash) temp.push_back(nums[k]);
            }
            result.push_back(temp);
            hash++;
        }
        return result;
    }
};

// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------
