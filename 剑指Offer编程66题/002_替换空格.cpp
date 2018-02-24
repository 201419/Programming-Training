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