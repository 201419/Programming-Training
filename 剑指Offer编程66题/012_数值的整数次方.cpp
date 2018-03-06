class Solution {
public:
    double Power(double base, int exponent) {
        int p=((exponent<0)?-exponent:exponent);
        double ret = 1.0;
        while(p) {
            if(p&1) ret *= base;
            base *= base;
            p >>= 1;
        }
        return ((exponent>0)?ret:1/ret);
    }
};