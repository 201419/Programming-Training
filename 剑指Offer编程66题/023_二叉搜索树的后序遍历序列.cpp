// 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
// 如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。


class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        int length = sequence.size();
        if(length==0)  return false;
         
        while(--length) {
            int i = 0;
            while(sequence[i++] < sequence[length]);
            while(sequence[i++] > sequence[length]);
            if (i < length)  return false;
        }
         
        return true;
    }
};