// https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/
// 111. 二叉树的最小深度

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/path-sum/
// 112. 路径总和

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/path-sum-ii/
// 113. 路径总和 II

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/
// 114. 二叉树展开为链表

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/distinct-subsequences/
// 115. 不同的子序列

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/
// 116. 填充每个节点的下一个右侧节点指针

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/
// 117. 填充每个节点的下一个右侧节点指针 II

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/pascals-triangle/
// 118. 杨辉三角

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows,vector<int>());
        for(int i=0; i<numRows; i++) {
            res[i].resize(i+1);
            res[i][0]=1;
            res[i][i]=1;
        }
        for(int i=1; i<numRows-1; i++) {
            for(int j=1; j<=i; j++) {
                res[i+1][j]=res[i][j-1]+res[i][j];
            }
        }
        return res;
    }
};

// other method

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        
        for (int i = 0; i < numRows; i++) {
            vector<int> tmp(i+1);
            for (int j = 0; j <= i; j++) {
                if (j == 0) tmp[j] = 1;
                else if (j == i) tmp[j] = 1;
                else tmp[j] = result[i-1][j-1] + result[i-1][j];
            }
            result.push_back(tmp);
        }
        return result;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/pascals-triangle-ii/
// 119. 杨辉三角 II

// 执行用时 : 0 ms , 在所有 C++ 提交中击败了 100.00% 的用户
// 内存消耗 : 8.4 MB , 在所有 C++ 提交中击败了 63.08% 的用户

//第 n 行的第 k 个数字为组合数 C_{n-1}^{k-1}}
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1);
        long int cur = 1;
        for(int i=0; i<=rowIndex; i++){
            res[i] = ((int)cur);
            cur = cur * (rowIndex-i) / (i+1);  
        }
        return res;
    }
};

// other method 

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex+1);
        for (int i = 0; i <= rowIndex; i++) {
            for (int j = i; j >= 0; j--) {
                if (j == 0) result[j] = 1;
                else if (j == i) result[j] = 1;
                else result[j] = result[j-1] + result[j];
            }
        }
        return result;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/triangle/
// 120. 三角形最小路径和
