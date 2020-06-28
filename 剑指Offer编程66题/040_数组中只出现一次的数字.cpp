// 一个整型数组里除了两个数字之外，其他的数字都出现了两次。
// 请写程序找出这两个只出现一次的数字。


class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int length = data.size();
        if(length <= 2) return;
          
        int one = 0;
        for(int i=0; i<length; i++) {
            one = one^data[i];
        }
         
        int flag=1;
        while (flag) {
            if (one&flag) break;
            flag=flag<<1;
        }
          
        for (int i=0; i<length; i++) {
            if(data[i]&flag) *num1=*num1^data[i];
            else *num2=*num2^data[i];
        }
    }
};