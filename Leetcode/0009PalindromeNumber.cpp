class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x!=0 && x%10==0)) return false;
        
        int j = 1000000000;
        while (!(x / j) && (j /= 10));
        
        for (int i = 1; i < j; i *= 10, j /= 10) {
            if ((x / i) % 10 != (x / j) % 10) return false;
        }
        return true;
    }
};