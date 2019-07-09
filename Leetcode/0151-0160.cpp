// https://leetcode-cn.com/problems/reverse-words-in-a-string/
// 151. 翻转字符串里的单词

// 8 ms

class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int pos = 0;

        while (true) {
            pos = s.find_first_not_of(' ', pos);    // 指向单词首字母
            if (pos == string::npos)
                break;
            st.push(s.substr(pos, s.find(' ', pos) - pos));    // 储存单词
            pos = s.find(' ', pos);    // 找到单词后的位置
        }
        string out;
        while (!st.empty()) {
            out += st.top() + " ";
            st.pop();
        }
        out.pop_back();    //删除多余空格
        return out;
    }
};

// other worse method (24ms)

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss;
        string ans="",temp;
        ss<<s;
        while(ss>>temp){
            ans=" "+temp+ans;
        }
        if(ans!="")
            ans.erase(ans.begin());
        return ans; 
    }
};

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/maximum-product-subarray/
// 152. 乘积最大子序列

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/
// 153. 寻找旋转排序数组中的最小值

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/
// 154. 寻找旋转排序数组中的最小值 II

// ---------------------------------------------------------------------------

// https://leetcode-cn.com/problems/min-stack/
// 155. 最小栈

// 44 ms
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x) {
        if(s2.empty()||s2.top()>=x)s2.push(x);
        s1.push(x);
    }
    
    void pop() {
        if(s1.top()==s2.top())s2.pop();
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
private:
    stack<int> s1,s2;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

// my code (48 ms)

class MinStack {
private:
    stack<long int> s;
    stack<long int> mins;
public:
    /** initialize your data structure here. */
    MinStack() {
        while (!s.empty()) s.pop();
        while (!mins.empty()) mins.pop();
    }
    
    void push(int x) {
        if (s.empty()) {
            s.push(x);
            mins.push(x);
        } else {
            if (mins.top() >= x) {
                s.push(x);
                mins.push(x);
            } else {
                mins.push(mins.top());
                s.push(x);
            }          
        }
    }
    
    void pop() {
        s.pop();
        mins.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mins.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

// ---------------------------------------------------------------------------



// ---------------------------------------------------------------------------



// ---------------------------------------------------------------------------



// ---------------------------------------------------------------------------



// ---------------------------------------------------------------------------


