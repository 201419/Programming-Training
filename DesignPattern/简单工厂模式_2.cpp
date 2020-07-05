#include <iostream>
#include <string>
using namespace std;


class Operation {  // 基类存放数据
public:
    double numberA, numberB;  // 两个数
    virtual double getResult() {  // 获取结果
        return 0;
    }
};

class addOperation : public Operation {  //派生类存放操作
    double getResult() {
        return numberA + numberB;
    }
};

class subOperation : public Operation {
    double getResult() {
        return numberA - numberB;
    }
};

class mulOperation : public Operation {
    double getResult() {
        return numberA*numberB;
    }
};

class divOperation : public Operation {
    double getResult() {
        return numberA / numberB;
    }
};

class operFactory { 
public:
    static Operation *createOperation(char c) {
        switch (c) { 
            case '+':
                return new addOperation;
                break;
            case '-':
                return new subOperation;
                break;
            case '*':
                return new mulOperation;
                break;
            case '/':
                return new divOperation;
                break;
        }
    }
};


int main() {
    
    Operation *oper = operFactory::createOperation('-');
    oper->numberA = 9;
    oper->numberB = 99;
    cout << oper->getResult() << endl;
    
    cin.get();
    return 0;

}
