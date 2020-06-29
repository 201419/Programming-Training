// 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
// 例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 
// 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。


class Solution {
public:
    bool isNumeric(char* string) {
        if (NULL == string) return false;
         
        bool numeric = scanInteger(&string);
        if ('.' == *string) {
            string++;
            numeric = (scanUnsignedInteger(&string) || numeric);  // 注意 - 顺序不能换
        }
        if ('e' == *string || 'E' == *string) {
            string++;
            numeric = (numeric && scanInteger(&string));
        }
        return (numeric && '\0'==*string);  // 这句包含了非法字符的检测
    }
     
    bool scanUnsignedInteger(char** string) {
        char* before = *string;
        for (; '\0'!=**string && '0'<=**string && '9'>=**string; (*string)++);
        return (*string > before);
    }
     
    bool scanInteger(char** string) {
        if ('+'==**string || '-'==**string) (*string)++;
        return scanUnsignedInteger(string);
    }
 
};
