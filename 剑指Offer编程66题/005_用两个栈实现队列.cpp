// 题目描述

// 用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。


class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        while(!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        int ret=stack2.top();
        stack2.pop();
        while(!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
        return ret;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

/* ============================================== */

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if (stack2.empty()) {
            while(!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        
        int ret=stack2.top();
        stack2.pop();
        return ret;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
