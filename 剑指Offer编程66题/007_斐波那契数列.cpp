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