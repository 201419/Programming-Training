// 题目描述

// 大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。
// n<=39


class Solution {
public:
    int Fibonacci(int n) {
        if(n==0) return 0;
        int front=1, ret=0;
        for(int i=1; i<=n; i++) {
            ret += front;
            front = ret-front;
        }
        return ret;
    }
};