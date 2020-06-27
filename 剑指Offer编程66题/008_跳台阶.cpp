// 题目描述

// 一只青蛙一次可以跳上1级台阶，也可以跳上2级。
// 求该青蛙跳上一个n级的台阶总共有多少种跳法。


class Solution {
public:
    int jumpFloor(int number) {
        if(number<=0) return 0;
        int front = 1, ret = 0;
        for(int i=0; i<=number; i++) {
            ret += front;
            front = ret - front;
        }
        return ret;
    }
};