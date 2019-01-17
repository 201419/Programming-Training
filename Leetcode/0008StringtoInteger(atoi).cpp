class Solution {
public:
    int myAtoi(string str) {
        const int n = str.size();
        if (n == 0) return 0;
        
        int i = 0, sign = 1;
        while (i + 1 < n && isspace(str[i])) ++i;
        if (i == n) return 0;
        
        long result = 0;
        if (str[i] == '-' || str[i] == '+') sign = 44 - str[i++];
        
        while (i < n) {
            if (isdigit(str[i])) result = 10 * result + str[i++] - '0';
            else return result * sign;
            if (result > INT_MAX) return sign == -1 ? INT_MIN : INT_MAX;
        }
        return result * sign;
    }
};