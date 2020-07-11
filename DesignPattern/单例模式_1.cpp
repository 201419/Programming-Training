// 饿汉式

#include <iostream>
using namespace std;

class Singelton { 
private:
    Singelton() {
        cout << "Singelton 构造函数执行" << endl;
    }
public:
    static Singelton *getInstance() {
        return m_psl;
    } 
    static void FreeInstance() {
        if (m_psl != NULL) {
            delete m_psl;
            m_psl = NULL;
        }
    }
private:
    static Singelton *m_psl;
};

Singelton *Singelton::m_psl = new Singelton;

void main2() {
    printf("\n");
    Singelton *p1 = Singelton::getInstance();
    Singelton *p2 = Singelton::getInstance();
    if (p1 == p2) {
        cout << "是同一个对象" << endl;
    } else {
        cout << "不是同一个对象" << endl;
    } 
    Singelton::FreeInstance();
    return ;
} 

int main() {
    main2();
    system("pause");
    return 0;
}
