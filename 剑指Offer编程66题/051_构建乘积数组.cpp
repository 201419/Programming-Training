// 给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
// 其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。
// 不能使用除法。
// （注意：规定B[0] = A[1] * A[2] * ... * A[n-1]，B[n-1] = A[0] * A[1] * ... * A[n-2];）


class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int length = A.size();
        vector<int> ans(length, 1);
        if (!length) return ans;
         
        for (int i=1; i<length; i++) {
            ans[i] = ans[i-1] * A[i-1];
        }
         
        for (int i=length-2, temp=1; i>=0; i--) {
            temp *= A[i+1];
            ans[i] *= temp;
        }
         
        return ans;
    }
};
