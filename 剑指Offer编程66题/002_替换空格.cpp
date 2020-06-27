// 题目描述

// 请实现一个函数，将一个字符串中的空格替换成“%20”。
// 例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

class Solution {
public:
    void replaceSpace(char *str,int length) {
        if(NULL==str) return;
        char *p = str;
        int size = 0, blankNum = 0;
        while(*p!='\0') {
            if(*p==' ') blankNum++;
            size++;
            p++;
        }
        if(blankNum==0) return;
        int newSize = size + blankNum*2;
        char *end = str + newSize;
        *end-- = '\0';
        p = str + size - 1;
        while(p>=str) {
            if(*p==' ') {
                *end-- = '0';
                *end-- = '2';
                *end-- = '%';
            }
            else {
                *end-- = *p;
            }
            p--;
        }
    }
};