// 汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
// 对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
// 例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。
// 是不是很简单？OK，搞定它！


class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(n<0) return NULL;
        if(n==0) return str;
           
        string strTemp = str.substr(0,n);
        str.erase(0,n);
        str += strTemp;
        return str;
    }
};

// =========================

class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(n<0) return NULL;
        if(n==0 || str.length()==0) return str;
         
        if (n < str.length()) {
            ReverseWord(str, 0, n-1);
            ReverseWord(str, n, str.length()-1);
            ReverseWord(str, 0, str.length()-1);
        }
         
        return str;
    }
     
    void ReverseWord(string &str, int begin, int end){
        while(begin < end){
            swap(str[begin++],str[end--]);
        }
    }
};
