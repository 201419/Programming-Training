// 在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 
// 如果没有则返回 -1（需要区分大小写）.（从0开始计数）


class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        int length = str.size();
        if(!length)  return -1;
         
        char ch[256]={0};
        for(int i = 0; i < length; i++)
            ch[str[i]]++;
        for(int i = 0; i < length; i++)
            if(ch[str[i]] == 1)
                return i;
        return 0;
    }
};

// =========================

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        int length = str.size();
        if(!length)  return -1;
         
        map<char,int> dict;
        for(int i=0; i<length; ++i) { ++dict[str[i]]; }
        string::size_type pos=0;
        for(int i=0; i<length; ++i)
            if(dict[str[i]]==1)
                return i;
        return -1;
    }
};