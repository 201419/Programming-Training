// 求1+2+3+...+n，
// 要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。


class Tmp {
public:
    Tmp() {++N; Sum += N;}
    static void Reset() {N = 0; Sum = 0;}
    static unsigned int GetSum() {return Sum;}
private:
    static unsigned int N ;
    static unsigned int Sum;
};
unsigned int Tmp::N = 0;
unsigned int Tmp::Sum = 0;
 
class Solution {
public:
    friend class Tmp;
    int Sum_Solution(int n) {
        Tmp::Reset();
        Tmp *a = new Tmp[n];
        delete[] a;
        a = NULL;
        return Tmp::GetSum();
    }
};

// =================

class A {
public:
    virtual unsigned int Sum (unsigned int n) {
        return 0;
    }
};
 
A* Array[2];
 
class B : public A {
public:
    virtual unsigned int Sum (unsigned int n) {
        return Array[!!n]->Sum(n-1) + n;
    }
};
 
class Solution {
public:
    int Sum_Solution(int n) {
        A a;
        B b;
        Array[0] = &a;
        Array[1] = &b;
        return Array[1]->Sum(n);
    }
};

// =================

class Solution {
public:
    typedef int (*func)(int);
     
    static int Sum_Terminator (int n) {
        return 0;
    }
     
    static int Sum_Solution(int n) {
        static func f[2] = {Sum_Terminator, Sum_Solution};
        return n + f[!!n](n-1);
    }
};

// =================

template <int n> struct Sum {
    enum Value {N = Sum<n-1>::N + n};
};
 
template <> struct Sum<1> {
    enum Value {N = 1};
};
 
class Solution {
public:
    static int Sum_Solution(int n) {
        return Sum<100>::N;
    }
};
