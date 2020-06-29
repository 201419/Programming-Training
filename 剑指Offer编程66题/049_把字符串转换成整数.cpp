// 将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 
// 数值为0或者字符串不是一个合法的数值则返回0


class Solution {
public:
    int StrToInt(string str) {
        int length = str.length();
        if(length <= 0) return 0;
         
        int sign = (str[0] == '-')?-1:1;
         
        int result = 0;
        for(int i=(str[i]=='-'||str[i]=='+')?1:0; i < length; ++i) {
            if(!(str[i]>='0' && str[i]<='9')) return 0;
            result = result*10 + (str[i]-'0');
        }
        return result*sign;
    }
};

// =====================

class Solution {
public:
    int StrToInt(string str) {
        int length = str.length();
        if(0 >= length) return 0;
         
        int i = 0, result = 0, sign = 1;
        while(str[i]==' ') {i++;}
        if (str[i] == '-') {
            sign = -1; i++;
        } else if (str[i] == '+') {
            sign = 1; i++;
        }
        for(; i < length; ++i) {  // for(; str[i]!='\0'; ++i)
            if(!(str[i]>='0' && str[i]<='9')) return 0;
            result = result*10 + (str[i]-'0');
        }
        return result*sign;
    }
};
