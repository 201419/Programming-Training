// https://leetcode-cn.com/problems/n-queens/
// 51. N皇后

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/n-queens-ii/
// 52. N皇后 II

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/maximum-subarray/
// 53. 最大子序和

class Solution {
public:
    int findMaxCrossSubArray(vector<int>& nums, int low, int mid, int high) {
        int left = INT_MIN, right = INT_MIN;
        int sum = 0;
        for (int i = mid; i >= low; i--) {
            sum += nums[i];
            if (sum > left)  left = sum;
        }
        sum = 0;
        for (int j = mid + 1; j <= high; j++) {
            sum += nums[j];
            if (sum > right)  right = sum;
        }
        return (left + right);
    }
    
    int findMaxSubArray(vector<int>& nums, int low, int high) {
        if (low == high)  return nums[low];
        else {
            int mid = (low + high) / 2;
            int leftSum = findMaxSubArray(nums, low, mid);
            int rightSum = findMaxSubArray(nums, mid+1, high);
            int crossSum = findMaxCrossSubArray(nums, low, mid, high);
            if (leftSum >= rightSum && leftSum >= crossSum)  return leftSum;
            else if (rightSum >= leftSum && rightSum >= crossSum)  return rightSum;
            else  return crossSum;
        }
    }
    
    int maxSubArray(vector<int>& nums) {
        /*
        int sum = 0, maxSubSum = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            sum = ((sum + nums[i]) > nums[i] ? (sum + nums[i]) : nums[i]);
            if (maxSubSum < sum)  maxSubSum = sum;
        }
        return maxSubSum;*/        
        return findMaxSubArray(nums, 0, nums.size()-1);
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/spiral-matrix/
// 54. 螺旋矩阵

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> result;
        if (matrix.empty()) return result;
        
        int i1 = 0, j1 = 0, i2 = matrix.size() - 1, j2 = matrix[0].size() - 1;
        while (i1 <= i2 && j1 <= j2) {
            
            for (int col = j1; col <= j2; col++) result.push_back(matrix[i1][col]);
            for (int row = i1 + 1; row <= i2; row++) result.push_back(matrix[row][j2]);
            
            if (i1 < i2 && j1 < j2) {
                for (int col = j2 - 1; col >= j1 + 1; --col) result.push_back(matrix[i2][col]);
                for (int row = i2; row >= i1 + 1; --row) result.push_back(matrix[row][j1]);
            }
            
            ++i1; ++j1;
            --i2; --j2;
        }
        return result;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/jump-game/
// 55. 跳跃游戏

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/merge-intervals/
// 56. 合并区间

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/insert-interval/
// 57. 插入区间

// ---------------------------------------------------------------------------

https://leetcode-cn.com/problems/length-of-last-word/
// 58. 最后一个单词的长度

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/spiral-matrix-ii/submissions/
// 59. 螺旋矩阵 II

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int index = 1, row = 0;
        while (index <= n * n) {
            for (int i = row; i < n - row; ++i) matrix[row][i] = index++;
            for (int i = row + 1; i < n - row; ++i) matrix[i][n-row-1] = index++;
            for (int i = n - row - 2; i > row; --i) matrix[n-row-1][i] = index++;
            for (int i = n - row - 1; i > row; --i) matrix[i][row] = index++;
            ++row;
        }
        return matrix;
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/permutation-sequence/
// 60. 第k个排列
