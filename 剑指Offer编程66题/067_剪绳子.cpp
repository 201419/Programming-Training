// 给你一根长度为n的绳子，请把绳子剪成整数长的m段（m、n都是整数，n>1并且m>1，m<=n），
// 每段绳子的长度记为k[1],...,k[m]。请问k[1]x...xk[m]可能的最大乘积是多少？
// 例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。


class Solution {
public:
    int cutRope(int number) {
        if (number == 2) return 1;
        if (number == 3) return 2;
        int timesofthree = number / 3;
        if (number - timesofthree*3 == 1) {
            timesofthree -= 1;
        }
        int timesoftwo = (number - timesofthree*3) / 2;
        return (int)(pow(3, timesofthree)) * (int)(pow(2, timesoftwo));
    }
};
