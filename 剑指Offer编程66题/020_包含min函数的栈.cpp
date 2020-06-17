class Solution {
public:
    void push(int value) {
        sta.push(value);
        if(staMin.empty()||staMin.top()>=value) staMin.push(value);  // if语句短路判断 & 注意等号
    }
    void pop() {
        if(staMin.top()==sta.top()) staMin.pop();
        sta.pop();  // 先判断后pop，顺序不可颠倒
    }
    int top() {
        return sta.top();
    }
    int min() {
        return staMin.top();
    }

private:
    stack<int> sta;
    stack<int> staMin;
};
