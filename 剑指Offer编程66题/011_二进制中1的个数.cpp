class Solution {
public:
     int  NumberOf1(int n) {
         int sum=0;
         while(n) {
             sum++;
             n &= (n-1);
         }
         return sum;
     }
};