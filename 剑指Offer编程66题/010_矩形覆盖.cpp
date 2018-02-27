class Solution {
public:
    int rectCover(int number) {
        if(number<=0) return 0;
        int front = 1, ret = 0;
        for(int i=0; i<=number; i++) {
            ret += front;
            front = ret - front;
        }
        return ret;
    }
};