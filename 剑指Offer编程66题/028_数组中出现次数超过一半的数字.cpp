// 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
// 例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
// 由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。


class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int length = numbers.size();
        if (!length)  return 0;
         
        int result = 0;
        for (int i = 0, times = 0; i < length; i++) {
            if (!times) {
                result = numbers[i];
                times = 1;
            }
            else if (numbers[i] == result) {
                times++;
                if (times > (length>>1))  return result;
            }
            else {
                times--;
            }
        }
         
        int maxNum = 0;
        for (int i = 0; i < length; i++) {
            if (numbers[i] == result) {
                maxNum++;
            }
        }
        return (maxNum>(length>>1))?result:0;
    }
};