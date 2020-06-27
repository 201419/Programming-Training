/* 题目描述

输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
例如，如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
*/


class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> vec;
        if(row==0) return vec;
        int i, left=0, right=col-1, top=0, bottom=row-1;
        while(left<=right&&top<=bottom) {
            for(i=left; i<=right; ++i) vec.push_back(matrix[top][i]);
            for(i=top+1; i<=bottom; ++i) vec.push_back(matrix[i][right]);
            if(top!=bottom) {
                for(i=right-1; i>=left; --i) vec.push_back(matrix[bottom][i]);
            }
            if(left!=right) {
                for(i=bottom-1; i>top; --i) vec.push_back(matrix[i][left]);
            }
            left++; right--; top++; bottom--;
        }
        return vec;
    }
};